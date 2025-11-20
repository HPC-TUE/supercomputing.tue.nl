# Submitting jobs using Slurm

![EasyBuild logo](200px-Slurm_logo-dark.png#only-dark){: align=right }
![EasyBuild logo](200px-Slurm_logo-light.png#only-light){: align=right }

## Introduction to Slurm

Slurm (Used to stand for: Simple Linux Utility for Resource Management, but now is just Slurm Workload Manager) is a powerful cluster management and job scheduling system. Slurm allows users to submit jobs to be performed on one or many nodes in a cluster, manage job queues, and query the status of jobs and queues.

This guide will cover the essentials of using Slurm, focusing on the `sbatch` command for job submission and discussing Slurm partitions.

## Understanding Slurm Partitions

A partition is a logical grouping of nodes, kind of like a queue, that specifies which nodes and job configurations are available to the jobs associated with it. Your cluster administrator will configure partitions according to the cluster's policies and available resources. You should choose a partition based on your job requirements and the partition specifications.

List available partitions (Also known as Queues):

```bash
sinfo
```

## Writing a Batch Job Script

A batch job script is a shell script that includes Slurm directives within commented lines (prefixed with `#SBATCH`) followed by the commands you want to execute.

Here's an example job script for a CPU only node:

```slurm
#!/bin/bash

#SBATCH --job-name=my_job
#SBATCH --output=my_job_output_%j.txt
#SBATCH --partition=tue.default.q
#SBATCH --time=02:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2G

# Load modules or software if needed
# In the example PyTorch is made available for import in to my_sript.py
module load PyTorch/2.1.2-foss-2023a

# Execute the script or command
python my_script.py
```
Here's an example job script for a GPU node:

```slurm
#!/bin/bash

#SBATCH --job-name=my_job
#SBATCH --output=my_job_output_%j.txt
#SBATCH --partition=tue.gpu.q         # Choose a partition that has GPUs
#SBATCH --time=16:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2G
#SBATCH --gpus=1                      # This is how to request a GPU

# Load modules or software if needed optimized for GPU use if available
# In the example PyTorch is made available for import in to my_sript.py
module load PyTorch/2.1.2-foss-2023a-CUDA-12.1.1

# Execute the script or command
python my_script.py
```

Here's what some of the key `sbatch` options mean:

- `--job-name`: Set the name of the job.
- `--output`: Designate the file to which Slurm will write the standard output (%j is the jobID).|
- `--partition`: Choose the partition on which the job should run (check with 'sinfo').
- `--time`: Specify the wall clock limit for the job (format 00-00:00:00 Days-Hours:Minutes:Seconds).
- `--nodes`: The number of nodes on which to run.
- `--ntasks-per-node`: The number of tasks to launch on each node.
- `--cpus-per-task`: The number of CPU cores per task.
- `--mem-per-cpu`: The memory required per CPU core.
- `--gpus`: The number of GPU to use.


## Submitting a Job with `sbatch`

Once you have written your job script, you can submit it to Slurm using `sbatch`.

```bash
sbatch my_job_script.sh
```

## Monitoring and Controlling Jobs

To check the status of your currently pending and running jobs, use `squeue`:

```bash
squeue --me
```

`squeue` can also be used to check the status of a single job:

```bash
squeue --job [JOBID]
```

You can cancel a submitted job using `scancel`.

```bash
scancel [JOBID]
```

You may want to monitor the resources being used by your job in real-time. This can be done using the `sstat` command.

```bash
sstat --format=MaxVMSize,MaxRSS,MaxDiskWrite,MaxDiskRead -j [JOBID]
```

## Advanced `sbatch` Options

### Using features

Nodes have Slurm-defined features that can be used to make sure a job uses a specific type of node(s). To check the available features on the nodes use to following:

```bash
sinfo -N -o "%20N  %4c  %10m  %60f"
```
The colomn AVAIL_FEATURES shows the configred features of the nodes.

To select a feature (run a job on the nodes with the feature) use the --constraint="" option. For example to make sure an NVIDIA A30 is used in the example job script for a GPU above add the following to the sbatch script:

```bash
#SBATCH --constraint="a30"
```

### More options

Slurm allows for a range of advanced options to precisely control the resources that a job requires. Here are some common advanced options:

- `--gres`: Specifies generic resources, often used for requesting GPUs.
- `--dependency`: Configures job dependencies, allowing jobs to be scheduled after certain other jobs complete.
- `--array`: Submits an array of similar jobs with a single `sbatch` command to iterate over different datasets or parameters.
- `--exclusive`: Requests exclusive node access for the job, even if requesting CPUs (or memory) that don't require the entire node.
- `--qos`: Specifies the Quality of Service for the job which may affect job priority or limits.
- `--reservation`: Submits a job to a reserved set of resources.

## Conclusion

This guide provides an overview of how to use Slurm, with an emphasis on utilizing the `sbatch` command for job submission and understanding partition allocations. For complete details on each command and advanced configuration options, consult the [official Slurm documentation](https://slurm.schedmd.com/documentation.html) or your cluster's user guide. Always be sure to follow best practices and policies of your specific cluster when submitting and managing jobs with Slurm.
