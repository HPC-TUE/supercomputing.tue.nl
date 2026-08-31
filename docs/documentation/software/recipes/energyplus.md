---
title: EnergyPlus
tags: [Software, Module]
---

EnergyPlus™ is a whole building energy simulation program that
engineers, architects, and researchers use to model both energy
consumption—for heating, cooling, ventilation, lighting and plug and
process loads—and water use in buildings. Some of the notable features
and capabilities of EnergyPlus include:

-   **Integrated, simultaneous solution** of thermal zone conditions and
    HVAC system response that does not assume that the HVAC system can
    meet zone loads and can simulate un-conditioned and
    under-conditioned spaces.
-   **Heat balance-based solution** of radiant and convective effects
    that produce surface temperatures thermal comfort and condensation
    calculations.
-   **Sub-hourly, user-definable time steps** for interaction between
    thermal zones and the environment; with automatically varied time
    steps for interactions between thermal zones and HVAC systems. These
    allow EnergyPlus to model systems with fast dynamics while also
    trading off simulation speed for precision.
-   **Combined heat and mass transfer** model that accounts for air
    movement between zones.
-   **Advanced fenestration models** including controllable window
    blinds, electrochromic glazings, and layer-by-layer heat balances
    that calculate solar energy absorbed by window panes.
-   **Illuminance and glare calculations** for reporting visual comfort
    and driving lighting controls.
-   **Component-based HVAC** that supports both standard and novel
    system configurations.
-   **A large number of built-in HVAC and lighting control strategies**
    and an extensible runtime scripting system for user-defined control.
-   **Functional Mockup Interface** import and export for co-simulation
    with other engines.
-   **Standard summary and detailed output reports** as well as user
    definable reports with selectable time-resolution from annual to
    sub-hourly, all with energy source multipliers.



#### Running Parametric Analysis on cluster

##### Running many Eplus models with slurm

###### **introduction**

EnergyPlus parametric studies are characterized by the large number of
simulations that must be performed if the number of parameters and the
variations in these increase. In order to be able to do the
pre-processing, simulations and post-processing within reasonable times,
it is necessary to perform as many simulations as possible in parallel.
A High Performance Computing cluster, with many computing cores, is
ideally suited for this task. The energyPlus_HPC package is written to
work on clusters with the SLURM workload manager. A combination of SLURM
task array's with bash loops and python scripts can handle large
parametric studies involving milions of simulations.

A python package with an example can be installed from the TU/e GitLab
repository <https://gitlab.tue.nl/bwjand/energyplus_hpc.git>

###### **Running the simulations**

Prepare a python script to generate the models and import it in
epc_main.py. You can use SA_create_idf-scenario4_fr.py as template. Make
sure that you create the function create_epplus_model.

Edit ep_main.py and change

-   the import of the model_generator to your needs (line 17)
-   change the directories (line 33 - 40) to your project
-   change the comfort parameters (line 53 -57) to your needs

Edit runn_all.sh

-   the SLURM settings (line 10 -19) to your needs
-   the per_task number of simulations (line 22)

The simulation process is logged to the logfile (default
application.log). The level of logging can be set to DEBUG, INFO,
WARNING, ERROR, CRITICAL in ep_main.py. The default level is WARNING,
which means that only events of this level and above will be tracked
(i.e, WARNING, ERROR, and CRITICAL will be tracked by default)

### How to setup a virtual environment for eppy

Eppy is a scripting language for EnergyPlus idf files, and EnergyPlus
output files. Eppy is written in the programming language Python. As a
result it takes full advantage of the rich data structure and idioms
that are available in Python. You can programmatically navigate, search,
and modify EnergyPlus idf files using eppy. The power of using a
scripting language allows you to do the following:

-   Make a large number of changes in an idf file with a few lines of
    eppy code.
-   Use conditions and filters when making changes to an idf file
-   Make changes to multiple idf files.
-   Read data from the output files of a EnergyPlus simulation run.
-   Based on the results of a EnergyPlus simulation run, generate the
    input file for the next simulation run.

So what does this matter? Here are some of the things you can do with
eppy:

-   Change construction for all north facing walls.
-   Change the glass type for all windows larger than 2 square meters.
-   Change the number of people in all the interior zones.
-   Change the lighting power in all south facing zones.
-   Change the efficiency and fan power of all rooftop units.
-   Find the energy use of all the models in a folder (or of models that
    were run after a certain date)

##### creating the python virtual environment with eppy and geomeppy

-   module load Umbrella/2024
-   module load anaconda
-   conda create -n eppy_env python=3.7
-   conda activate eppy_env
-   pip install decorator=5.0.5
-   pip install eppy
-   pip install geomeppy
-   pip install pandas
-   pip ins xlsxwriter

Every time you like to use eppy activate your virtual environment (conda
activate eppy_env)
===Links===

-   [EnergyPlus web site](https://energyplus.net/)
-   [EnergyPlus web based
    documentation](https://bigladdersoftware.com/epx/docs/)
-   [Eppy](https://pypi.org/project/eppy/)