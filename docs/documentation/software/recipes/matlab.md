---
title: MATLAB
tags: [Software, Module]
---
![MATLAB in Umbrella On Demand](matlab-ood.png){: align=right style="height:100px"}
[MATLAB](https://nl.mathworks.com/products/matlab.html){:target="_blank"} by MathWorks is a programming and numeric computing platform used by millions of engineers and scientists to analyze data, develop algorithms, and create models.

[MATLAB Basic Functions Reference](matlab-basic-functions-reference.pdf)

## Using MATLAB interactive<br>(Graphical User Interface)

Use your browser to connect to [Umbrella On Demand](https://hpc.tue.nl){:target="_blank"}

## Using MATLAB in SLURM batch jobs<br>(Command Line Interface)

### Test MATLAB

Load the module(s)

```shell 
[user@umbrella]$ module purge
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load MATLAB/2024b
```

Check if the licenses are available:

```shell
[user@umbrella]$ matlab -dmlworker -nodisplay -singleCompThread -r "ver -support;exit"
```

Output to screen should start with:

```output
-----------------------------------------------------------------------------------------------------
MATLAB Version: 24.2.0.2712019 (R2024b)
MATLAB License Number: 284992
Operating System: Linux 4.18.0-553.16.1.el8_10.x86_64 #1 SMP Thu Aug 8 17:47:08 UTC 2024 x86_64
Java Version: Java 1.8.0_202-b08 with Oracle Corporation Java HotSpot(TM) 64-Bit Server VM mixed mode
-----------------------------------------------------------------------------------------------------
MATLAB                                                Version 24.2        (R2024b)      License 284992
```

Check the GPU(s) available. This command only gives output on nodes with GPU (MIG GPU(s) throw an Error)) installed and when requested:

```gpuDeviceTable```

### MATLAB SLURM sbatch jobscript example using 1 CPU

```slurm
#!/bin/bash
#SBATCH --job-name=test_matlab
#SBATCH --output=test_matlab-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load MATLAB/2024b

matlab -batch simple
```

??? example "simple.m"
  
    ```matlab
    a=1;
    b=2;
    disp (a + b);
    exit;
    ```

### MATLAB SLURM sbatch jobscript example using 8 CPU

MATLAB by default creates a parpool("Processes") using the available CPUs (--cpus-per-task).

```slurm
#!/bin/bash
#SBATCH --job-name=test_matlab
#SBATCH --output=test_matlab-%j.log
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=8
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=00:05:00

module purge
module load Umbrella/2024
module load MATLAB/2024b

matlab -batch parallel
```

??? example "parallel.m"
  
    ```matlab
    parfor idx = 1:8
        pause(10);
    end
    exit;
    ```

## Parallel Computing using MATLAB on the **Umbrella** HPC Cluster

Below the steps to configure MATLAB so it's submit jobs to a cluster, retrieve results, and debug errors. Either using interactive MATLAB in the Cluster, or using MATLAB running on your Desktop/Laptop.  

### CONFIGURATION – Interactive MATLAB client (GUI) on the cluster

After logging into [hpc.tue.nl](<https://hpc.tue.nl>){:target="_blank"}, click the MATLAB app and choose your settings. Then press the "Launch" button. Wait for the session to start and press "Launch MATLAB". Wait for the MATLAB application to appear. Then, on the Home tab, click Parallel > Discover Clusters… (on your network) to discover the profile.

Jobs will now default to the cluster rather than submit to the local machine.

### INSTALLATION and CONFIGURATION – Desktop MATLAB client

The **Umbrella** MATLAB support package (a ZIP file) can be found [here](tue.Desktop.zip).

Download the ZIP file and start MATLAB on your local compute. The ZIP file should be unzipped in the location returned by calling

```matlab
>> userpath
```

Configure MATLAB to run parallel jobs on the cluster by calling configCluster (configCluster must be in the _userpath_ folder).  configCluster only needs to be called once per version of MATLAB.

```matlab
>> configCluster
```

Submission to the cluster requires SSH credentials.  You will be prompted for username and password or identity file (private key).  The username and location of the private key will be stored in MATLAB for future sessions.

Jobs will now default to the cluster rather than submit to the local machine.

**NOTE**: To submit to the local machine instead of the cluster, run the following:

```matlab
>> % Get a handle to the local resources
>> c = parcluster("local");
```

### CONFIGURING JOBS

Prior to submitting the job, various parameters can be assigned, such as queue, e-mail, walltime, etc.  The following is a partial list of parameters.  See AdditionalProperties for the complete list.  [*Only Partition is required.*]

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

[REQUIRED]

>> % Specify the partition
>> c.AdditionalProperties.Partition = "partition-name";

[OPTIONAL]

>> % Specify the account
>> c.AdditionalProperties.AccountName = "account-name";

>> % Specify a constraint
>> c.AdditionalProperties.Constraint = "feature-name";

>> % Request email notification of job status
>> c.AdditionalProperties.EmailAddress = "user-id@tue.nl";

>> % Specify number of GPUs (default: 0)
>> c.AdditionalProperties.GPUsPerNode = 1;

>> % Specify memory to use, per core (default: 4gb)
>> c.AdditionalProperties.MemPerCPU = "6gb";

>> % Specify cores per node
>> c.AdditionalProperties.ProcsPerNode = 4;

>> % Set node exclusivity (default: false)
>> c.AdditionalProperties.RequireExclusiveNode = true;

>> % Use reservation
>> c.AdditionalProperties.Reservation = "reservation-name";

>> % Specify the wall time (e.g., 1 day, 5 hours, 30 minutes)
>> c.AdditionalProperties.WallTime = "1-05:30";
```

Save changes after modifying AdditionalProperties for the above changes to persist between MATLAB sessions.

```matlab
>> c.saveProfile
```

To see the values of the current configuration options, display AdditionalProperties.

```matlab
>> % To view current properties
>> c.AdditionalProperties
```

Unset a value when no longer needed.

```matlab
>> % Turn off email notifications
>> c.AdditionalProperties.EmailAddress = "";
>> c.saveProfile
```

### INTERACTIVE JOBS - MATLAB client on the cluster

To run an interactive pool job on the cluster, continue to use parpool as before.

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

>> % Open a pool of 64 workers on the cluster
>> pool = c.parpool(64);
```

Rather than running local on the local machine, the pool can now run across multiple nodes on the cluster.

```matlab
>> % Run a parfor over 1000 iterations
>> parfor idx = 1:1000
        a(idx) = rand;
   end
```

Delete the pool when it’s no longer needed.

```matlab
>> % Delete the pool
>> pool.delete
```

### INDEPENDENT BATCH JOB

Use the batch command to submit asynchronous jobs to the cluster.  The batch command will return a job object which is used to access the output of the submitted job.  See the MATLAB documentation for more help on batch.

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

>> % Submit job to query where MATLAB is running on the cluster
>> job = c.batch(@pwd, 1, {}, "CurrentFolder",'.');

>> % Query job for state
>> job.State

>> % If state is finished, fetch the results
>> job.fetchOutputs{:}

>> % Delete the job after results are no longer needed
>> job.delete
```

To retrieve a list of running or completed jobs, call parcluster to return the cluster object.  The cluster object stores an array of jobs that are queued to run, are running, have run, or have failed.  Retrieve and view the list of jobs as shown below.

```matlab
>> c = parcluster;
>> jobs = c.Jobs
>>
>> % Get a handle to the second job in the list
>> job2 = c.Jobs(2);
```

Once the job has been selected, fetch the results as previously done.

fetchOutputs is used to retrieve function output arguments; if calling batch with a script, use load instead.   Data that has been written to files on the cluster needs be retrieved directly from the file system (e.g., via sftp).

```matlab
>> % Fetch all results from the second job in the list
>> job2.fetchOutputs{:}
```

### PARALLEL BATCH JOB

batch can also submit parallel workflows.  Let’s use the following example for a parallel job, which is saved as parallel_example.m.

```matlab
function [sim_t, A] = parallel_example(iter)

if nargin==0
    iter = 8;
end

disp("Start sim")

t0 = tic;
parfor idx = 1:iter
    A(idx) = idx;
    pause(2)
    idx
end
sim_t = toc(t0);

disp("Sim completed")

save RESULTS A

end
```

This time when using the batch command, also specify a MATLAB Pool argument.

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

>> % Submit a batch pool job using 4 workers for 16 simulations
>> job = c.batch(@parallel_example, 1, {16}, "Pool",4, "CurrentFolder",'.');

>> % View current job status
>> job.State

>> % Fetch the results after a finished state is retrieved
>> job.fetchOutputs{:}
ans =
    8.8872
```

The job ran in 8.89 seconds using four workers.  Note that these jobs will always request N+1 CPU cores, since one worker is required to manage the batch job and pool of workers.   For example, a job that needs eight workers will request nine CPU cores.

Run the same simulation but increase the Pool size.  This time, to retrieve the results later, keep track of the job ID.

**NOTE**: For some applications, there will be a diminishing return when allocating too many workers, as the overhead may exceed computation time.

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

>> % Submit a batch pool job using 8 workers for 16 simulations
>> job = c.batch(@parallel_example, 1, {16}, "Pool",8, "CurrentFolder",'.');

>> % Get the job ID
>> id = job.ID
id =
    4
    
>> % Clear job from workspace (as though MATLAB exited)
>> clear job
```

With a handle to the cluster, the findJob method searches for the job with the specified job ID.

```matlab
>> % Get a handle to the cluster
>> c = parcluster;

>> % Find the old job
>> job = c.findJob("ID", 4);

>> % Retrieve the state of the job
>> job.State
ans =
    finished

>> % Fetch the results
>> job.fetchOutputs{:};
ans =
    4.7270
```

The job now runs in 4.73 seconds using eight workers.  Run code with different number of workers to determine the ideal number to use.

Alternatively, to retrieve job results via a graphical user interface, use the Job Monitor (Parallel > Monitor Jobs).

### HELPER FUNCTIONS

| Function              | Description                          | Applies only to Desktop    |
|---                    |---                                   |---                         |
| clusterFeatures       | List of cluster features/constraints |                            |
| clusterGpuCards       | List of cluster GPU cards            |                            |
| clusterPartitionNames | List of cluster partition names      |                            |
| fixConnection         | Reestablish cluster connection (e.g., after reconnection of VPN) | true |
| willRun               | Explain why job is queued            |                            |

### DEBUGGING

If a serial job produces an error, call the getDebugLog method to view the error log file.  When submitting an independent job, specify the task.

```matlab
>> c.getDebugLog(job.Tasks)
```

For Pool jobs, only specify the job object.

```matlab
>> c.getDebugLog(job)
```

When troubleshooting a job, the cluster admin may request the scheduler ID of the job.  This can be derived by calling getTaskSchedulerIDs (call schedID(job) before R2019b).

```matlab
>> job.getTaskSchedulerIDs()
ans =
    25539
```

## TO LEARN MORE

To learn more about the MATLAB Parallel Computing Toolbox, check out these resources:

- [Parallel Computing Overview](http://www.mathworks.com/products/parallel-computing/index.html){:target="_blank"}
- [Parallel Computing Documentation](http://www.mathworks.com/help/distcomp/index.html){:target="_blank"}
- [Parallel Computing Coding Examples](https://www.mathworks.com/help/parallel-computing/examples.html){:target="_blank"}
- [Parallel Computing Tutorials](http://www.mathworks.com/products/parallel-computing/tutorials.html){:target="_blank"}
- [Parallel Computing Videos](http://www.mathworks.com/products/parallel-computing/videos.html){:target="_blank"}
- [Parallel Computing Webinars](http://www.mathworks.com/products/parallel-computing/webinars.html){:target="_blank"}
