---
title: CP2K
tags: [Software, Module]
---

[CP2K](https://www.cp2k.org/) is a quantum chemistry and solid state physics software package that can perform atomistic simulations of solid state, liquid, molecular, periodic, material, crystal, and biological systems.

## Using CP2K in SLURM batch jobs<br>(Command Line Interface)

### Test CP2K

Load the modules

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load CP2K/2023.1-foss-2023a
```
Check commandline version of Application
```shell
[user@umbrella]$ cp2k.popt --version
 CP2K version 2023.1
 Source code revision git:b888bd8
 cp2kflags: omp libint fftw3 libxc parallel scalapack xsmm plumed2 libvori libbqb
 ......
```
[user@umbrella]$ cp2k.psmp --version
 CP2K version 2023.1
 Source code revision git:b888bd8
 cp2kflags: omp libint fftw3 libxc parallel scalapack xsmm plumed2 libvori libbqb
 ......

### CP2K SLURM sbatch jobscript example using Shared Memory

```slurm
#!/bin/bash
#SBATCH --job-name=test_cp2k
#SBATCH --output=test_cp2k-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load CP2K/2023.1-foss-2023a
cp2k.psmp example.inp
```

### CP2K SLURM sbatch jobscript example using MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_cp2k
#SBATCH --output=test_cp2k-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load CP2K/2023.1-foss-2023a
mpirun  -n ${SLURM_NTASKS} cp2k.popt example.inp
```

### CP2K SLURM sbatch jobscript example using Shared Memory and MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_cp2k
#SBATCH --output=test_cp2k-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load CP2K/2023.1-foss-2023a
mpirun -n ${SLURM_NTASKS} cp2k.psmp example.inp
```
