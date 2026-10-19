---
date: 2026-10-19
type: news
image: &image blog/news/2026/eessi-umbrella.png
title: EESSI software stack now available on the Umbrella HPC Cluster
slug: eessi-software-stack-now-available-on-the-umbrella-hpc-cluster
hero:
  backdrop: *image
---

# EESSI software stack now available on the Umbrella HPC Cluster

**The European Environment for Scientific Software Installations (EESSI) is now available on the TU/e Umbrella HPC Cluster, giving all users access to a large, shared collection of optimized scientific software.**

<!-- more -->

[EESSI](https://www.eessi.io/) is a collaboration between European HPC partners to provide a common stack of scientific
software installations for HPC systems and beyond. The software is distributed via CVMFS and automatically selects the
build that is optimized for the CPU architecture of the node it runs on.

## Also available on other systems

EESSI is also available on the national supercomputer **Snellius** (SURF), as well as on other Dutch tier-2 sites such
as Leiden University (ALICE), the University of Groningen (Hábrók) and Vrije Universiteit Amsterdam (ADA, DAS-6).
Beyond the Netherlands, it is used on most EuroHPC systems, including LUMI, Leonardo and MareNostrum 5. This means you
can use the same software stack on Umbrella and on the systems your research may grow into, which helps to make your
workflows portable and reproducible. See the
[list of systems with EESSI](https://www.eessi.io/docs/systems/){:target=_blank} for the full overview.

## Getting started

Load the EESSI gateway module, and use the usual module commands to explore and load software:

```shell
module load EESSI/2025.06
module avail
module spider OpenFOAM
```

EESSI is available next to the existing `Umbrella` software modules, so you can keep using your current workflows.
For a full overview of the software that EESSI provides, see
[EESSI available software](https://www.eessi.io/docs/available_software/).

## More information

* [EESSI Software Modules](../../../../documentation/software/eessi.md) in the Umbrella documentation
* [Software on Umbrella](../../../../documentation/steps/software/index.md)

Questions or requests? Contact us at [supercomputing@tue.nl](mailto:supercomputing@tue.nl).
