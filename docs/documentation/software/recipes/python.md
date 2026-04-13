---
title: Python
tags: [Software, Module]
---

The TU/e Umbrella HPc cluster has environment modules available specially for Pyhton, an overview can be found here: [Python Modules](../python.md)

NOTE: There are various versions of python available as modules, we recommend to to use a recent version as older version are no longer supported or updated: [Python Versions and their support](https://devguide.python.org/versions/#versions) 

## Test Python

Load a Python version via environment modules.

```shell
[user@umbrella]$ module purge
[user@umbrella]$ module load Python/3.11.3
[user@umbrella]$ python --version
Python 3.11.3
```

Using environment modules to make packages available for import.

```shell
[user@umbrella]$ module purge
[user@umbrella]$ module load PyTorch/2.1.2-foss-2023a
[user@umbrella]$ python
Python 3.11.3 (main, Feb  2 2024, 18:52:27) [GCC 12.3.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import torch as t
>>> print(t.__version__)
2.1.2
```

## Python jobscript example

```slurm
#!/bin/bash
#SBATCH --job-name=test_python
#SBATCH --output=test_python-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load SciPy-bundle/2023.07-gfbf-2023a

cd $HOME/Jobs/Python

python test.py
```

## Virtual environments

### Python virtual env

We recommend you to work within a [virtual environment](https://packaging.python.org/guides/installing-using-pip-and-virtual-environments/){:target="_blank"}
if you work with Python packages. This is essentially a local directory
where all packages you install are stored, so as to not interfere with
system packages or other projects you might have. Usage is quite
straightforward. First, create an environment and chose a name for it
(and the directory):

`python3 -m venv my-python-environment`

After that one-time step, you can activate the environment at any time
using

`source my-python-environment/bin/activate`

and deactivate the environment by executing `deactivate`. Your prompt
should indicate if a virtual environment is active, if you use it in an
interactive session.

Within this environment, you can freely install and upgrade packages
using pip. You can start with `pip install --upgrade pip` to make sure
the package manager is on the latest version, followed by
`pip install <package>` to install whatever you need.

#### Check availability and install packages

To check the availability of a package, either use the command
`pip show <package>` or `pip list`. If the package is installed, the command will
return the version and some other information about it. Otherwise the
command will issue a warning, and you can then install the package as
follows:

`pip install <package>`

### Using Anaconda

**NOTE:** Anaconda has great impact on your environment settings and using it is **not advised**.

If you want to use [Anaconda](https://www.anaconda.com/){:target=_blank}, you
will have to load a module: `module load Anaconda3`. Several versions are
available, as you can see by running `module avail anaconda` and `module avail
Anaconda` (mind the capital A!). The former command will load the current
version of Anaconda (which is kept up-to-date on a best effort basis). Loading
this module will make several executables available, among which `anaconda`,
`conda`, `flask` and `jupyter`. You *can* then directly use those in your
script. We do however recommend you to always work in a
[virtual environment](#virtual-environments).

`conda` in fact allows you to create
[environments](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html){:target="_blank"}
and even to install a specific version of Python for an environment.
This enables even more flexibility. As opposed to the built-in `venv`
module of Python, Anaconda environments are stored in a central location
in your home directory. You can thus activate environments regardless of
your current working directory.

```shell
module load Python/3.11.3-GCCcore-12.3.0 
module load Anaconda3/2023.09-0
eval "$(conda shell.bash activate)"
conda create -n myconda
```

After that, you can at all times activate your environment as follows:

```shell
module load Python/3.11.3-GCCcore-12.3.0 
module load Anaconda3/2023.09-0
eval "$(conda shell.bash activate)"
conda activate myconda
```

To list your environments, use:

```shell
conda env list
```

And clean up environments you no longer need by running:

```shell
conda env remove -n myconda
```

Within an environment, you can `pip install` libraries just like in
Python `venv` without impacting other environments.

### Using TensorFlow

[TensorFlow](https://www.tensorflow.org/){:target=_blank} is available as a module:

```shell
module load TensorFlow/2.13.0-foss-2023a 
```

If you want to use an other version of TensorFlow than avaiable, you should
create a [virtual environment](#virtual-environments),
activate it and then

```shell
TMPDIR=/scratch-node pip install --build /screatch-node tensorflow`
```

This is a slight variation on the `pip install tensorflow` command you might
expect, which is needed because of the limited size of the `/tmp`
partition you get on the HPC cluster. Please try rerunning the command
once or twice if it fails due to too little disk space, before reporting
the problem.

When done, you can verify if the installation was successful by
executing

`python -c $'import tensorflow as tf\nprint(tf.__version__)'`

which should print something like `2.2.0`.

Now that you have installed TensorFlow, using it is a matter of
activating the virtual environment and importing it in your script.
