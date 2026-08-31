---
title: StarCCM+
tags: [Software, Module]
---

[StarCCM+](https://plm.sw.siemens.com/en-US/simcenter/fluids-thermal-simulation/star-ccm/starccm){:target="_blank"} is a multiphysics computational fluid dynamics (CFD) simulation software that models the complexity products operating under real-world conditions.

![StarCCM+ in Umbrella On Demdand](starccm-ood.png){: align=right style="height:100px"}

## Using StarCCM+ interactive<br>(Graphical User Interface)

Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using StarCCM+ in SLURM batch jobs<br>(Command Line Interface)

### Test StarCCM+

Load the modules

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load StarCCM+/2024.0001
```

Check commandline version of StarCCM+

```shell
[user@umbrella]$ starccm+ --version
Simcenter STAR-CCM+ 2402.0001 Build 19.02.013 (linux-x86_64-2.28/gnu11.2)
```

Test mpi functionality of StarCCM+

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load gompi/2023a
[user@umbrella]$ module load StarCCM+/2024.0001
[user@umbrella]$ starccm+ -np 2 -mpi openmpi -mpitest
Starting parallel server
MPI Distribution : Open MPI-4.1.5
Host 0 -- tue-login001.icts.tue.nl -- Ranks 0-1
Process rank 0 tue-login001.icts.tue.nl 1675194
Total number of processes : 2

Simcenter STAR-CCM+ 2402.0001 Build 19.02.013 (linux-x86_64-2.28/gnu11.2)
.......
```

### StarCCM+ SLURM sbatch jobscript example using 1 CPU

```slurm
#!/bin/bash
#SBATCH --job-name=test_starccm
#SBATCH --output=test_starccm-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load StarCCM+/2024.0001

starccm+ -batch MeshAndSave.java example.sim
```

### StarCCM+ SLURM sbatch jobscript example using (Open)MPI

```slurm
#!/bin/bash
#SBATCH --job-name=test_starccm
#SBATCH --output=test_starccm-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=8
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load gompi/2023a
module load StarCCM+/2024.0001

starccm+ -np ${SLURM_NTASKS} -mpi openmpi -batch MeshAndSave.java example.sim
```
