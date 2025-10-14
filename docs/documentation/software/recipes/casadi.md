---
title: CasADi
tags: [Software, Module, Python]
knowledgebase: true
---

[CasAdi](https://web.casadi.org/) is an open-source tool for nonlinear optimization and algorithmic differentiation. It facilitates rapid — yet efficient — implementation of different methods for numerical optimal control, both in an offline context and for nonlinear model predictive control (NMPC).

## CasADi for MATLAB

## Using CasADi for MATLAB interactive<br>(Graphical User Interface)

Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"} and start MATLAB session that includes CasADi.

## Using CasADi for MATLAB in SLURM batch jobs<br>(Command Line Interface)

A CasADi module for MATLAB needs to be loaded so MATLAB can use CasADi.

```slurm
#!/bin/bash
#SBATCH --job-name=test_casadi
#SBATCH --output=test_casadi-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load CasADi/3.7.2-linux64-matlab
module load MATLAB/2025b

matlab -batch test_casadi
```

??? example "test_casadi.m"
  
    ```matlab
    import casadi.*
    
    % Create scalar/matrix symbols
    x = MX.sym('x',5);
    
    % Compose into expressions
    y = norm(x,2);
    
    % Sensitivity of expression -> new expression
    grad_y = gradient(y,x)
    
    % Create a Function to evaluate expression
    f = Function('f',{x},{grad_y});
    
    % Evaluate numerically
    grad_y_num = f([1;2;3;4;5])
    ```

## Using CasADi for Python in SLURM batch jobs

When loading the CasADi module the correct version of Python and it's dependencies are automaticaly loaded.

```slurm
#!/bin/bash
#SBATCH --job-name=test_casadi
#SBATCH --output=test_casadi-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load CasADi/3.7.2-foss-2024a

python test_casadi.py
```

??? example "test_casadi.py"
  
    ```python
    from casadi import *
    
    # Create scalar/matrix symbols
    x = MX.sym('x',5)
    
    # Compose into expressions
    y = norm_2(x)
    
    # Sensitivity of expression -> new expression
    grad_y = gradient(y,x);
    
    # Create a Function to evaluate expression
    f = Function('f',[x],[grad_y])
    
    # Evaluate numerically
    grad_y_num = f([1,2,3,4,5]);
    
    print(grad_y_num);
    ```

## Including and using the CoinHSL solvers

Load the module for CoinHSL

MATLAB

```shell
ml purge
ml CoinHSL/2024.05.15-foss-2024a
ml CasADi/3.7.2-linux64-matlab
```

Python

```shell
ml purge
ml CoinHSL/2024.05.15-foss-2024a
ml CasADi/3.7.2-foss-2024a
```

## Using solvers (e.q. MUMPS) that request MPI in Python

If the following ERROR is thrown by CasADi for python "The MPI_Comm_f2c() function was called before MPI_INIT was invoked."
this indicates a missing MPI module. Some solvers are compiled to use MPI and need the mpi4py module to be loaded and the
python package mpy4py.MPI needs to be imported.

```shell
ml purge
ml mpi4py/4.0.1-gompi-2024a
ml CasADi/3.7.2-foss-2024a
```

```python
from casadi import *
from mpi4py import MPI

# Symbols/expressions
x = MX.sym('x')
y = MX.sym('y')
z = MX.sym('z')
f = x**2+100*z**2
g = z+(1-x)**2-y

nlp = {}                 # NLP declaration
nlp['x']= vertcat(x,y,z) # decision vars
nlp['f'] = f             # objective
nlp['g'] = g             # constraints

# Create solver instance
F = nlpsol('F','ipopt',nlp);

# Solve the problem using a guess
F(x0=[2.5,3.0,0.75],ubg=0,lbg=0)
```