---
title: Umbrella Maintenance 2026 Q3
date: 2026-07-21
start: 2026-08-24T09:00:00
end: 2026-08-28T17:00:00
categories: [ Umbrella ]
tags: [ Maintenance ]
authors: [ a.van.hoof, e.loomeijer, a.c.m.bertens ]
type: maintenance
slug: Q3-2026-umbrella-maintenance
image: assets/images/maintenance.webp
banner:
  enabled: true
---

# 2026 Q3 Umbrella HPC Cluster maintenance

The TU/e Umbrella HPC Cluster will be undergoing scheduled maintenance, from: **Monday 24 August 2026, 09:00 CET** to
**Friday 28 August 2026, 17:00 CET**.

The entire cluster will be **offline** during this period. Please make sure your jobs finish before the maintenance
starts, or that they can safely be interrupted and rerun.

!!! danger ""

    _All_ running jobs on **Monday 24 August 2026 09:00** will be cancelled/killed!

<!-- more -->

!!! warning "No Backups!"

    There are **no backups** on the HPC cluster — do not use it for archiving. You are responsible for your own data management!

## Impact

### New features

-  Introduction of the [EESSI software stack](https://www.eessi.io/). To see what software EESSI provides, please use ```module load EESSI/2025.06```, followed by ```module list```.

### Major impact: Overhaul of software / environment modules

- All modules will be made accessible through so-called gateway modules, which must be loaded before loading other modules. For example:

  * ```module load Umbrella/2024```
  * ```module load EESSI/2025.06```
  * Remember that module names are case sensitive!

These so-called gateway modules will make it easier to deprecate old software and to clearly communicate about this.

- Many old software modules will be removed. The full list can be found [here](https://supercomputing.tue.nl/maintenance/umbrella/old-modules/). (This list coincides with everything in ```/cm/shared```.) If you use any of these modules, please use newer versions instead. If a newer version is not installed, please let us know, and we’ll try to install it.

- The remaining software will be accessible through the ```Umbrella/2024``` module. This module is deprecated. It, and all modules accessible through it, will remain available for another half year, after which it will be removed.

- New software will be installed under the ```Umbrella/2026``` module.

- All software installed in ```/cm/shared/...``` will be removed. If you use anything installed in ```/cm/shared```, please note that using hardcoded paths is not supported. Please use use the [module system](https://supercomputing.tue.nl/documentation/steps/software/) instead.

### Major impact: loaded modules will no longer carry over to sbatch

- Please ensure that you start your job scripts with
  * ```module purge```
  * ```module load Module(s)/that.you.need```
  * ```source .venv/bin/activate (if needed)```
  * ```conda activate (if needed)```
  * ```...```

- Any environment variables set before running sbatch will no longer be carried into your jobs. This also applies to loaded modules, activated conda envs, etc.
- Any environment variables (and modules, conda envs, etc.) defined in your ```.bashrc``` will still take effect.
- This change forces you to run ```module load``` from within jobs. This, in turn, allows module load to determine the job’s node’s architecture, and load software appropriate for that architecture. In particular for newer nodes this will noticably speed up computations.

### Minor impact

- Slurm will automatically requeue jobs if a node fails. This is Slurm’s default. It had been temporarily disabled a while ago, because it caused unexpected behaviour. Long-running jobs should take care not to delete checkpoints if it gets requeued. Auto-requeuing can be disabled with ```#SBATCH --no-requeue``.
- Access to ```/local``` will be prohibited. Please use ```$TMPDIR```, or if that is not possible, ```/scratch-node```. Please see our [file systems documentation](https://supercomputing.tue.nl/documentation/filesystems/#scratch-node) for more info about ```$TMPDIR``` and ```/scratch-node```.
- Slurm’s GPU autodetection will be enabled. This may cause Slurm’s GPU names to change. If you were using something like ```--gpus=rtx2080ti.11gb:1```, i.e. if you were specifying a GPU type, you may need to change the GPU type. To see what GPU types are available on a node, run ```scontrol show node <node name>```, and look for a line that starts with ```Gres=```.
- The cluster will be upgraded from [Rocky Linux](https://rockylinux.org/) 8 to Rocky Linux 9. Self-compiled software may break, in which case you’ll need to recompile it. Some centrally installed software may break; if this happens, please let us know, so we can reinstall it.
- The central cluster storage system (VAST DATA) will be switched from NFSv4 to NFSv3. This should increase metadata performance by 10x. In rare cases file locks may not be released correctly, and issues may occur when deleting files/directory trees that are still being accessed.
- User accounts with expiry periods >1 year will be reset to 1 year. By requiring accounts to be renewed yearly, we can keep the cluster from cluttering up with old accounts. We understand this is an inconvenience, and we are looking into alternatives.
- Due to the OS upgrade, SSH host keys may change. Your SSH client may warn you about this. If you encounter this, please remove the old host keys and accept the new ones. We publish our key fingerprints [here](https://supercomputing.tue.nl/documentation/steps/access/ssh/). 

### No expected impact

- ```module load gcc``` is old and serves no purpose; we will remove it from your ```.bashrc```.
- The cluster’s connection to TU/e will be changed from 2× 10Gbit to 2× 100Gbit.
- The cluster will be upgraded from [Slurm](https://slurm.schedmd.com/) 23.11 to Slurm 25.11.
- Some other software (a.o. [rclone](https://rclone.org/)) will be updated.
- Security fixes and firmware upgrades will be applied across all nodes and network switches, improving reliability and security.

## Questions?

If you encounter any issues _after_ the maintenance window, with which you would like assistance, please let us know.
We can be reached by [e-mail](mailto:hpcsupport@tue.nl) and through
[Teams](https://teams.microsoft.com/l/team/19:7830cc8a6f244d6689a374c60673b43c%40thread.tacv2/conversations?groupId=a07b9e15-8538-4889-8610-502177c36dc7&tenantId=cc7df247-60ce-4a0f-9d75-704cf60efc64){:target=_blank}.
