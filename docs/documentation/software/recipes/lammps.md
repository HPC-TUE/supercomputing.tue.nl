---
title: LAMMPS
tags: [Software, Module]
---

[LAMMPS](https://www.lammps.org/){:target="_blank"} (Molecular Dynamics Simulator) is a classical molecular dynamics code with a focus on materials modeling. It's an acronym for Large-scale Atomic/Molecular Massively Parallel Simulator.

## Using LAMMPS in SLURM batch jobs<br>(Command Line Interface)

### Test LAMMPS

Load the modules

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load LAMMPS/29Aug2024_update2-foss-2023a-kokkos
```

Check commandline version of LAMMPS

```shell
[user@umbrella]$ lmp < /dev/null
LAMMPS (2 Aug 2023 - Update 2)
OMP_NUM_THREADS environment is not set. Defaulting to 1 thread. (src/comm.cpp:98)
  using 1 OpenMP thread(s) per MPI task
Total wall time: 0:00:00
```

### LAMMPS SLURM sbatch jobscript example using Shared Memory

```slurm
#!/bin/bash
#SBATCH --job-name=test_lammps
#SBATCH --output=test_lammps-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load LAMMPS/29Aug2024_update2-foss-2023a-kokkos

export OMP_NUM_THREADS=${SLURM_CPUS_PER_TASK}

lmp < in.friction
```

### LAMMPS SLURM sbatch jobscript example using MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_lammps
#SBATCH --output=test_lammps-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load LAMMPS/29Aug2024_update2-foss-2023a-kokkos

mpirun lmp < in.friction
```

### LAMMPS SLURM sbatch jobscript example using Shared Memory and MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_lammps
#SBATCH --output=test_lammps-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=2
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load LAMMPS/29Aug2024_update2-foss-2023a-kokkos

export OMP_NUM_THREADS=${SLURM_CPUS_PER_TASK}

mpirun lmp < in.friction
```
