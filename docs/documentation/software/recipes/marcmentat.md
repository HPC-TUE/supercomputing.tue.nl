---
title: Marc Mentat
tags: [Software, Module]
---

[Marc Mentat by Hexagon](https://hexagon.com/products/marc){:target="_blank"} Marc is a general purpose finite element program capable of solving structural and thermal problems. Marc input is graphically generated using the program Mentat.

## Using Marc Mentat interactive<br>(Graphical User Interface)

![Marc Mentat in Umbrella On Demdand](marcmentat-ood.png){: style="height:100px"}
Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using Marc Mentat in SLURM batch jobs<br>(Command Line Interface)

### Test Marc

??? example "Test Marc Mentat"
    Load the module
    
    ```shell 
    [user@umbrella]$ module purge
    [user@umbrella]$ module load MarcMentat/2025.1-intel-2024a
    ```
    
    Check execution on empty data file (test.dat)
    
    ```shell
    [user@umbrella]$ touch test.dat
    [user@umbrella]$ run_marc -jid test
    
    Program name         : marc
    Marc shared lib      : 
    Version type         : i8
    .....
    .....
    running the job in the background, see test.log
    
     
    Final run stream value
     RUNJOB= /sw/rl8/zen/app/MarcMentat/marc2024.1/bin/linux64i8/marc -jid test -dirjid /home/20224765/. -maxnum 1000000     -dirjob /home/20224765 -ml 128474 -ci yes -cr yes
    ```
    
    test.log file has more info
    
    ```shell
    [user@umbrella]$ cat test.log
    .....
    Tue Nov 25 17:20:21 CET 2025
 Marc test begins execution

     (c) COPYRIGHT 2025 Hexagon Manufacturing Intelligence, Inc., all rights reserved


 Requested number of element threads                     =    1
 Requested number of solver threads                      =    1


 VERSION: Marc 2025.1, build 271e0caa5 (2025-07-27)



     Date: Tue Nov 25 17:20:22 2025

                              Marc execution begins
 Date:          Tue Nov 25 17:20:22 2025
 MSC Id:        cc96e5f26997 (ethernet) (Linux)
 Hostname:      tue-login002.cluster (user 20224765, display /dev/tty)
 License files: 27500@marcmentat.lic.tue.nl
 CEID:          56906B84-A5BDA279
 User:          20224765
 Display:       /dev/tty
 LAPI Version:  LAPI 23.1.2 (CL b668b185) (FLEXlm 11.19.6.3)
Acquired 20 licenses for Group MSCONE (Marc) from license server on host marcmentat.lic.tue.nl


             general memory initially set to =        23 MByte

             maximum available memory set to =    128499 MByte

               *** error -  no element types chosen and no substructure input
Returned 20 licenses for Group MSCONE (Marc)

    ......
    ```
    
???example "Test MarcMentat and Fortran compiler"
    
    Load the module
    
    ```shell 
    [user@umbrella]$ module purge
    [user@umbrella]$ module load MarcMentat/2024.1-intel-2023a
    ```
    Check execution on empty data file (test.dat) and fortran code (main.f)
    
    ```shell
    [user@umbrella]$ touch test.dat
    [user@umbrella]$ 
    [user@umbrella]$ run_marc -jid test -u main
    ```
    




### Marc SLURM sbatch jobscript example using Shared Memory

``` text
#!/bin/bash
#SBATCH --job-name=test_marc
#SBATCH --output=test_marc-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load MarcMentat/2024.1-intel-2023a

# The input file input.dat can be referenced without the .dat extension

run_marc -j input -v no -b no -nte ${SLURM_CPUS_PER_TASK} -nts ${SLURM_CPUS_PER_TASK}
```

### Marc SLURM sbatch jobscript example using specific Fortran code

``` text
#!/bin/bash
#SBATCH --job-name=test_marc
#SBATCH --output=test_marc-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load MarcMentat/2024.1-intel-2023a

# The input file input.dat can be referenced without the .dat extension
# The Fortran code main.f can be referenced without the .f extension

run_marc -j input -u main -v no -b no -nte ${SLURM_CPUS_PER_TASK} -nts ${SLURM_CPUS_PER_TASK}

```

