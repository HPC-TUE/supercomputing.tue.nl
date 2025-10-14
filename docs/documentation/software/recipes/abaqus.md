---
title: Abaqus
tags: [Software, Module, Abaqus]
knowledgebase: true
---

[Abaqus by 3DS](https://www.3ds.com/products-services/simulia/products/abaqus/){:target="_blank"} is licensed software and only usable if the user is a member of the correct group.

## Using Abaqus interactive<br>(Graphical User Interface)

![Abaqus in Umbrella On Demdand](abaqus-ood.png){: style="height:100px"}
Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using Abaqus in SLURM batch jobs<br>(Command Line Interface)

### Test Abaqus

Load the module(s)

```shell
[user@umbrella]$ module purge
[user@umbrella]$ module load intel/2024a
[user@umbrella]$ module load Abaqus/2025
```

Check the fortran compiler

```shell
[user@umbrella]$ ifort --version
ifort: remark #10448: Intel(R) Fortran Compiler Classic (ifort) is now deprecated and will be discontinued late 2024. Intel recommends that customers transition now to using the LLVM-based Intel(R) Fortran Compiler (ifx) for continued Windows* and Linux* support, new language support, new language features, and optimizations. Use '-diag-disable=10448' to disable this message.
ifort (IFORT) 2021.13.0 20240602
Copyright (C) 1985-2024 Intel Corporation.  All rights reserved.
```

Check abaqus:

```shell
[user@umbrella]$ abaqus verify -user_std
------------------------------------------------------------

Abaqus Product Verification

Tue 14 Oct 2025 11:40:20 AM CEST

------------------------------------------------------------

Verify test : Abaqus/Standard with user subroutines verification

     result : PASS

------------------------------------------------------------

Verification procedure complete

Tue 14 Oct 2025 11:40:38 AM CEST

------------------------------------------------------------
```

### Abaqus SLURM sbatch jobscript example using Shared Memory

```bash
#!/bin/bash
#SBATCH --job-name=test_abaqus
#SBATCH --output=test_abaqus-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load intel/2024a
module load Abaqus/2025

cd $HOME/Jobs/Abaqus

abaqus interactive job=${SLURM_JOB_NAME} cpus=${SLURM_CPUS_PER_TASK} mp_mode=threads input=boltpipeflange_3d_solidgask.inp 
```

## Abaqus 2024 notes

### Abaqus Error: "main.f" does not contain an Abaqus user subroutine

```shell
Abaqus Error: "main.f" does not contain an Abaqus user subroutine.
```

When using a user-provided material routine (i.e. `user=main`), then the file `main.f` must contain the `umat` subroutine.  It is not enough if `main.f` includes another file that contains `umat`; it **must** be in `main.f`.

This check was not present in Abaqus 2020 and earlier.

### Python error: LookupError: unknown encoding: ISO-8859-1

```shell
...
  File "/vast.mnt/sw/rl8/zen/app/Abaqus/2024/linux_a64/tools/SMApy/python3.10/lib/python3.10/configparser.py", line 697, in read
    with open(filename, encoding=encoding) as fp:
LookupError: unknown encoding: ISO-8859-1
```

Abaqus does something with the locale while reading config files.  The locale variables propagate through SSH, through sbatch, into your jobs, and may cause the above error message.  To prevent this, add the following line to your job scripts before calling Abaqus:

```bash
export LC_ALL=POSIX
```
