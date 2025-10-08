---
tags: [Software]
---
# Environment Modules

# --8<-- [start:lmod]

Environment Modules provide a convenient way to dynamically change the users’ environment through modulefiles. With this module system, different versions of software, like compilers or special math libraries, are easily accessable and usable. Different modules are available, varying from GCC  or Intel Compilers, Python versions and software compiled from source and ready to use. Environment modules can activate commercial software and thier licenses.

The most common used module commands are:

| Command               | Description                           | Alias    |
| --------------------- | ------------------------------------- |----------|
| `module avail`        | Lists available (loadable) modules    | `ml av`  |
| `module list`         | Lists loaded modules                  | `ml`  |
| `module load MOD/X`   | Loads module MOD/X (and dependencies) | `ml MOD/X` |
| `module switch MOD/Y` | Switch to version Y of MOD (and deps) | `ml sw MOD/Y` |
| `module purge`        | unload all modules                    | `ml purge` |

!!! note "Modules are case insensitive"
    The command `module avail` finds and lists modules case insensitive but `module load` is **case sensitive**.

??? example "Usage Example (Python)"

    ??? shell "module avail"

        ```shell
        $ module avail
         ...
         Cantera/2.6.0-foss-2022a                                          PycURL/7.45.2-GCCcore-12.3.0                                   libepoxy/1.5.10-GCCcore-11.3.0
         Cantera/3.0.0-foss-2023a                                (D)       Python-bundle-PyPI/2023.06-GCCcore-12.3.0                      libepoxy/1.5.10-GCCcore-12.3.0
         CasADI/3.6.7-gfbf-2023a                                           Python-bundle-PyPI/2024.06-GCCcore-13.3.0                      libepoxy/1.5.10-GCCcore-13.3.0              (D)
         CasADI/3.6.7-linux64-matlab                                       Python-bundle-PyPI/2025.04-GCCcore-14.2.0               (D)    libevent/2.1.12-GCCcore-11.3.0
         CasADI/3.7.0-gfbf-2023a                                           Python/2.7.18-GCCcore-11.3.0-bare                              libevent/2.1.12-GCCcore-12.3.0
         CasADI/3.7.0-gfbf-2024a                                           Python/3.8.20-GCCcore-11.3.0                                   libevent/2.1.12-GCCcore-13.3.0
         CasADI/3.7.0-linux64-matlab                             (D)       Python/3.10.4-GCCcore-11.3.0-bare                              libevent/2.1.12-GCCcore-14.2.0              (D)
         CasADi/3.7.2-foss-2024a                                           Python/3.10.4-GCCcore-11.3.0                                   libfabric/1.15.1-GCCcore-11.3.0
         CasADi/3.7.2-linux64-matlab                             (D)       Python/3.10.13-GCCcore-11.3.0                                  libfabric/1.18.0-GCCcore-12.3.0
         Catch2/2.13.9-GCCcore-12.3.0                                      Python/3.11.3-GCCcore-12.3.0                                   libfabric/1.21.0-GCCcore-13.3.0
         Catch2/2.13.10-GCCcore-13.3.0                                     Python/3.12.3-GCCcore-13.3.0                                   libfabric/2.0.0-GCCcore-14.2.0              (D)
         Catch2/2.13.10-GCCcore-14.2.0                           (D)       Python/3.13.1-GCCcore-14.2.0                            (D)    libfdf/0.5.1-GCC-13.3.0
         Cbc/2.10.12-foss-2024a                                            QCG-PilotJob/0.13.1-foss-2022a                                 libffi/3.4.2-GCCcore-11.3.0
         ...
        ```

    ??? shell "module spider Python"

        ```shell
        $ ml spider Python
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
          Python:
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            Description:
              Python is a programming language that lets you work more quickly and integrate your systems more effectively.

             Versions:
                Python/2.7.15-foss-2018b
                Python/2.7.15-GCCcore-7.3.0-bare
                Python/2.7.16-GCCcore-8.3.0
                Python/2.7.18-GCCcore-9.3.0
                Python/2.7.18-GCCcore-10.3.0-bare
                Python/2.7.18-GCCcore-11.3.0-bare
                Python/3.7.4-GCCcore-8.3.0
                Python/3.8.2-GCCcore-9.3.0
                Python/3.8.20-GCCcore-11.3.0
                Python/3.9.5-GCCcore-10.3.0-bare
                Python/3.9.5-GCCcore-10.3.0
                Python/3.10.4-GCCcore-11.3.0-bare
                Python/3.10.4-GCCcore-11.3.0
                Python/3.10.13-GCCcore-11.3.0
                Python/3.11.3-GCCcore-12.3.0
                Python/3.12.3-GCCcore-13.3.0
                Python/3.13.1-GCCcore-14.2.0
             Other possible modules matches:
                Biopython  Boost.Python  GitPython  IPython  Python-bundle-PyPI  flatbuffers-python  meson-python  protobuf-python  spglib-python

        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
          To find other possible module matches execute:

              $ module -r spider '.*Python.*'

        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
          For detailed information about a specific "Python" package (including how to load the modules) use the module's full name.
          Note that names that have a trailing (E) are extensions provided by other modules.
          For example:

             $ module spider Python/3.13.1-GCCcore-14.2.0
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        ```

    ??? shell "module load Python/3.11.3-GCCcore-12.3.0"

        ```shell
        $ module load Python/3.11.3-GCCcore-12.3.0
        $ module list

        Currently Loaded Modules:
          1) GCCcore/12.3.0                 5) ncurses/6.4-GCCcore-12.3.0       9) XZ/5.4.2-GCCcore-12.3.0
          2) zlib/1.2.13-GCCcore-12.3.0     6) libreadline/8.2-GCCcore-12.3.0  10) libffi/3.4.4-GCCcore-12.3.0
          3) binutils/2.40-GCCcore-12.3.0   7) Tcl/8.6.13-GCCcore-12.3.0       11) OpenSSL/1.1
          4) bzip2/1.0.8-GCCcore-12.3.0     8) SQLite/3.42.0-GCCcore-12.3.0    12) Python/3.11.3-GCCcore-12.3.0

        $ python --version
        Python 3.11.3
        ```


    ??? shell "module purge"

        ```shell
        $ module purge
        $ module list
        No modules loaded

        $ python --version
        -bash: python: command not found
    ```

