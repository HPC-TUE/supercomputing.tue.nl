---
title: ANSYS Lumerical
tags: [Software, Module]
---

[ANSYS Lumerical](https://www.ansys.com/products/optics){:target="_blank"}, part of the ANSYS Optics suite, is an optics simulation package.

## Using ANSYS Lumerical interactive<br>(Graphical User Interface)

![ANSYS Lumerical in Umbrella On Demdand](lumerical-ood.png){: style="height:100px"}
Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using ANSYS Lumerical in SLURM batch jobs<br>(Command Line Interface)

### Test ANSYS Lumerical Shared Memory

Load the modules

``` shell
[user@umbrella]$ module purge
[user@umbrella]$ module load intel/2024a
[user@umbrella]$ module load Lumerical/2025-R1.3
```

Check commandline version of Lumerical fdtd-engine

```shell
[user@umbrella]$ fdtd-engine -v
Ansys Lumerical 2025 R1.3 FDTD Solver Version 8.33.4124 (Linux 64bit)
```

### Lumerical SLURM sbatch jobscript example using Shared Memory

```slurm
#!/bin/bash
#SBATCH --job-name=test_lumerical
#SBATCH --output=test_lumerical-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load intel/2024a
module load Lumerical/2025-R1.3

fdtd-engine -t ${SLURM_CPUS_PER_TASK} -logall -fullinfo example.lsf
```

### Lumerical SLURM sbatch jobscript example using intelMPI

```slurm
#!/bin/bash
#
#SBATCH --job-name=test_lumerical
#SBATCH --output=test_lumerical-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=8
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load intel/2024a
module load Lumerical/2025-R1.3

mpirun fdtd-engine-impi-lcl -logall -fullinfo example.lsf
```

## Method 1

We will make Lumerical believe it is running on a "local computer"
(which is in fact the HPC system). The approach has some benefits:

-   It is relatively easy to set up.
-   It is slightly less prone to issues with e.g. MPI.

The downsides are:

-   Parameter sweeps cannot be done in parallel; for this a tighter
    integration with the scheduler (Slurm) is needed.
-   It is probably unsafe to run multiple instances of Lumerical
    simultaneously with this approach.
-   The user must set some maximum number of threads beforehand, and
    must consistently request the same amount from the scheduler, which
    is prone to errors.

In the following we will restrict Lumerical to at most 4 threads. Any
other number of threads would work as well, but using more threads can
lead to longer waiting times in the queue.

### Workflow

This is a suggested workflow for Lumerical on the Umbrella cluster:

1.  Initial setup of Lumerical (first-time use only!)
2.  Prepare LSF file using the Lumerical GUI on the cluster
3.  Submit Lumerical job
4.  Postprocess/view results using the Lumerical GUI on the cluster

Each of these steps is detailed below. It is also possible to run
non-interactive Python jobs; this is a detailed below as well.

### Initial setup

1.  Log on to the cluster using [Open OnDemand](../../steps/access/openondemand.md), and start an interactive
    Lumerical session.
2.  Within the interactive session, click "Solvers" → "New" → "FDTD". A
    new window opens.
3.  From the "Simulation" menu, choose "Resource configuration". A new
    window opens.
4.  In the "Resource configuration" window, in the FDTD solver tab,
    delete all but one profile.
5.  Click the "Edit" button to edit the remaining profile. A new window
    opens.
6.  In the "Resource advanced options" window, make the following
    changes, and then hit OK.
    -   Job launching preset: Local Computer
    -   FDTD options:
        -   extra command line options: (empty)
        -   checkpoint directory: (empty)
        -   no default options: unchecked
        -   create log for all processes: unchecked
7.  In the "Resource configuration window", make sure the one remaining
    profile has the following values set. Values can be changed by
    double clicking the value.
    -
    -   active: true
    -   threads: 4 (or whichever number you decided on)
    -   capacity: 1
8.  Optionally, hit "Run tests". After a few seconds it should say
    "Tests completed successfully".
9.  In the Design environment tab, make the following changes:
    -   auto detect: unchecked
    -   max threads: 4 (or whichever number you decided on)
10. Hit "Save".
11. Close Lumerical.

### Prepare/postprocess with Lumerical GUI

The Lumerical GUI can be run on the cluster through [Open OnDemand](../../steps/access/openondemand.md).

### Submitting a Lumerical job

**It may be unsafe to run multiple Lumerical jobs simultaneously!** This
is due to the use of the "local computer" resource configuration
profile.

This is an example job script:

    #!/usr/bin/bash

    #SBATCH --ntasks=1
    #SBATCH --cpus-per-task=4   # <--- replace with desired number of threads
    #SBATCH --partition=tue.default.q    # <--- replace with your partition

    module load lumerical/2021-R1

    xvfb-run fdtd-solutions -nw -run [script.lsf]   # <--- replace with your script

The above script uses `xvfb-run` to make Lumerical believe it is
connected to a monitor.

### Submitting a Lumerical Python job

**It may be unsafe to run multiple Lumerical jobs simultaneously!** This
is due to the use of the "local computer" resource configuration
profile.

This is an example job script:

    #!/usr/bin/bash

    #SBATCH --ntasks=1
    #SBATCH --cpus-per-task=4   # <--- replace with desired number of threads
    #SBATCH --partition=tue.default.q

    module load lumerical/2021-R1

    set -e

    LUMDIR=$(dirname $(dirname $(which fdtd-solutions)))
    #export PATH="$LUMDIR/python/bin:$PATH"  # <--- uncomment to use the version of Python bundled with Lumerical
    export PYTHONPATH="$LUMDIR/api/python"

    # -u to keep stdout/stderr unbuffered
    xvfb-run python3 -u myscript.py

Also see the following websites:

-   Setting Lumerical environment variables:
    [here](https://optics.ansys.com/hc/en-us/articles/7595785040403).

## Method 2

To be done: configure Lumerical so it makes use of the cluster's MPI
system. This implies a tighter integration with the scheduler, and is
therefore less prone to user error.

## Method 3

Direct resource integration of the HPC node in the Lumerical GUI. Lumerical will handle file transfer from your PC to the HPC, run the simulation on HPC and will download the simulated file back to your PC.
By default, the HPC node will not use the GUI license, but just a runner license.

### Workflow

1.  Initial setup of Lumerical (first-time use only!)
2.  Prepare Lumerical file on your local PC using the GUI
3.  Run Lumerical job (which will transfer to HPC, run and transfer back)
4.  Postprocess/view results of Lumerical file on your local PC using the GUI

### Initial setup

1. Configure SSH keys to connect to the HPC from you local PC [using this method](../../steps/access/ssh/step-1.md)
2. Configure Lumerical config settings on the HPC
   1. Connect to HPC using SSH
   2. Add a new directory using: `mkdir -p ~/.config/Lumerical/`
   3. Create a new file named License.ini inside the folder: `nano ~/.config/Lumerical/License.ini`
   4. Add the following contents
        ```
        [license]
        domain=2
        default=user
        ansysserver\host=1055@tue032938.ele.tue.nl
        flexserver\host=27011@tue032938.ele.tue.nl
        ```
   5. Save and exit using *crtl+x* and press *y* to confirm saving
3. Configure slurm.py on your local PC (if your Lumerical version is **older** than 2023 R2.2)
   1. Locate the slurm.py file on your local Lumerical installation usually at `C:\Program Files\Lumerical\vxxx\scripts\job_schedulers\slurm.py`
   2. Open the file and change the following lines to:
        ```
        USE_SSH = True
        USE_SCP = True
        CLUSTER_CWD = ''
        if USE_SSH:
            USER_NAME = "username" # TU/e username
            SSH_LOGIN = f"{USER_NAME}@hpc.tue.nl"
            SSH_KEY = expanduser('~/.ssh/privkeyname') # Location of your private key on your PC
        ```
   3. Save the file
4. Configure job_scheduler_input.json on your local PC (if your Lumerical version is 2023 R2.2 or **newer**)
   1. Please update according to [Lumericals documentation](https://optics.ansys.com/hc/en-us/articles/360034620113-Lumerical-job-scheduler-integration-Slurm-Torque-LSF-SGE)
5. Add the HPC as resource in the Lumerical GUI
   1. Open your Lumerical software tool (like FDTD)
   2. Press the resources button in the top ribbon
   3. Add new resource, select it and press edit
   4. Change the job launcher preset to 'Job Scheduler: Slurm'
   5. In the command field, add `sbatch -N 1`
   6. In the submission script field add
        ```
        #!/usr/bin/bash
        #SBATCH --nodes=1
        #SBATCH --ntasks=16
        #SBATCH --partition=elec-phi.gpu.q
        #SBATCH --output=slurm-%j.out

        module purge
        module load intel/2023a
        module load lumerical/2024-R1.1

        mpirun fdtd-engine-impi-lcl {PROJECT_FILE_PATH}
        ```

### Prepare job & run on HPC

Now that everything is configured, you can simply prepare your FDTD file and run the job like you are used to. The software will automatically upload the .fsp file to the HPC, and schedule the job. When the job is finished, it will automatically download it back to your PC.

### Debug in case of errors

In case the simulation is not running, or it stopped really quickly, you can look at the error and log files on the HPC. They will be automatically added when the file is transferred to the HPC.
You can connect to HPC over SSH and check the contents of the log files to debug.

## Troubleshooting

### Failed to start messaging, check licenses...

This is a poorly-worded error message that *may* indicate Lumerical
cannot connect to an X11 server. Lumerical is a GUI application; even
when started with **-nw** (no window) it needs to have an X11 server
available. Only the solvers themselves do not require X11.
