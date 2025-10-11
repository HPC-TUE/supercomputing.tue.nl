---
date: 2025-01-28
start: 2025-04-01T09:00:00
end: 2025-04-11T17:00:00
hide: [ sidebar ]
hero:
  backdrop: assets/images/2025-spring_hpc_school.png
  messages:
    - { message: "Spring HPC School '25", color: "primary" }
    - { message: "1-3 April & 7-11 April", size: "medium" }
title: Spring HPC School '25
categories: [ HPC School ]
speakers: [ g.t.chepuck.fernandes, a.van.hoof, n.sunami, v.menkovski, evertvanvlietcfd, r.ozcelik, universityracing ]
price: 0.00
location: TU/e Campus
image: assets/images/2025-spring_hpc_school_thumb.png
type: event
scheme: spring
sponsors: [ surf.nl, eurocc-netherlands.nl ]
registration:
  enabled: true
  options:
    - { title: Register Now, url: https://hpcschool2025.dryfta.com/en/attendee-registration-tickets, qr: true }
#schedule_hide: True
schedule:
  - { title: HPC Primer I, description: "An introductory guide to HPC essentials for beginners, covering remote terminal setup, bash scripting, file management, job execution with SLURM, and an overview of TU/e's Supercomputing Center.", start: 2025-04-01T09:30:00, end: 2025-04-01T15:30:00, speakers: [ g.t.chepuck.fernandes ], location: "Neuron 0.262",
      schedule: [
#        { start: 2025-04-01T09:30:00, end: 2025-04-01T12:30:00 },
        { start: 2025-04-01T12:30:00, end: 2025-04-01T13:30:00, icon: food-fork-drink, title: Lunch },
#        { start: 2025-04-01T13:30:00, end: 2025-04-01T15:30:00 },
      ]
  }
  - { title: HPC Primer II, description: "Learn about secure SSH connections, setting up Git for version control, and understanding repository licenses in day two of the HPC Primer.", start: 2025-04-02T09:30:00, end: 2025-04-02T15:30:00, speakers: [ a.van.hoof ], location: "Neuron 0.246",
      schedule: [
#        { start: 2025-04-02T09:30:00, end: 2025-04-02T12:30:00 },
        { start: 2025-04-02T12:00:00, end: 2025-04-02T13:00:00, icon: food-fork-drink, title: Lunch },
        { start: 2025-04-02T13:00:00, end: 2025-04-02T13:30:00, speakers: ["n.sunami"], title: "Licenses for Code Repository" },
#        { start: 2025-04-02T13:30:00, end: 2025-04-02T15:30:00 },
      ]
  }
  - { title: Introduction to Supercomputing & LUMI, description: "Unleash the potential of clusters, supercomputers, and LUMI—Europe's fastest—for extensive computations, AI applications, and advanced data analyses.", start: 2025-04-03T09:30:00, end: 2025-04-03T15:00:00, location: "Neuron 0.262",
      schedule: [
        { start: 2025-04-03T09:30:00, end: 2025-04-03T12:30:00, title: Introduction to Supercomputing, description: "Learn to harness the power of clusters and supercomputers for large-scale computations and analyses in this course." },
        { start: 2025-04-03T12:30:00, end: 2025-04-03T13:30:00, icon: food-fork-drink, title: Lunch },
        { start: 2025-04-03T13:30:00, end: 2025-04-03T14:30:00, title: "LUMI: pre-exascale compute facilities for TU/e researchers" },
        { start: 2025-04-03T14:30:00, end: 2025-04-03T15:00:00, speakers: ["r.ozcelik"], title: "Experiences from the first TU/e user on LUMI" },
      ]
  }
  - { title: Parallel jobs & Profiling, start: 2025-04-07T09:30:00, end: 2025-04-07T16:00:00, location: "Atlas -1.822", description: "Explore two distinct courses: one on optimizing supercomputer resource utilization through job concurrency with the QCG PilotJob framework, and another offering insights into high-performance hybrid systems with a focus on architecture, configuration, performance analysis models, and the Roofline model application.",
      schedule: [
        { start: 2025-04-07T09:30:00, end: 2025-04-07T12:30:00, title: Embarrassingly Parallel jobs },
        { start: 2025-04-07T12:30:00, end: 2025-04-07T13:30:00, icon: food-fork-drink, title: Lunch },
        { start: 2025-04-07T13:30:00, end: 2025-04-07T16:00:00, title: "Fundamentals of performance analysis" },
      ]
  }
  - { title: High Performance Machine Learning 1, start: 2025-04-08T09:30:00, end: 2025-04-08T17:00:00, location: "Neuron 0.246", description: "Engage in a two-day, hands-on course to master deep learning basics, optimize neural network models with Keras, and harness high-performance computing clusters.",
      schedule: [
#        { start: 2025-04-08T09:30:00, end: 2025-04-08T12:30:00 },
        { start: 2025-04-08T12:30:00, end: 2025-04-08T13:30:00, icon: food-fork-drink, title: Lunch },
#        { start: 2025-04-08T13:30:00, end: 2025-04-08T17:00:00 },
      ]
  }
  - { title: High Performance Machine Learning 2, start: 2025-04-09T09:30:00, end: 2025-04-09T17:00:00, location: "Neuron 0.262", description: "Enhance your deep learning efficiency by setting up a software environment, optimizing file I/O, leveraging CPU/GPU capabilities, profiling PyTorch, and utilizing parallel computing.",
      schedule: [
        { start: 2025-04-09T11:30:00, end: 2025-04-09T12:30:00, title: "Keynote: Vlado Menkovski", speakers: [ v.menkovski ] },
        { start: 2025-04-09T12:30:00, end: 2025-04-09T13:30:00, icon: food-fork-drink, title: Lunch },
#        { start: 2025-04-09T13:30:00, end: 2025-04-09T17:00:00 },
      ]
  }
  - { title: GPU computing in Python using PyCUDA, start: 2025-04-10T09:30:00, end: 2025-04-10T16:00:00, location: "Neuron 0.246", description: "Learn to leverage NVIDIA GPUs in Python using PyCUDA, from basic concepts to advanced parallel computation techniques.",
      schedule: [
#        { start: 2025-04-10T09:30:00, end: 2025-04-10T12:30:00 },
        { start: 2025-04-10T11:30:00, end: 2025-04-10T12:30:00, title: "Keynote: Evert van Vliet (ASML)", speakers: [ evertvanvlietcfd ] },
        { start: 2025-04-10T12:30:00, end: 2025-04-10T13:30:00, icon: food-fork-drink, title: Lunch },
#        { start: 2025-04-10T13:30:00, end: 2025-04-10T16:00:00 },
      ]
  }
  - { title: ParaView for (remote) visualization, start: 2025-04-11T09:30:00, end: 2025-04-11T16:30:00, location: "Neuron 0.264", description: "This course offers practical exercises and advanced topics in scientific visualization using ParaView.",
      schedule: [
#        { start: 2025-04-11T09:30:00, end: 2025-04-11T12:30:00 },
        { start: 2025-04-11T12:30:00, end: 2025-04-11T13:30:00, icon: food-fork-drink, title: "Keynote: University Racing Eindhoven (Lunch session)", speakers: [ universityracing ] },
#        { start: 2025-04-11T13:30:00, end: 2025-04-11T16:30:00 },
      ]
  }
---

# Spring HPC School

**Supercomputing at the Spring HPC School! This 2-week program is perfect for students and researchers keen to explore
the world of AI and high-performance computing. Join us for our excellent keynotes and workshops and unlock the power of
HPC.**

Be part of our free event and select tracks that match your interests. Seats are limited, so make sure to
[**register**](https://hpcschool2025.dryfta.com/en/attendee-registration-tickets){:target=_blank} quickly to secure your
spot!

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
