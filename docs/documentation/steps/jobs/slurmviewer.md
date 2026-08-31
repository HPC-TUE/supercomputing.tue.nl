# Slurm Viewer

Slurm Viewer^[:fontawesome-brands-git:](https://gitlab.com/lkeb/slurm_viewer){:target=_blank}^ (**slurm-viewer**) is a Graphical Command Line
Interface to the Slurm Scheduler. View the status of a SLURM cluster, including nodes and partitions/queues. It is
available as a [module](../../steps/software/index.md) on the login node and needs initialization once.

Load the module

```shell
[user@umbrella]$ module load Umbrella/2024
[user@umbrella]$ module load SlurmViewer
```

Start SlurmViewer

```shell
[user@umbrella]$ slurm-viewer
```
The interface can be used with a mouse (it's clickable)

![SlurmViewerExample](SlurmViewerExample.png)