If you recurrently need lots of modules, this loading can be automated with a (ba)sh-file, so that you just have to execute the file once and it loads all modules, you need. Be aware the loading modules by default (via a (ba)sh-file) can result in conflics when loading modules from the command-line or in a Job-script.

# --8<-- [end:lmod]

More detailed information about what modules are available in the TU/e Umbrella HPC Cluster can be found here:

[Commercial software modules](../../software/commercial.md)

[Non-Commercial software modules](../../software/non-commercial.md)

[Python related software modules](../../software/python.md)

---

![Lmod logo](../../software/Lmod-logo.png){: style="height:30px"}

:  The TU/e Umbrella HPC cluster uses [lmod](https://lmod.readthedocs.io/) a LUA based environment module system.

---

## Parallel Programming

Currently development of computers is at a point, where you cannot just make a processor run faster (e.g. by increasing its clock frequency), because limits of physics have been reached in semiconductor development. Therefore the current approach is to split the work into multiple, ideally independent parts, which are then executed in parallel. Similar to cleaning your house, where everybody takes care of a few rooms, on a supercomputer this is usually done with parallel programming paradigms like Open Multi-Processing (OpenMP) or Message Passing Interface (MPI). However like the fact that you only have one vacuum cleaner in the whole house which not everybody can use at the same time, there are limits on how fast you can get, even with a big number of processing units/cpus/cores (analogous to people in the metaphor) working on your problem (cleaning the house) in parallel.

## Software Manipulation
### Generic software

The clusters have quite a few programs pre-installed. They are managed
as optional modules that you have to load before you can use them. One
reason for using them this way (I guess...) is that this makes it
possible to have multiple versions of the same program on the same
system, which can be relevant (multiple pythons for example). This page
explains the basic usage of modules. All module management is done
through the aptly named program "module".

#### Viewing available modules

To show the available modules, you should run `module avail` This prints
out a list of available modules to the screen.

#### Viewing loaded modules

To show which modules are already loaded, run `module list`

#### Loading modules

In order to use a module that is not loaded, run
`module load `<module name> For example, if you want to use the intel
compiler, "icc", if you try to run it from the command line, you will
get

    $ icc
    -bash: icc: command not found

After loading this becomes

    $ module load intel
    $ icc
    icc: command line error: no files specified; for help type "icc -help"

which is the expected behaviour.

#### Unloading modules

As easy as you can load modules, you can also unload them. The proper
command, as you might have guessed, is `module unload `<name of module>
So, to unload the intel module, you would run `module unload intel`.

### Specific software

#### Uploading

You can upload your specific (or even custom) software to your [personal homedir](../access/index.md).

For uploading modules, you should contact a system administrator.
