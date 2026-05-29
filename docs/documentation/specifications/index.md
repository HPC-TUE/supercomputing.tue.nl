# Technical Specifications

!!! quote inline end ""

    |                       | Software Stack                                               |
    |----------------------:|--------------------------------------------------------------|
    |      Operating System | :simple-rockylinux: [Rocky Linux 8](https://rockylinux.org/) |
    |    Cluster Management | [TrinityX](https://github.com/clustervision/trinityX)        |
    |         Module System | [Lmod](https://lmod.readthedocs.io/en/latest/)               |
    | Software Build System | [EasyBuild](https://docs.easybuild.io/)                      |
    |     Remote Web Access | [Open Ondemand](https://openondemand.org/)                   |

## Partition/Queues

Depending on your department/research group, you can get access to
certain parts (partitions/queues) of the TU/e Umbrella HPC Cluster.
The tables below list the specifications of the clusters per department.
In case you are not a part of the below-mentioned departments, and you
still would like to compute, you can use the [generic nodes](#generic-nodes).

To find out which cluster partition(s)/queue(s) you have access to,
issue the `sinfo` command without parameters on a login node. It will
print out a list of partitions (queues) you have access
to.

Read how to select these clusters, or even specific nodes within them,
in the [Submit Jobs](../steps/jobs/index.md) tutorial.

## Hardware

### Generic Nodes

Generic computing nodes are freely available to everyone with a TU/e account. These shared resources provide easy access
to high-performance computing capabilities, enabling users from any discipline to carry out a wide range of
computational tasks.

--8<-- "tue.inc"

### Departmental Nodes

Departmental computing nodes are reserved for specific departments or research groups within TU/e. Access to these
resources is restricted, and in cases where nodes are allocated to smaller groups, explicit approval from the queue
owner is required. These nodes are intended to support more specialized or intensive computational tasks aligned with
departmental research priorities.

=== "APSE"

    --8<-- "phys.inc"

=== "BE"

    --8<-- "be.inc"

=== "BmE"

    --8<-- "bme.inc"

=== "CE&C"

    --8<-- "chem.inc"

=== "EE"

    --8<-- "ee.inc"

=== "ID"

    --8<-- "id.inc"

=== "M&CS"

    --8<-- "mcs.inc"

=== "ME"

    --8<-- "mech.inc"

=== "MaTe"

    --8<-- "mate.inc"

#### Investment Options

[This](configs/2024.md) is a proposal for standard node
configurations. In what form this will be implemented, **if at all**, is not
known yet.

*[MIG]: Multi-Instance GPU
*[HT]: Hyper Threading enabled
*[SMT]: Simultaneous Multi-Threading enabled
*[APSE]: Applied Physics & Science Education
*[BmE]: Biomedical Engineering
*[BE]: Built Environment
*[CE&C]: Chemical Engineering & Chemistry
*[EE]: Electrical Engineering
*[ID]: Industrial Design
*[IE&IS]: Industrial Engineering & Innovation Sciences
*[M&CS]: Mathematics & Computer Science
*[ME]: Mechanical Engineering
