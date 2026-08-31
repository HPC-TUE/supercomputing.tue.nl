# Spark

## Simple, relatively small workloads

The following script will do the trick:

```bash
#!/bin/bash

#SBATCH --partition=tue.default.q    #FIXME: partition
#SBATCH --cpus-per-task=4            #FIXME: number of CPU cores needed
#SBATCH --mem=64G                    #FIXME: total RAM needed
#SBATCH --time=4:00:00               #FIXME: run time needed

module purge
module load Umbrella/2024
module load Spark
spark-submit --master 'local[*]' my_spark_script.py
```

`--master 'local[*]'` will tell Spark to start an instance of Spark (master and workers) in the CPUs and RAM that Slurm allocated for the job.  Once the instance has started, it will run `my_spark_script.py` as a workload within the Spark instance.  Once it finishes, Spark will exit, and the job will terminate.

## Spark cluster within a job

It is possible to set up a [Spark](https://spark.apache.org/){:target=_blank} cluster in a Slurm job as follows. 
First, create a directory to work in:

```shell
mkdir -p -- ~/spark/{logs,temp}
cd ~/spark
```

Then, upload the following Slurm batch script into that directory.
Please update the `#SBATCH` values accordingly to your needs.

??? example "spark.cmd"

    ```bash
    #!/bin/bash

    #SBATCH --partition=tue.test.q
    #SBATCH --nodes=3
    #SBATCH --cpus-per-task=4
    #SBATCH --mem-per-cpu=500
    #SBATCH --exclusive

    #SBATCH --time=01:00:00

    #SBATCH --output=/home/%u/spark/logs/%j.out

    # can only have one Spark slave per node in this script (otherwise would need
    # increasing ports and take care in general)
    #SBATCH --ntasks-per-node=1

    # this section will be run by sbatch initially
    if [ "$1x" != "srunningx" ]; then
        export _SPARK_LOGS="$HOME/spark/logs/"
        export _SPARK_TEMP="$HOME/spark/temp/"
        mkdir -p -- "$_SPARK_LOGS" "$_SPARK_TEMP"
        export _SPARK_MASTER_NODE="$_SPARK_TEMP/${SLURM_JOBID}_spark_master"

        # because Slurm copies this script temporarily and deletes it before we can
        # call it, we make our own copy
        _SCRIPT="$_SPARK_TEMP/${SLURM_JOBID}_$(basename -- "$0")"
        cp "$0" "$_SCRIPT"

        srun "$_SCRIPT" srunning
    else # if run by srun, decide via the Slurm procid whether we are master or worker
        module load Umbrella/2024
        module load Spark

        # trim "bin/spark-submit" from the below path to get Spark root
        _SPARK_LOC="$(whereis spark-submit | awk -F' ' '{print $2}')"
        export SPARK_HOME="${_SPARK_LOC%/*/*}"
        export SPARK_WORKER_DIR="$_SPARK_LOGS"
        export SPARK_LOCAL_DIRS="$_SPARK_LOGS"
        export SPARK_MASTER_PORT=7077
        export SPARK_MASTER_WEBUI_PORT=8080
        export SPARK_WORKER_CORES=$SLURM_CPUS_PER_TASK
        export SPARK_DAEMON_MEMORY=$(( $SLURM_MEM_PER_CPU * $SLURM_CPUS_PER_TASK / 2 ))m
        export SPARK_MEM=$SPARK_DAEMON_MEMORY

        source "$SPARK_HOME/sbin/spark-config.sh"
        source "$SPARK_HOME/bin/load-spark-env.sh"

        if [ "$SLURM_PROCID" -eq 0 ]; then
            export SPARK_MASTER_IP=$(hostname)
            MASTER_NODE=$(scontrol show hostname $SLURM_NODELIST | head -n 1)

            # save host and port so that slaves know where to submit jobs
            echo "spark://$SPARK_MASTER_IP:$SPARK_MASTER_PORT" > "$_SPARK_MASTER_NODE"
            "$SPARK_HOME/bin/spark-class" org.apache.spark.deploy.master.Master \
                --ip "$SPARK_MASTER_IP" \
                --port "$SPARK_MASTER_PORT" \
                --webui-port "$SPARK_MASTER_WEBUI_PORT"
        else
            MASTER_NODE=""
            while [ -z "$MASTER_NODE" ]; do
                sleep 1s
                if [ -f "$_SPARK_MASTER_NODE" ]; then
                    MASTER_NODE=$(<"$_SPARK_MASTER_NODE")
                fi
            done
            "$SPARK_HOME/bin/spark-class" org.apache.spark.deploy.worker.Worker "$MASTER_NODE"
        fi
    fi
    ```

Modify the parameters near the top to suit your needs:

-   the [partition](../../steps/jobs/index.md),
-   number of nodes (master plus number of workers),
-   CPUs per task (number of CPUs that can be used by each worker and
    the master), and
-   memory per CPU (default unit is megabytes, unit can be specified as `K`|`M`|`G`|`T` after the number).

You can also change the time limit, which is the time after which the
cluster is destroyed. Consult the [sbatch man page](https://slurm.schedmd.com/sbatch.html){:target=_blank} to find accepted time
formats.

Finally, you may want to change where Slurm writes output from Spark. If
you don't change the defaults in the above script, you'll find the logs
in the same directory where Spark will write its log files to.

### Starting a Spark cluster and submitting applications

Now that you have set up this batch script, you can start a cluster as
follows.

```shell
sbatch spark.cmd
# Submitted batch job <JobID>
```

Note the Slurm _JobID_; you'll need it later to work with the Spark cluster.

Monitor the status of the job by issuing `squeue -u $USER` until you see
it has started (time greater than 00:00, nodelist nonempty). You will
(soon after) find the address of the master node in the
`temp/<JobID>_spark_master` file. This can be used as follows to run an example:

```shell
module load Umbrella/2024
module load Spark
run-example --master $(<temp/<JobID>_spark_master) SparkPi 100
```

This uses a Bash construct to read the value from the file that contains
the master node address, and pass it as an argument to the `run-example`
executable. In a similar manner you can use `spark-submit` to submit
your application to the Spark cluster and monitor its status.

### Stopping a Spark cluster

Stopping the cluster is a matter of cancelling the Slurm job:
```shell
scancel <JobID>
```

### Opening the Spark web UI

If you open the `temp/<JobID>_spark_master` file, you'll see on which
node it runs. This might be `tue-computeZ042.cluster` for example.
Given that the web UI can be accessed via port 8080 on that node, you
can access it in your browser if you set up local port forwarding. When
connecting to the HPC cluster on Linux, that might look as follows:

```shell
ssh -L 8000:tue-computeB005.cm.cluster:8080 you@hpc.tue.nl
```

You will then be able to open [http://localhost:8000](http://localhost:8000){:target=_blank} in your browser to access the Spark web UI.
