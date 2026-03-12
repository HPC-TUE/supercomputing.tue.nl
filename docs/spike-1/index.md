---
title: Spike-1
---

# Spike-1 GPU Cluster

Spike-1 is a high-performance GPU computing platform at TU/e, built on NVIDIA DGX infrastructure. It is designed for AI/ML workloads, large-scale deep learning, and GPU-accelerated research across multiple departments.

## Technical Specifications

|                         | Details                                                                                    |
|------------------------:|--------------------------------------------------------------------------------------------|
|                Platform | [NVIDIA DGX B200](https://www.nvidia.com/en-us/data-center/dgx-platform/){:target=_blank} |
|                   Nodes | 4x DGX B200                                                                               |
|                    GPUs | 32x NVIDIA B200                                                                            |
|                 Storage | 250 TB high-performance [DDN](https://www.ddn.com/){:target=_blank} storage                |
|                 Interconnect | NVLink Infiniband.                                                                    |
|        Workload Manager | [Run:AI](https://www.run.ai/){:target=_blank}                                             |
|        Containerization | [Docker](https://www.docker.com/){:target=_blank}                                         |
|      Container Registry | [Harbor](https://goharbor.io/){:target=_blank}                                            |
|        Software License | [NVIDIA AI Enterprise](https://www.nvidia.com/en-us/data-center/products/ai-enterprise/){:target=_blank} (full license) |
|              Access URL | [spike.run.ai](https://spike.run.ai){:target=_blank}                                      |

!!! note "Container-Based Workflows"

    Spike-1 uses **Run:AI** as its workload scheduling and orchestration layer on top of the DGX hardware. All workloads run inside **Docker containers**, providing reproducible and isolated environments for research computing. Users submit jobs through Run:AI, which manages GPU allocation and scheduling across the cluster.

## Associated Departments

Spike-1 is a shared resource across the following TU/e departments and institutes:

| Abbreviation | Department / Institute                              |
|-------------:|-----------------------------------------------------|
|        EAISI | Eindhoven Artificial Intelligence Systems Institute |
|         M&CS | Mathematics & Computer Science                      |
|           EE | Electrical Engineering                              |
|          BME | Biomedical Engineering                              |
|           ME | Mechanical Engineering                              |
|           ID | Industrial Design                                   |
|           CE | Chemical Engineering & Chemistry                                   |
|           IEIS | Industrial Design & Innovation Sciences                       |
|           EHCI | Eindhovense Hendrik Casimir Instituut                     |


## How to Apply

To request access to Spike-1, submit an application through the [Topdesk service request form](https://tue.topdesk.net/tas/public/ssp/content/serviceflow?unid=c038bd02-3508-4b7e-a09f-c96bed805387){:target=_blank}. Access is available to researchers and students affiliated with the associated departments listed above. You can also use the [Research Cockpit](https://PLACEHOLDER_RESEARCH_COCKPIT_URL){:target=_blank} to explore your project context and available resources.

### Is Spike-1 the right fit for your project?

Spike-1 is the most powerful GPU system at TU/e — think of it as the F1-car of our HPC landscape. It is designed for research workloads that genuinely benefit from cutting-edge GPU hardware, large-scale distributed training, or the NVIDIA AI Enterprise software ecosystem.

Not every GPU workload needs this level of compute. If your project runs comfortably on a single GPU or does not require the specific capabilities below, [Snellius](https://www.surf.nl/en/services/snellius-the-national-supercomputer){:target=_blank} may be a better starting point.

The following are **examples** of what Spike-1 excels at — your project does not need to tick every box:

- Large-scale distributed training across multiple GPUs or nodes
- Workloads that benefit from very large vRAM capacity
- Use of NVIDIA driver-level FP4 precision (Blackwell architecture)
- Leveraging the NVIDIA AI Enterprise software stack
- GPU Direct Storage for high-throughput data pipelines
- Container-based (Docker) research workflows
- Training runs that exceed the capacity or time limits of Umbrella or Snellius

If you are unsure whether Spike-1 is the right fit, don't hesitate to reach out — we are happy to discuss your project and help you find the best platform.

!!! warning "Important"

    Access to Spike-1 is granted for a defined access window. All access, data, and workloads will be **deleted** after the access window ends. Please plan the long-term storage with your DMP.

## Support & Collaboration

The Supercomputing Center is TU/e's **Center of Excellence** for high-performance AI computing. Our AI engineers don't just provide support — we are excited to collaborate with you on your research.

We are here to **teach** you how to get the most out of Spike-1, from containerized workflows and distributed training to optimizing GPU utilization. Equally, we are here to **learn** from your research challenges, so we can continuously improve the platform and our expertise.

Whether you are new to container-based workflows or an experienced HPC user, we work alongside you during onboarding and throughout the duration of your project. No question is too small, no challenge too big.

Don't hesitate to reach out to the [Supercomputing Center](https://tue.topdesk.net/tas/public/ssp/content/detail/service?unid=eb5df64a462d462da58051df1095be64){:target=_blank} for any questions.

## Data & Security Restrictions

Spike-1 follows the same security standards as Snellius. This means the following types of data and workloads **cannot** be processed on the cluster:

- **Non-anonymized or non-pseudonymized personal data** — all personal data must be properly anonymized or pseudonymized before it is used on Spike-1.
- **Direct user data processing** — Spike-1 is not designed to process live or direct end-user data.
- **Data classifications** — Anything above high sensitivity.

For full information about data classification, handling requirements, and what is permitted, please consult your **data steward**.

*[EAISI]: Eindhoven Artificial Intelligence Systems Institute
*[M&CS]: Mathematics & Computer Science
*[BME]: Biomedical Engineering
*[EE]: Electrical Engineering
*[ME]: Mechanical Engineering
*[ID]: Industrial Design
*[CE]: Chemical Engineering & Chemistry
*[IEIS]: Industrial Design & Innovation Sciences
*[EHCI]: Eindhovense Hendrik Casimir Instituut
