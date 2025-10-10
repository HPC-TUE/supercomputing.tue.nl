---
date: 2025-10-10
authors: [ h.zhang ]
type: news
image: &image blog/news/2025/spike1-open-for-research.png
title: SPIKE-1 is now open to general research
hero:
  backdrop: *image
---

# SPIKE-1 is now open to general research

**As you [may have read](../2024/2024-11-04_nvidia-dgx-superpod.md) before, TU/e is one of the first universities to have access to the NVIDIA DGX B200 system.
The cluster has been tested by different groups and is now _open to all TU/e researcher’s proposal for access_.**

Different departments have invested different amounts proportionally, thus researchers can use the system based on their
department quota. For funded research (e.g. NWO/EU), it is also possible to use more GPUs using a pay-per-hour model. If
you are interested and want to know more, please fill the [SPIKE-1 project proposal](https://tue.topdesk.net/tas/public/ssp/content/serviceflow?unid=778f3ed6a17e4d419e300e26fc925e39){:target=_blank} or send an email to
[supercomputing@tue.nl](mailto:supercomputing@tue.nl).

<!-- more -->

SPIKE-1 has five unique features compared to other HPC facilities:

- FP4 native hardware support
- NVLink & InfiniBand for large scale training
- Run:ai Container orchestration
- GPU Direct Storage
- Integrated with NVIDIA NGC ecosystem

For researchers, SPIKE-1 is ideal if you have the need for:

- FP4 research; or
- Large scale training needs (multi-GPU/multi-nodes); or
- Large VRAM (e.g. training foundation models)

## What is SPIKE-1

**SPIKE-1** is a modular AI supercomputer from Nvidia. TU/e Supercomputing Center installed the first batch of 4 (DGX B200) systems early 2025.
The system is hosted in a datacenter in Kajaani (Finland). At the moment Proof of concepts are running on the system.

- **'State of the art'**: With the newest Nvidia ‘Blackwell’ Technology (DGX B200)
- The GPU’s will be **renewed every 2-3 years**, so It will **STAY ‘state of the art’**
- Placed in **Finland**, in a green datacenter

### Technical details

#### Hardware

4x [DGX B200](https://www.nvidia.com/en-us/data-center/dgx-b200/){:target=_blank} nodes available with each:

- 8x Nvidia ‘Blackwell’ B200 GPUs
- 1.53 TB VRAM (~196 GB per GPU)
- 2x 112 CPU core Intel Platinum 8570
- 2.16 TB RAM

#### Software

- Code runs in containers that can have a certain number of GPUs assigned
- NVIDIA AI Enterprise software

Please note that this is different from how most other HPC systems work (TU/e HPC Umbrella and Snellius both use Slurm
for job scheduling). Some experience with building container images is recommended.
