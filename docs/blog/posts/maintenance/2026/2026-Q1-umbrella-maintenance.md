---
title: Umbrella Maintenance 2026 Q1
date: 2026-01-17
start: 2026-02-16T09:00:00
end: 2026-02-18T17:00:00
categories: [ Umbrella ]
tags: [ Maintenance ]
authors: [ a.van.hoof, e.loomeijer, a.c.m.bertens ]
type: maintenance
slug: Q1-2026-umbrella-maintenance
image: assets/images/maintenance.webp
banner:
  enabled: true
---

# 2026 Q1 Umbrella HPC Cluster maintenance

The TU/e Umbrella HPC Cluster will be undergoing scheduled maintenance, from: **Monday 16 February 2026, 09:00 CET** to
**Wednesday 18 February 2026, 17:00 CET**.

The entire cluster will be **offline** during this period. Please make sure your jobs finish before the maintenance
starts, or that they can safely be interrupted and rerun.

!!! danger ""

    _All_ running jobs on **Monday 16 February 2026 09:00** will be cancelled/killed!

<!-- more -->

!!! warning "No Backups!"

    There are **no backups** on the HPC cluster — do not use it for archiving. You are responsible for your own data management!

## Impact

### Minor impact

- Starting after the maintenance, the two login nodes will be updated and rebooted every two weeks. Long running
  processes such as tmux, screen, and VS Code Server, will be terminated on reboot, and may require restarting.
- The `pam_slurm_adopt` module will be enabled on compute nodes. SSH’ing into a compute node will work as it does now, but
  any process started through SSH will be associated with a Slurm job on that same node, and will be terminated when the
  job ends.
- Tools such as `top` and `ps` will no longer show processes from _other_ users.

## Questions?

If you encounter any issues _after_ the maintenance window, with which you would like assistance, please let us know.
We can be reached by [pe-mail](mailto:hpcsupport@tue.nl) and through
[Teams](https://teams.microsoft.com/l/team/19:7830cc8a6f244d6689a374c60673b43c%40thread.tacv2/conversations?groupId=a07b9e15-8538-4889-8610-502177c36dc7&tenantId=cc7df247-60ce-4a0f-9d75-704cf60efc64){:target=_blank}.

## Overview of changes

- Starting after the maintenance, the two login nodes will be updated and rebooted monthly. This improves security, and
  will also keep the nodes "fresh": old temporary files and orphaned processes will be cleared, leaving more resources
  available for current users.
- The [`pam_slurm_adopt`](https://slurm.schedmd.com/pam_slurm_adopt.html){:target=_blank} module will be enabled on
  compute nodes. This ensures that users will only use their allotted CPU cores, GPUs, and memory, and cannot interfere
  with other users’ jobs.
- Tools such as `top` and `ps` will no longer show processes from other users. This slightly improves security.
- Latest updates and patches to [Rocky Linux 8](https://rockylinux.org/){:target=_blank} will be installed.
- Some software (a.o. [Slurm](https://slurm.schedmd.com/){:target=_blank} and [rclone](https://rclone.org/){:target=_blank}) will be updated.
- Security fixes and firmware upgrades will be applied across all nodes and network switches, improving reliability and
  security.
