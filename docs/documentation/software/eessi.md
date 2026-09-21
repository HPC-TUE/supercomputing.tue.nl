---
title: EESSI Software Modules
tags: [Software]
---

![EESSI logo](EESSI-logo.png){ style="height:30px"}

EESSI, short for the European Environment for Scientific Software Installations, is a collaborated project between different European partners in HPC community to build a common stack of scientific software installations for HPC systems and beyond. Through the EESSI project, a shared stack of scientific software installations is distributed via CVMFS.

The official website of EESSI can be found [here](https://eessi.io/). To get an overview of all the available software in EESSI per specific CPU target, please check [EESSI available software](https://www.eessi.io/docs/available_software/).

## Using EESSI Software Modules

Like the Umbrella software modules, the EESSI software modules are available via [gateway modules](https://supercomputing.tue.nl/documentation/steps/software/#gateway-environment-modules). EESSI will "look" at the current hardware it is loaded on and activates the modules optimized for that hardware.

```shell
module load EESSI/2025.06
Module for EESSI/2025.06 loaded successfully
```

??? example "Usage Example (OpenFOAM)"

    ??? shell "module avail"

        ```shell
        $ module avail
         ...
         -------------------------------------------------------- /cvmfs/software.eessi.io/versions/2025.06/software/linux/x86_64/amd/zen4/modules/all --------------------------------------------------------
         2decomp-fft/2.0.4-foss-2025b                          OpenJPEG/2.5.3-GCCcore-14.3.0                   (D)    hatch-jupyter-builder/0.9.1-GCCcore-13.3.0
         ABINIT/10.4.7-foss-2025b                              OpenMM/8.5.2-foss-2025b                                hatch-jupyter-builder/0.9.1-GCCcore-14.2.0
         AOCL-BLAS/5.0-GCC-14.2.0                              OpenMPI/5.0.3-GCC-13.3.0                               hatch-jupyter-builder/0.9.1-GCCcore-14.3.0           (D)
         AOCL-BLAS/5.1-GCC-14.3.0                              OpenMPI/5.0.7-GCC-14.2.0                               hatchling/1.24.2-GCCcore-13.3.0
         AOCL-BLAS/5.1-llvm-compilers-20.1.8         (D)       OpenMPI/5.0.8-GCC-14.3.0                               hatchling/1.27.0-GCCcore-14.2.0
         ASAP3/3.13.10-foss-2025b                              OpenMPI/5.0.8-llvm-compilers-20.1.8             (D)    hatchling/1.27.0-GCCcore-14.3.0                      (D)
         ASAP3/3.13.11-foss-2025b                    (D)       OpenPGM/5.2.122-GCCcore-13.3.0                         huggingface-hub/0.34.4-GCCcore-13.3.0
         ASE/3.25.0-gfbf-2025a                                 OpenPGM/5.2.122-GCCcore-14.2.0                         huggingface-hub/1.2.4-GCCcore-14.2.0                 (D)
         ASE/3.26.0-gfbf-2025a                                 OpenPGM/5.2.122-GCCcore-14.3.0                  (D)    hwdata/0.403-GCCcore-14.3.0
         ASE/3.26.0-gfbf-2025b                       (D)       OpenSSL/3                                              hwloc/2.10.0-GCCcore-13.3.0
         ATK/2.38.0-GCCcore-13.3.0                             Openbox/3.6.1-GCCcore-13.3.0                           hwloc/2.11.2-GCCcore-14.2.0
         ATK/2.38.0-GCCcore-14.3.0                   (D)       Osi/0.108.11-GCC-13.3.0                                hwloc/2.12.1-GCCcore-14.3.0                          (D)
         AUGUSTUS/3.5.0-foss-2025b                             Osi/0.108.11-GCC-14.3.0                         (D)    hypothesis/6.103.1-GCCcore-13.3.0
         Abseil/20240722.0-GCCcore-13.3.0                      PAPI/7.2.0-GCCcore-14.2.0                              hypothesis/6.133.2-GCCcore-14.2.0
         Abseil/20250512.1-GCCcore-14.3.0            (D)       PAPI/7.2.0-GCCcore-14.3.0                       (D)    hypothesis/6.136.6-GCCcore-14.3.0                    (D)
         ...
        ```

    ??? shell "module spider openfoam"

        ```shell
        $ ml spider OpenFOAM

        ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
          OpenFOAM:
        ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            Description:
              OpenFOAM is a free, open source CFD software package. OpenFOAM has an extensive range of features to solve anything from complex fluid flows involving chemical reactions, turbulence and
              heat transfer, to solid dynamics and electromagnetics.
        
             Versions:
                OpenFOAM/v2506-foss-2025a
                OpenFOAM/13-foss-2025a
        
        ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
          For detailed information about a specific "OpenFOAM" package (including how to load the modules) use the module's full name.
          Note that names that have a trailing (E) are extensions provided by other modules.
          For example:
        
             $ module spider OpenFOAM/13-foss-2025a
        ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        ```

    ??? shell "module load OpenFOAM/v2506-foss-2025a"

        ```shell
        $ foamVersion
        -bash: foamVersion: command not found

        $ module load EESSI/2025.06
        $ module load OpenFOAM/v2506-foss-2025a
        $ module list
        Currently Loaded Modules:
         1) EESSI/2025.06                       32) KaHIP/3.19-gompi-2025a                     63) libglvnd/1.7.0-GCCcore-14.2.0           94) libogg/1.3.6-GCCcore-14.2.0
         2) GCCcore/14.2.0                      33) CGAL/6.0.1-GCCcore-14.2.0                  64) Z3/4.13.4-GCCcore-14.2.0                95) libvorbis/1.3.7-GCCcore-14.2.0
         3) GCC/14.2.0                          34) GMP/6.3.0-GCCcore-14.2.0                   65) LLVM/20.1.7-GCCcore-14.2.0              96) libopus/1.5.2-GCCcore-14.2.0
         4) numactl/2.0.19-GCCcore-14.2.0       35) MPFR/4.2.2-GCCcore-14.2.0                  66) Wayland/1.23.92-GCCcore-14.2.0          97) FriBidi/1.0.16-GCCcore-14.2.0
         5) libxml2/2.13.4-GCCcore-14.2.0       36) gzip/1.13-GCCcore-14.2.0                   67) Mesa/25.1.3-GCCcore-14.2.0              98) SDL2/2.32.8-GCCcore-14.2.0
         6) libpciaccess/0.18.1-GCCcore-14.2.0  37) lz4/1.10.0-GCCcore-14.2.0                  68) double-conversion/3.3.1-GCCcore-14.2.0  99) FFmpeg/7.1.1-GCCcore-14.2.0
         7) hwloc/2.11.2-GCCcore-14.2.0         38) zstd/1.5.6-GCCcore-14.2.0                  69) PCRE2/10.45-GCCcore-14.2.0             100) libGLU/9.0.3-GCCcore-14.2.0
         8) OpenSSL/3                           39) ICU/76.1-GCCcore-14.2.0                    70) GLib/2.85.1-GCCcore-14.2.0             101) NSPR/4.36-GCCcore-14.2.0
         9) libevent/2.1.12-GCCcore-14.2.0      40) Boost/1.88.0-GCC-14.2.0                    71) NASM/2.16.03-GCCcore-14.2.0            102) NSS/3.113-GCCcore-14.2.0
        10) UCX/1.18.0-GCCcore-14.2.0           41) gfbf/2025a                                 72) libjpeg-turbo/3.1.0-GCCcore-14.2.0     103) snappy/1.2.2-GCCcore-14.2.0
        11) libfabric/2.0.0-GCCcore-14.2.0      42) cffi/1.17.1-GCCcore-14.2.0                 73) jbigkit/2.1-GCCcore-14.2.0             104) nodejs/22.16.0-GCCcore-14.2.0
        12) PMIx/5.0.6-GCCcore-14.2.0           43) cryptography/44.0.2-GCCcore-14.2.0         74) libdeflate/1.24-GCCcore-14.2.0         105) Qt6/6.9.3-GCCcore-14.2.0
        13) PRRTE/3.0.8-GCCcore-14.2.0          44) virtualenv/20.29.2-GCCcore-14.2.0          75) LibTIFF/4.7.0-GCCcore-14.2.0           106) Tk/8.6.16-GCCcore-14.2.0
        14) UCC/1.3.0-GCCcore-14.2.0            45) Python-bundle-PyPI/2025.04-GCCcore-14.2.0  76) giflib/5.2.2-GCCcore-14.2.0            107) Tkinter/3.13.1-GCCcore-14.2.0
        15) OpenMPI/5.0.7-GCC-14.2.0            46) SciPy-bundle/2025.06-gfbf-2025a            77) libwebp/1.5.0-GCCcore-14.2.0           108) OpenJPEG/2.5.3-GCCcore-14.2.0
        16) OpenBLAS/0.3.29-GCC-14.2.0          47) Szip/2.1.1-GCCcore-14.2.0                  78) libde265/1.0.16-GCCcore-14.2.0         109) LittleCMS/2.17-GCCcore-14.2.0
        17) FlexiBLAS/3.4.5-GCC-14.2.0          48) HDF5/1.14.6-gompi-2025a                    79) x265/4.1-GCCcore-14.2.0                110) Pillow/11.3.0-GCCcore-14.2.0
        18) FFTW/3.3.10-GCC-14.2.0              49) libidn2/2.3.7-GCCcore-14.2.0               80) Gdk-Pixbuf/2.42.12-GCCcore-14.2.0      111) Qhull/2020.2-GCCcore-14.2.0
        19) gompi/2025a                         50) libiconv/1.18-GCCcore-14.2.0               81) libheif/1.19.8-GCCcore-14.2.0          112) fonttools/4.58.4-GCCcore-14.2.0
        20) FFTW.MPI/3.3.10-gompi-2025a         51) libunistring/1.3-GCCcore-14.2.0            82) JasPer/4.2.5-GCCcore-14.2.0            113) matplotlib/3.10.3-gfbf-2025a
        21) ScaLAPACK/2.2.2-gompi-2025a-fb      52) libpsl/0.21.5-GCCcore-14.2.0               83) pixman/0.46.2-GCCcore-14.2.0           114) libxslt/1.1.42-GCCcore-14.2.0
        22) foss/2025a                          53) cURL/8.11.1-GCCcore-14.2.0                 84) cairo/1.18.4-GCCcore-14.2.0            115) OSPRay/2.12.0
        23) METIS/5.1.0-GCCcore-14.2.0          54) netCDF/4.9.3-gompi-2025a                   85) HarfBuzz/11.2.1-GCCcore-14.2.0         116) ParaView/6.0.1-foss-2025a
        24) SCOTCH/7.0.8-gompi-2025a            55) expat/2.6.4-GCCcore-14.2.0                 86) graphite2/1.3.14-GCCcore-14.2.0        117) libgd/2.3.3-GCCcore-14.2.0
        25) Tcl/8.6.16-GCCcore-14.2.0           56) libpng/1.6.48-GCCcore-14.2.0               87) assimp/6.0.2-GCCcore-14.2.0            118) Pango/1.56.3-GCCcore-14.2.0
        26) SQLite/3.47.2-GCCcore-14.2.0        57) Brotli/1.1.0-GCCcore-14.2.0                88) x264/20250619-GCCcore-14.2.0           119) libcerf/3.0-GCCcore-14.2.0
        27) libffi/3.4.5-GCCcore-14.2.0         58) freetype/2.13.3-GCCcore-14.2.0             89) LAME/3.100-GCCcore-14.2.0              120) Lua/5.4.8-GCCcore-14.2.0
        28) Python/3.13.1-GCCcore-14.2.0        59) fontconfig/2.16.2-GCCcore-14.2.0           90) dav1d/1.5.2-GCCcore-14.2.0             121) gnuplot/6.0.3-GCCcore-14.2.0
        29) GKlib-METIS/5.1.1-GCC-14.2.0        60) xorg-macros/1.20.2-GCCcore-14.2.0          91) SVT-AV1/3.1.2-GCCcore-14.2.0           122) OpenFOAM/v2506-foss-2025a
        30) libunwind/1.8.1-GCCcore-14.2.0      61) X11/20250521-GCCcore-14.2.0                92) libaom/3.10.0-GCCcore-14.2.0
        31) gperftools/2.16-GCCcore-14.2.0      62) libdrm/2.4.125-GCCcore-14.2.0              93) libvpx/1.15.2-GCCcore-14.2.0

        $ source $FOAM_BASH
        $ foamVersion
        OpenFOAM-v2506
        ```

    ??? shell "module purge"

        ```shell
        $ module purge
        $ module list
        No modules loaded
        $ foamVersion
        OpenFOAM-
        ```
