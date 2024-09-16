---
title: File systems
hide:
  - toc
---

# File systems

[TOC]

## Overview

<table>
  <tr>
    <th>File system</th>
    <th>Quota (space)</th>
    <th>Quota (files)</th>
    <th>Speed</th>
    <th>Shared between nodes</th>
    <th>Path</th>
    <th>Expiration</th>
    <th>Backup</th>
    <th>Notes</th>
  </tr>
  <tr>
    <td>Home</td>
    <td>200 GiB<sup>1</sup></td>
    <td>1,000,000<sup>1</sup></td>
    <td>Fast<sup>1</sup></td>
    <td>Yes</td>
    <td><code>/home/&lt;login_name&gt;</code></td>
    <td>To be decided</td>
    <td style="color: red; font-weight:bold;">No backup</td>
    <td>&mdash;</td>
  </tr>
  <tr>
    <td>Scratch-shared</td>
    <td>8 TiB</td>
    <td>3,000,000</td>
    <td>Fast</td>
    <td>Yes</td>
    <td><code>/scratch-shared/&lt;login_name&gt;</code></td>
    <td>Files older than <b>14 days</b> are automatically removed</td>
    <td style="color: red; font-weight:bold;">No backup</td>
    <td>&mdash;</td>
  </tr>
  <tr>
    <td>Scratch-node</td>
    <td>&mdash;</td>
    <td>&mdash;</td>
    <td>Very fast</td>
    <td>No</td>
    <td><code>$TMPDIR</code> (and <code>/scratch-node</code>)</td>
    <td>Data is cleaned at irregular intervals</td>
    <td style="color: red; font-weight:bold;">No backup</td>
    <td>Size varies per node</td>
  </tr>
  <tr>
    <td>Project</td>
    <td colspan="3" style="text-align:center;">&mdash;Varies per project&mdash;</td>
    <td>Yes</td>
    <td><code>/project/&lt;project_name&gt;</code></td>
    <td>Varies per project</td>
    <td style="color: red; font-weight:bold;">No backup</td>
    <td>&mdash;</td>
  </tr>
</table>

<small>1. Shown values are default values.  For a number of reasons, some home directories may have different quota, and may reside on slower storage.</small>

## Home directories

!!! warning "No backup"

    There is no backup service available for home directories. Please check the [Storage Finder](https://storagefinder.tue.nl){:target=_blank} for available options to store your data for long term!

Every user has their own home directory, which is accessible at <code>/home/&lt;login_name&gt;</code>.

**Your home directory has default capacity quota of 200 GiB. The default inode quota is 1,000,000.**  To see your current quota usage, run the `myquota` command.

Most home directories reside on fast (NVMe) storage. Some, however, may reside on slower (spinning disk) storage.

The 200 GiB home directory is ample space for a work environment on the system for most users. If you think that it is not sufficient to accommodate your work environment on the Umbrella Cluster, you can request extra storage space (project space). Think of your home directory as the basis for arranging the work environment for your current computational project on the Umbrella Cluster.  Note, however, that home directories are not intended for long term storage of large data sets. For this purpose, the HPC Lab recommends using other (external) storages, such as the TU/e NetApp or SURF Research Drive. Please consult the [Storage Finder](https://storagefinder.tue.nl){:target=_blank}, your local hub, or your [Research IT representative](https://tuenl.sharepoint.com/sites/intranet-LIS/SitePages/Research-IT.aspx) for available options to store your data for long term!

## Scratch file systems

The scratch file systems are intended as fast temporary storage that can be used while running a job, and can be accessed by all users with a valid account on the system.  There are several different types of scratch available on the Umbrella Cluster, as listed in the table above. Below, we describe them in detail, including any active quota and backup policies.

### Scratch-shared

!!! warning "Automatic cleanup and no backup"

    For scratch-shared there is an automated expiration policy of 14 days.  Files and directories that are older, i.e. haven't been modified in the past 14 days, are automatically deleted.

    There is no backup service for scratch-shared.

Scratch-shared can be accessed at <code>/scratch-shared/&lt;login_name&gt;</code>.  It resides on fast (NVMe) networked storage.  Each user can store **up to 8 TiB and 3,000,000 files**.  Files are automatically deleted 14 days after they've been last modified.

### Scratch-node

!!! warning "Irregular cleanup and no backup"

    For scratch-node there is an irregular expiration policy.  Files and directories are removed irregularly and unannounced.

    There is no backup service for scratch-shared.

Scratch-node can be accessed at <code>$TMPDIR</code> (will be removed after job) and <code>/scratch-node</code> (cleaned up irregularly).  It resides on fast (NVMe) local storage, that is attached directly to the compute node's CPU.  The size of this file system differs per node.

## Project spaces

!!! warning "No backup"

    There is no backup service for project spaces.  Please check the [Storage Finder](https://storagefinder.tue.nl){:target=_blank} for available options to store your data for long term!

A project space can be used when:

- you need additional storage space, but do not require a backup; or
- you need to share files within a collaboration.

Project spaces are accessible at <code>/project/&lt;project_name&gt;</code>.  They can reside on fast storage (NVMe) or slow (spinning disk) storage, and have project-dependent quota for space and number of files.  (Current quota usage can be seen using the `myquota` command.)  By default accounts on our systems are not provisioned with a project space. Project spaces can be requested separately, through the [web form](https://tue.topdesk.net/tas/public/ssp/content/serviceflow?unid=f950a580c8e34a7abb7d37d102c788e8){:target=_blank}.

Project spaces are not intended for long term storage of large data sets. For this purpose, the HPC Lab recommends using other (external) storages, such as the TU/e NetApp or SURF Research Drive. Please consult the [Storage Finder](https://storagefinder.tue.nl){:target=_blank}, your local hub, or your [Research IT representative](https://tuenl.sharepoint.com/sites/intranet-LIS/SitePages/Research-IT.aspx) for available options to store your data for long term!
