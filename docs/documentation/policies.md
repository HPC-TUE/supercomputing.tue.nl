# Cluster Policies

Everybody who has used other computing clusters before is used to different policies.
This pages serves to make clear what ours are.

## Jobs

Please refrain from running long, highly CPU-intensive jobs directly on the login node.
If many people do this, it significantly slows down using the system for e.g. submitting jobs, copying data, etc.

## Storage

Each user has a 200 GiB disk quota and is limited to 1,000,000 files and directories maximum (see [File Systems](filesystems.md)).
The total disk space is however not enough for every user to actually use that much. Therefore:

1. Try to keep disk usage below 100GB as a general rule.
2. If your disk usage exceeds 150GB, think carefully about what can be (re)moved.
3. Make use of [scratch space](filesystems.md#scratch-file-systems).

_Your current quota usage can be checked with shell command `myquota`._

!!! danger "You are **FULLY** responsible for your own data management!"

    Please be aware that data (_**including**_ your home directory) in the HPC Cluster is **NOT** backed up!

    The HPC Cluster is not a solution for archiving your work. Please consult the [Storage Finder](https://storagefinder.tue.nl){:target=_blank}, your local hub, or your [Research IT representative](https://tuenl.sharepoint.com/sites/intranet-LIS/SitePages/Research-IT.aspx) for available options to store your data for long term!

### Disk load

Sometimes you just have to do a lot of operations on a lot of files.
This is a regularly occurring cause for poor head node performance. How do we prevent being a nuisance?

#### Bulk moving, deleting, tarring, etc. files that are in home

This is a common part of cleaning up your home directory.
It can cause overloading of the disk system regardless of measures you take, but you can still do things to prevent that.

Most importantly: Do not do this in multiple parallel threads or shells: The disk is often the bottleneck in these operations, so it will not speed things up anyway, and in fact may cause a slowdown.
And if the disk is not the bottleneck (as in some gzip operations), you are doing everyone a great favor by doing only one thread at the time because it means the chance that anyone will even notice you're doing this has gone down significantly.

#### Copying files from elsewhere on the cluster

Same as in the previous point: please do not try to do multiple SCP sessions in parallel. The chance of generating a speedup for yourself is smaller than the chance of causing trouble for others.
