---
title: Non commercial software modules
tags: [Software]
---

The HPC Umbrella Cluster uses the concept of Toolchains to build software, it includes specific Compilers and an MPI
implementation, in case of foss also Open/FlexiBLAS, ScaLAPACK and FFTW(MPI) are included for example.   

| Toolchain Name | Supported Versions            | Module(s)             | Remarks                               |
|----------------|-------------------------------|-----------------------|---------------------------------------|
| foss           | `2025a`, **`2024a`**, `2023a`, `2022a` | `module spider foss`  |                                       |
| gfbf           | `2025a`, **`2024a`**, `2023a`  | `module spider gfbf`  | gfbf is a subset of foss (no OpenMPI) |
| intel          | `2025a`, **`2024a`**, `2023a`, `2022a` | `module spider intel` |                                       |

??? example "module load foss/2024a"
    ```shell
    $ module list

    Currently Loaded Modules:
       1) GCCcore/13.3.0
       2) zlib/1.3.1-GCCcore-13.3.0
       3) binutils/2.42-GCCcore-13.3.0
       4) GCC/13.3.0
       5) numactl/2.0.18-GCCcore-13.3.0
       6) XZ/5.4.5-GCCcore-13.3.0
       7) libxml2/2.12.7-GCCcore-13.3.0
       8) libpciaccess/0.18.1-GCCcore-13.3.0
       9) hwloc/2.10.0-GCCcore-13.3.0
       10) OpenSSL/3
       11) libevent/2.1.12-GCCcore-13.3.0
       12) UCX/1.16.0-GCCcore-13.3.0
       13) libfabric/1.21.0-GCCcore-13.3.0
       14) PMIx/5.0.2-GCCcore-13.3.0
       15) PRRTE/3.0.5-GCCcore-13.3.0
       16) UCC/1.3.0-GCCcore-13.3.0
       17) OpenMPI/5.0.3-GCC-13.3.0
       18) OpenBLAS/0.3.27-GCC-13.3.0
       19) FlexiBLAS/3.4.4-GCC-13.3.0
       20) FFTW/3.3.10-GCC-13.3.0
       21) gompi/2024a
       22) FFTW.MPI/3.3.10-gompi-2024a
       23) ScaLAPACK/2.2.0-gompi-2024a-fb
       24) foss/2024a
    ```

??? example "module load gfbf/2024a"
    ```shell
    $ module list

    Currently Loaded Modules:
       1) GCCcore/13.3.0
       2) zlib/1.3.1-GCCcore-13.3.0
       3) binutils/2.42-GCCcore-13.3.0
       4) GCC/13.3.0
       5) OpenBLAS/0.3.27-GCC-13.3.0
       6) FlexiBLAS/3.4.4-GCC-13.3.0
       7) FFTW/3.3.10-GCC-13.3.0
       8) gfbf/2024a
    ```

??? example "module load intel/2024a"
    ```shell
    $ module list

    Currently Loaded Modules:
       1) GCCcore/13.3.0
       2) zlib/1.3.1-GCCcore-13.3.0
       3) binutils/2.42-GCCcore-13.3.0
       4) intel-compilers/2024.2.0
       5) numactl/2.0.18-GCCcore-13.3.0
       6) UCX/1.16.0-GCCcore-13.3.0
       7) impi/2021.13.0-intel-compilers-2024.2.0
       8) imkl/2024.2.0
       9) iimpi/2024a
       10) imkl-FFTW/2024.2.0-iimpi-2024a
       11) intel/2024a
    ```

Using the toolchain(s) the following software is avaiable. When the module is loaded the toolchain it depends on is automatically loaded.

| Name                                        | Supported Versions                                                                   | Module(s)           | https://hpc.tue.nl          |
|---------------------------------------------|--------------------------------------------------------------------------------------|---------------------|-----------------------------|
| ADIOS2                                      | 2.10.2-gompi-2024a                                                                   | `ADIOS2`            |                             |
| Amber                                       | 24.0-foss-2022a-AmberTools-24.0-CUDA-11.7.0<br>24.0-foss-2024a-AmberTools-24.0       | `Amber`             |                             |
| Blender                                     | 4.5.3-linux-x86_64-CUDA-12.8.0                                                       | `Blender`           | Yes                         |
| [CP2K](recipes/cp2k.md)                     | 2023.1-foss-2023a                                                                    | `CP2K`              |                             |
| dask                                        | 2024.9.1-gfbf-2024a                                                                  | `dask`              |                             |
| git                                         | 2.50.0-GCCcore-14.2.0                                                                | `git`               |                             |
| git-lfs                                     | 3.6.1                                                                                | `git-lfs`           |                             |
| GROMACS                                     | 2023.3-foss-2023a                                                                    | `GROMACS`           |                             |
| Julia                                       | 1.11.7                                                                               | `Julia`             | Yes via Pluto               |
| [LAMMPS](recipes/lammps.md)                 | 29Aug2024_update2-foss-2023a-kokkos                                                  | `LAMMPS`            |                             |
| MCL                                         | 22.282-GCCcore-14.2.0                                                                | `MCL`               |                             |
| [NetLogo](recipes/netlogo.md)               | 6.4.0-64                                                                             | `NetLogo`           | Yes                         |
| OpenFOAM (ESI)                              | v2206-foss-2022a<br>v2312-foss-2023a<br>v2406-foss-2023a                             | `OpenFOAM`          |                             |
| OpenFOAM (Foundation)                       | 10-foss-2023a<br>11-foss-2023a<br>12-foss-2023a                                      | `OpenFOAM`          |                             |
| OpenModelica                                | 1.22.0-foss-2022a                                                                    | `OpenModelica`      |                             |
| OpenMM                                      | 8.0.0-foss-2023a-CUDA-12.1.1<br>8.0.0-foss-2023a                                     | `OpenMM`            |                             |
| OpenSceneGraph                              | 3.6.5-foss-2022a                                                                     | `OpenSceneGraph`    | Yes via Interactive Desktop |
| ORCA                                        | 5.0.4-gompi-2023a<br>6.0.1-gompi-2023a                                               | `ORCA`              |                             |
| ParaView                                    | 5.12.1-foss-2023a                                                                    | `ParaView`          | Yes                         |
| QCG-PilotJob                                | 0.14.1-gfbf-2024a                                                                    | `QCG-PilotJob`      |                             |
| QuantumESPRESSO                             | 7.3.1-foss-2023a<br>7.4-foss-2024a                                                   | `QuantumESPRESSO`   |                             |
| [R](recipes/r.md)                           | 4.4.2-gfbf-2024a<br>4.5.0-gfbf-2024a                                                 | `R`                 | Yes via Rstudio             |
| Rstudio                                     | 2023.12.1+402-gfbf-2023a-Java-11-R-4.4.1                                             | `RStudio`           | Yes                         |
| Siesta                                      | 5.2.2-foss-2024a                                                                     | `Siesta`            |                             |
| [SlurmViewer](../steps/jobs/slurmviewer.md) | 1.0.4-GCCcore-13.3.0                                                                 | `slurm-SlurmViewer` |                             |
| [Spark](recipes/spark.md)                   | 3.5.0-foss-2023a<br>3.5.1-foss-2023a-Java-17                                         | `Spark`             |                             |
| VSCode                                      | 1.98.2<br>1.99.3                                                                     | `VSCode`            | Yes via CodeServer          |

*[foss]: Free and Open Source Software
*[gfbf]: Gcc + FlexiBas + Fftw
