---
tags: [Software]
---
# Environment Modules

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

If you recurrently need lots of modules, this loading can be automated with a (ba)sh-file, so that you just have to execute the file once and it loads all modules, you need. Be aware the loading modules by default (via a (ba)sh-file) can result in conflics when loading modules from the command-line or in a Job-script.

More deatailed infromation about what modules are available in the TU/e Umbrella HPC Cluster can be found here:

[Commercial software modules](../../software/commercial.md)

[Non-Commercial software modules](../../software/non-commercial.md)

[Python related software modules](../../software/python.md)

![Lmod logo](../../software/Lmod-logo.png){: align=left style="height:30px"}
The TU/e Umbrella HPC cluster uses [lmod](https://lmod.readthedocs.io/) a Lua based environment module system.


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
