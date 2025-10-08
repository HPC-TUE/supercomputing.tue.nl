---
date: 2025-10-08
authors: [ e.loomeijer ]
type: kb
slug: "8"
tags: [ "Umbrella", "Knowledge Base", "Software" ]
categories: [ "Software", "Umbrella" ]
---

# How to use or install software

On HPC systems you generally **cannot use `sudo`** or install software system-wide.
Instead, software is provided via **[environment modules](../../../steps/software/index.md)** and can be extended using **EasyBuild**[^1].

---

## Using Environment Modules

--8<-- "documentation/steps/software/index.md:lmod"

[^1]: The documentation regarding EasyBuild is currently missing and will be added soon.


