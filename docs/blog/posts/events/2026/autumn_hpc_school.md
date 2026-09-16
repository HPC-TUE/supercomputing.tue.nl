---
date: 2026-09-15
start: 2026-09-29T10:00:00
end: 2026-10-09T16:30:00
hide: [ sidebar ]
hero:
  backdrop: blog/events/2026/autumn_hpc_school.png
  messages:
    - { message: "Autumn HPC School '26", color: "primary" }
    - { message: "29 September - 9 October", size: "medium" }
title: Autumn HPC School '26
categories: [ HPC School ]
speakers: [ g.t.chepuck.fernandes, a.van.hoof, a.knupfer, nxp, a.kashkanova, j.delpozomellado, a.torres, m.moller, s.dolas, a.c.m.bertens ]
price: 0.00
location: TU/e Campus
image: blog/events/2026/autumn_hpc_school_thumb.png
type: event
scheme: autumn
sponsors: [ surf.nl, eurocc-netherlands.nl, eurohpc-ju, datalad, sc-brabant ]
registration:
  enabled: true
  options:
    - { title: Register Now, url: https://hpc.copernica.tue.nl/HPC_Autumn_2026_subscribe, qr: true }
#schedule_hide: True
schedule:
  - { title: "HPC Primer - 1", description: "An introductory guide to HPC essentials for beginners, covering remote terminal setup, bash scripting, file management, job execution with SLURM, and an overview of TU/e's Supercomputing Center.", start: 2026-09-29T10:00:00, end: 2026-09-29T14:00:00, speakers: [ g.t.chepuck.fernandes ] }
  - { title: "HPC Primer - 2 (inc. RDM for HPC workflows)", description: "Covers SSH connections & keys, using git version control on a supercomputer, and the fundamentals of Research Data Management (RDM) applied to supercomputing.", start: 2026-09-30T10:00:00, end: 2026-09-30T14:00:00, speakers: [ a.van.hoof ],
      schedule: [
        { start: 2026-09-30T10:00:00, end: 2026-09-30T12:00:00, title: "Git for HPC workflows" },
        { start: 2026-09-30T12:30:00, end: 2026-09-30T14:00:00, title: "Research Data Management (RDM) for HPC workflows" },
      ]
  }
  - { title: "Intro. to Supercomputing, File Systems & LUMI", description: "Understand what high-performance computing is, learn the basics of clusters and supercomputers, get hands-on with the national supercomputer Snellius, and learn how to choose the right file system for the job.", start: 2026-10-01T10:00:00, end: 2026-10-01T17:00:00 }
  - { title: "Eindhoven Quantum Computing Workshop", description: "A multidisciplinary workshop addressing the emerging field of Quantum Computing: what it is, what it is not, and how it relates to Supercomputing/HPC. Participants gain a broad overview and insight into Quantum Computing, plus hands-on experience with current Quantum algorithms.", start: 2026-10-02T09:30:00, end: 2026-10-02T17:30:00,
      schedule: [
        { start: 2026-10-02T09:30:00, end: 2026-10-02T10:15:00, title: "Quantum 101", speakers: [ j.delpozomellado ] },
        { start: 2026-10-02T10:15:00, end: 2026-10-02T10:45:00, title: "Quantum @ SURF", speakers: [ a.torres ] },
        { start: 2026-10-02T11:00:00, end: 2026-10-02T11:30:00, title: "Quantum & CFD", speakers: [ m.moller ] },
        { start: 2026-10-02T11:30:00, end: 2026-10-02T12:15:00, title: "Panel Discussion: Quantum Hype?", speakers: [ s.dolas ] },
        { start: 2026-10-02T13:15:00, end: 2026-10-02T16:00:00, title: "Hands on Quantum Computing with Quantum Inspire", speakers: [ a.c.m.bertens ] },
        { start: 2026-10-02T16:00:00, end: 2026-10-02T16:30:00, title: "CQT Quantum Lab Tour" },
        { start: 2026-10-02T16:30:00, end: 2026-10-02T17:30:00, icon: glass-cocktail, title: "Networking Drinks" },
      ]
  }
  - { title: "Massively Parallel Job Submission & HPC Efficiency", start: 2026-10-05T10:00:00, end: 2026-10-05T16:00:00, description: "Learn how to efficiently run large numbers of independent jobs using SLURM arrays and QCG-PilotJob, followed by a session on monitoring energy and performance with the EAR dashboard.",
      schedule: [
        { start: 2026-10-05T10:00:00, end: 2026-10-05T12:30:00, title: "Massively Parallel Job Submission on Supercomputers" },
        { start: 2026-10-05T13:15:00, end: 2026-10-05T16:00:00, title: "HPC Efficiency: Profiling, EAR dashboard" },
      ]
  }
  - { title: "Large-Scale Data Version Control for HPC with Git and DataLad", description: "Learn how to version control research data with git and DataLad, including large binary files, collaborate through a git forge, and add machine-actionable reproducibility to your HPC workflows on Slurm.", start: 2026-10-06T09:30:00, end: 2026-10-06T16:00:00, speakers: [ a.knupfer ] }
  - { title: "GPU Computing 1 & 2", description: "An introduction to parallel computing architectures and GPU programming with Python, using Numba and PyCUDA on Snellius' Nvidia A100 and H100 GPUs.", start: 2026-10-07T09:30:00, end: 2026-10-07T16:00:00,
      schedule: [
        { start: 2026-10-07T11:30:00, end: 2026-10-07T12:15:00, icon: presentation, title: "Keynote: NXP", speakers: [ nxp ] },
      ]
  }
  - { title: "High-Performance Deep-Learning", description: "Enhance your deep learning efficiency by setting up a software environment, optimizing file I/O, leveraging CPU/GPU capabilities, profiling PyTorch, and utilizing parallel computing.", start: 2026-10-08T09:30:00, end: 2026-10-08T16:00:00,
      schedule: [
        { start: 2026-10-08T11:30:00, end: 2026-10-08T12:15:00, icon: presentation, title: "Keynote: Anna Kashkanova (TU/e)", speakers: [ a.kashkanova ] },
      ]
  }
  - { title: "Visualization with (Remote) Paraview & Blender", start: 2026-10-09T09:30:00, end: 2026-10-09T16:30:00, description: "Get to know the fundamentals of scientific visualisation using ParaView's 3D data manipulation model and pipelines, followed by an introduction to producing attractive images and animations from 3D scientific data using Blender.",
      schedule: [
        { start: 2026-10-09T09:30:00, end: 2026-10-09T12:30:00, title: "Visualization with (Remote) Paraview" },
        { start: 2026-10-09T13:30:00, end: 2026-10-09T16:30:00, title: "Scientific Visualisation with Blender: Data, Lights, Camera, Action! (introduction)" },
      ]
  }
---

# Autumn HPC School

**Supercomputing at the Autumn HPC School! This 2-week program is perfect for students and researchers keen to explore
the world of AI, quantum computing, and high-performance computing. Join us for our excellent keynotes and workshops
and unlock the power of HPC.**

Be part of our free event and select tracks that match your interests. Seats are limited, so make sure to
[**register**](https://hpc.copernica.tue.nl/HPC_Autumn_2026_subscribe){:target=_blank} quickly to secure your
spot! For the latest information, including up-to-date session locations, always check
[hpc-training.nl](https://hpc-training.nl){:target=_blank}, and see [quantumeindhoven.nl](https://quantumeindhoven.nl){:target=_blank}
for the dedicated Eindhoven Quantum Computing Workshop embedded within the school.

This HPC School is made possible through the collaboration between the [TU/e Supercomputing Center](https://www.linkedin.com/in/supercomputing/){:target=_blank}, [SURF](https://www.surf.nl){:target=_blank}, & [EuroCC Netherlands](https://eurocc-netherlands.nl/nl/){:target=_blank}.

<!-- more -->

Participants will have the opportunity to engage with leading experts in the field, gaining insight into the latest
advancements and methodologies in supercomputing. The program is designed to be both comprehensive and accessible,
ensuring that attendees of various experience levels can benefit fully from the sessions.

In addition to the structured workshops, there will be networking opportunities where attendees can connect with peers
and industry leaders. This is an excellent chance to discuss potential collaborative projects, share ideas, and build
relationships within the HPC community.

Don't miss out on this incredible opportunity to advance your knowledge and skills in AI and high-performance computing.
Secure your spot today and be part of a transformative experience that will enhance your research and career potential
in the field of supercomputing.

!!! quote ""

    For questions or feedback about the HPC school, including reservations, email us at
    [hpc-training@tue.nl](mailto:hpc-training@tue.nl)!
