---
title: Mathematica
tags: [Software, Module]
---


[Wolfram Mathematica](https://www.wolfram.com/mathematica/){:target=_blank} a is a software system with built-in libraries for several areas of technical computing that allow machine learning, statistics, symbolic computation, data manipulation, network analysis, time series analysis, NLP, optimization, plotting functions and various types of data, implementation of algorithms, creation of user interfaces, and interfacing with programs written in other programming languages.


## Using Mathematica interactive<br>(Graphical User Interface)

![Mathematica in Umbrella On Demdand](mathematica-ood.png){: align="text-align:center" style="height:100px"}
Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using Mathematica in SLURM batch jobs<br>(Command Line Interface)

### Test Mathematica

Load the module(s)
``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module Mathematica/14.3.0
```
Test the Mathematica command line version
``` shell
[user@umbrella]$ wolfram -run 'Quit[];'
Wolfram 1432.0 Kernel for Linux x86 (64-bit)
Copyright 1988-2025 Wolfram Research, Inc.
```

### Mathematica SLURM sbatch jobscript example using 1 CPU

```slurm
#!/bin/bash
#SBATCH --job-name=test_mathematica
#SBATCH --output=test.mathematica-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00
module purge
module load Mathematica/14.3.0
wolfram -script sample-simple.wl
```

??? example "sample-simple.wl"
  
    ```mathematica

    A = Sum[i, {i,1,100}]
    B = Mean[{25, 36, 22, 16, 8, 42}]
    Answer = A + B
    Quit[];

    ```


### Mathematica SLURM sbatch jobscript example using Multiple CPUs

Mathematica can be run in parallel using the built in Parallel commands or by utilizing the parallel API. Parallel Mathematica jobs are limited to one node, but can utilize all CPU cores on the node. Here we request and use eight cores:

```slurm
#!/bin/bash
#SBATCH --job-name=test_mathematica
#SBATCH --output=test.mathematica-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00
module purge
module load Mathematica/14.3.0
worlfram -script sample-parallel.wl
```
??? example "sample-parallel.wl"
  
    ```mathematica

    (*Prints the machine name that each kernel is running on*)
    Print[ParallelEvaluate[$MachineName]];

    (*Prints all Mersenne Prime numbers less than 2000*)
    Print[Parallelize[Select[Range[2000],PrimeQ[2^#-1]&]]];

    ```


## To Be Tested (Work In Progress)

In a Slurm batch script is all you need. However, these scripts will
only use a single core. To fully leverage the parallel character of the
HPC cluster, one can/should use (remote) subkernels. This can be done by
embedding your script into the following template.

??? example "hpc.wl"

    ```mathematica
    
    (*
     * This script must be invoked by Slurm on a compute node, and will spawn remote
     * kernels on the nodes assigned to the job. To this end some environment
     * variables set by Slurm are read and parsed. It is assumed that compute nodes
     * can communicate freely with one another (no passwords, firewalls).
     *
     *)

    (*DEBUG*) (*turn on WSTP link debugging*)
    (*DEBUG*) Needs["Parallel`Debug`"];
    (*DEBUG*) SetOptions[$Parallel,Tracers->{MathLink}];


    Needs["SubKernels`RemoteKernels`"];


    (* get hostnames of nodes to run on *)
    nodes = StringSplit[
        RunProcess[
          {"scontrol", "show", "hostnames", Environment["SLURM_JOB_NODELIST"]},
          "StandardOutput"
        ],
        "\n"
      ];

    (* determine number of CPUs per node - this is the number of kernels *)
    cpusRaw = StringSplit[Environment["SLURM_JOB_CPUS_PER_NODE"], ","];
    cpus = {};
    For[i = 1, i <= Length[cpusRaw], i++,
      cpu = cpusRaw[[/i|i]];
      matches = StringCases[cpu, RegularExpression["^(\\d+)(?:\\(x(\\d+)\\))?$"] -> {"$1", "$2"}];
      repeat = ToExpression[matches[[/1|1]][[/2|2]]];
      If[NumericQ[repeat], Null, repeat = 1];
      For[j = 0, j < repeat, j++, AppendTo[cpus, ToExpression[matches[[/1|1]][[/1|1]]]]]
    ];
    cpus[[/Position[nodes,_Environment["SLURMD_NODENAME"|Position[nodes, Environment["SLURMD_NODENAME"]][[/1|1]]]]--;

    (*DEBUG*) (*print job resources, and Wolfram Kernel path, to screen*)
    (*DEBUG*) Print["nodes = ", nodes];
    (*DEBUG*) Print["jobs per node = ", cpus];

    (* start remote kernels and connect them to the controlling Wolfram Kernel *)
    SetOptions[$Output, FormatType->OutputForm];
    For[i = 1, i <= Length[nodes], i++,
      If[cpus[[/i|i]] > 0, LaunchKernels[RemoteMachine[
        nodes[[/i|i]],
        "ssh -x -f -l `3` `1` \"module load mathematica && wolfram -wstp -linkmode Connect `4` -linkname '`2`' -subkernel -noinit\"",
        cpus[[/i|i]]
      ]]]
    ];

    (*DEBUG*) (*check that kernels were launched correctly*)
    (*DEBUG*) Print["Kernels = ", Kernels[]];
    (*DEBUG*) Print["Kernel count = ", $KernelCount];

    (* ===== Your script, leveraging HPC, starts here ===== *)

    (* For example: *)
    result = ParallelTable[Prime[i], {i, 11111115}];
    Save["result.txt", result];

    (* ===== end of your HPC script ===== *)

    CloseKernels[];
    Quit[];
    ```

You can call the above script, after you have embedded your script into
it, using the following Slurm batch script.

??? example "math.cmd"

    ```shell
    #!/usr/bin/bash
    #SBATCH --nodes=3
    #SBATCH --ntasks=3
    #SBATCH --cpus-per-task=2
    #SBATCH --partition=tue.default.q
    #SBATCH --output=slurm-%j.out
    #SBATCH --time=00:01:00

    module load Mathematica/14.3.0
    wolfram -script hpc.wl
    ```

Of course, you can modify the number of nodes and CPUs in the parameters
of the Slurm batch script to suit your needs. You should also modify the [partition](../../steps/jobs/index.md)
and time limit. Finally, just `sbatch math.cmd`.
