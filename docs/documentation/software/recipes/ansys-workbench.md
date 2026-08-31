---
draft: true
title: ANSYS WorkBench
tags: [Software, Module]
---

[ANSYS WorkBench](https://www.ansys.com/products/ansys-workbench){:target="_blank"} lets you integrate data across engineering simulations to create more accurate models more efficiently.

## Using Application interactive<br>(Graphical User Interface)

![ANSYS WorkBench in Umbrella On Demand](ansys-workbench-ood.png){: style="height:100px"}
Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using ANSYS WorkBench in SLURM batch jobs<br>(Command Line Interface)

### Test ANSYS WorkBench

Load the modules

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load intel/2023a
[user@umbrella]$ module load ANSYS/2024R1
```
Check commandline version of Application
```shell
[user@umbrella]$ runwb2 -B
Starting Ansys Workbench...
Loading add-ins...
IronPython 2.7.0.40 on .NET 4.0.30319.42000
>>> 
```

### ANSYS WorkBench SLURM sbatch jobscript example using intel MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_ansyswb
#SBATCH --output=test_ansyswb-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --mem-per-cpu=8gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load intel/2023a
module load ANSYS/2024R1

WB_JOURNAL="journal.wbjn"

runwb2 -B -R ${WB_JOURNAL}

```
