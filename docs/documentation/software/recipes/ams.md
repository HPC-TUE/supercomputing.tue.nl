---
title: AMS
tags: [Software, Module]
---
The [Amsterdam Modeling Suite](https://www.scm.com){:target=_blank} is used by academic and
industrial researchers in all areas of chemistry, materials science, and engineering.

## Using AMS in SLURM batch jobs<br>(Command Line Interface)

### AMS SLURM sbatch jobscript example using OpenMPI on 1 Node

```slurm

#!/bin/bash

#SBATCH --job-name=test_ams
#SBATCH --output=test_ams-%j.out 
#SBATCH --partition=tue.default.q
#SBATCH --nodes=1
#SBATCH --ntasks=16
#SBATCH --mem-per-cpu=2gb
#SBATCH --time=0-00:05:00

module purge
module load AMS/2026.101-gompi-2024a

export SCM_TMPDIR=$SLURM_TMPDIR

ls -R $AMSHOME >> /dev/null

<AMS CODE HERE>
```

On some nodes, AMS is not running due to the processor type. Adding the following option the the AMS startup command might help:

```shell
-C "amd|haswell|cascadelake|broadwell"
```

AMS [Documentation on running MPI Jobs](https://www.scm.com/doc/Installation/Additional_Information_and_Known_Issues.html#running-mpi-jobs){:target=_blank}

### `AMSJob` Python example

```python
from scm.plams import *

gr = GridRunner(parallel=True, maxjobs=16, grid='slurm')
gr.settings.special.export = '--export='

job_settings = Settings()
job_settings.runscript.preamble_lines = [
    'export SCM_TMPDIR=$SLURM_TMPDIR',
]

job = AMSJob(..., settings=job_settings)
job.run(jobrunner=gr, queue='myqueue.q', cores=16, nodes=1, C="amd|cascadelake|broadwell")
job.ok()
```
