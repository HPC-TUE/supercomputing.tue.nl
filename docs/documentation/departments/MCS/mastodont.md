---
title: M&CS big memory compute (mastodont)
---

# M&CS big memory compute (mastodont)

!!! info "Documentation by M&CS"

    This section of the documentation is maintained by M&CS. For suggestions
    to these pages, please contact
    [Hub MetaForum](https://tuenl.sharepoint.com/sites/intranet-mathematics-and-computer-science/SitePages/Hub-Metaforum.aspx){:target=_blank}.

## Introduction

`mastodont.win.tue.nl` is a Linux system designed to support
long-running computations that require a large amount of RAM.
It was *not* designed to support CPU-bound or parallel computations.
For such computations, please consider the [HPC cluster](hpc.md)
. The mastodont server is *not* part of a cluster.

## Documentation

### Technical specifications

| **Resource** | **Specification**                                                                                                           |
|-------------:|-----------------------------------------------------------------------------------------------------------------------------|
|          CPU | 4 x Intel(R) Xeon(R) Gold 6136 CPU @ 3.00GHz (96 processors)                                                                |
|          RAM | 3 TB (3169407968 KB)                                                                                                        |
|      Storage | swap space: 4 x 2.9 TB (SSD, equal priority, parallel)<br/>`/home`: 50 GB SSD in RAID 1<br/>`/scratch`: 33 TB HDD in RAID 6 |

### Operating system

`mastodont` runs Ubuntu Server 20.04 LTS.

For security reasons, users will not be granted `root` permissions. Software is
installed and upgraded by LIS-CSS, see also [the section below](#software).

Security updates are applied automatically every night. Reboots only
happen after communication with users, so as not to disturb long-running
processes.

### User accounts
To get access to mastodont, please contact [Hub MetaForum](https://tuenl.sharepoint.com/sites/intranet-mathematics-and-computer-science/SitePages/Hub-Metaforum.aspx){:target=_blank}
and also contact the key user of the system (see [this page](./index.md)). The
FSA cluster is the biggest consumer of the machine and can help determine
when and whether there is capacity available on the machine for your research. 

For security reasons, SSH access is only allowed from the campus or
[VPN](https://tuenl.sharepoint.com/sites/intranet-LIS/SitePages/New-VPN-Service--eduVPN.aspx){:target=_blank}. Login 
using SSH with your TU/e user name and password. It is highly recommended that you setup and use
[public key authentication](https://linuxwiki.tue.nl/wiki/SSH#SSH_Keys).

??? warning "User account names starting with a digit"

    Starting with Ubuntu 20, obstacles were raised by the service manager
    `systemd` for user names starting with a digit.
    These usernames violate the default `NAME_REGEX` on Ubuntu systems
    (`"^[a-z][-a-z0-9]*\$"`), but these usernames were already introduced at
    TU/e (as part of central IAM - *identity and access management*) before
    `systemd` introduced these obstacles.

    Relevant obstacles are mentioned below:

    * The obstacles mostly concern desktop applications that you will probably
    not use on mastodont. Such applications will complain that they cannot
    connect to the dbus.

    * In case you are working with `uid`/`gid` (for example in order to
    set the owner of a file using `chown`), this can cause some confusion.<br/>
    You can enforce interpretation as those IDs by prepending the IDs with a
    `+`. This is relevant if the `uid` overlaps with an existing username.

    * The environment variable `XDG_RUNTIME_DIR` will not be set. 
    `$XDG_RUNTIME_DIR` will normally point to the process environment directory.
    Typically, it is set to `/run/user/[uid]`, but this fails for numeric user
    IDs. This may concern applications that you do use on mastodont.<br/>
    Sometimes this can be resolved by setting this variable in your `.bashrc`.

### Disk space

All disk space is local, not shared with other systems.

!!! tip "Data transfer to/from other data solutions"
    On [this page](../../steps/data/smb-smbclient.md), some tips can be found on how to
    transfer data to and from TU/e long-term data solutions.

| **Path**           | **Storage space**             | **Purpose**                                                                                                                                                                                                                                                               |
|-------------------:|-------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `/home/[username]` | 50 GB (shared with all users) | Your home directory<br/>Mostly intended for configuration files. We do not provide a backup service, so keep your files safe elsewhere. Disk space is limited, and quota are not enforced; please be considerate of other users and keep your use as limited as possible. |
| `/scratch`         | 33 TB (shared with all users) | Scratch space for temporary files<br/>Use it for files you can afford to lose. We reserve the right to clean it up when required! There is plenty of disk space, but please be considerate of other users and regularly remove files you no longer need.                  |

!!! danger "No backup"

    There is no backup service available for home directories. Please check the
    [Storage Finder](https://storagefinder.tue.nl){:target=_blank} for
    available options to store your data for long term!

    Disk error protection is provided by the
    [RAID](https://en.wikipedia.org/wiki/RAID) levels as mentioned in the
    Hardware specifications section.
    Note that this does not protect against disk <i>controller</i> failures.

### Software
To obtain a list of available software packages and versions, please log in to
the machine and run `apt list --installed`. This list is not documented here
because of the volatile nature of a package list. However, you can expect
common software tools to be available. In case you want to know if a specific
package is available, please contact the key user (see [this page](./index.md)).

Packages from the Ubuntu repositories can be installed by submitting a request
through [TOPdesk SSP](https://tue.topdesk.net/tas/public/ssp/content/serviceflow?unid=2df9d1d0420c4e889bfa47a15370112f){:target=_blank}.
LIS-CSS will check the requested packages for security and side-effects for
other users and install them if there are no issues. Sometimes this review may
take longer, for example in case the key user or the Security Operations team
needs to be contacted.
