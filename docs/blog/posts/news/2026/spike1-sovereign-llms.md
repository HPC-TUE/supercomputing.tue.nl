---
date: 2026-09-02
type: news
image: &image blog/news/2026/spike1-sovereign-llms.jpg
title: Spike-1 provides SOTA sovereign LLMs access to all TU/e researchers
slug: spike-1-provides-sota-sovereign-llms-access-to-all-tue-researchers
hero:
  backdrop: *image
---

# Spike-1 provides SOTA sovereign LLMs access to all TU/e researchers

**TU/e Supercomputing Center (SCC) and EAISI now host sovereign LLMs on Spike-1 — an NVIDIA DGX B200 system owned by TU/e — and open access to all TU/e researchers over an internal API, no vendor in between.**

<!-- more -->

Every researcher can start on the light tier models (requiring less than 8 GPUs) and a weekly budget of 10M prompt tokens and 1M completion tokens, by sending an email to [supercomputing@tue.nl](mailto:supercomputing@tue.nl) and stating:

> *"I would like to get access to Spike-1 hosted LLMs for my research"*

## Currently Hosted Models

| Model | GPUs |
|:------|:-----|
| Kimi-K3 | 16 |
| GLM-5.3-FP8 | 8 |
| GLM-5.3-Flash-FP8 | 4 |
| qwen3-8-flash-next-fp8 | 2 |
| qwen3-8-27b-fp8 | 1 |

This model list updates over time, typically including Day-0 support for the latest open-weight models.

## Access to Heavier Models & Higher Budgets

If you as a researcher need access to heavier models (GLM-5.3-FP8, Kimi-K3) or a larger budget, an application can be done by sending a concise project summary to [supercomputing@tue.nl](mailto:supercomputing@tue.nl) describing:

- What you are trying to achieve
- Why it is new
- Why it requires Spike-1

An example of such an application can be provided upon request.

## Data Sovereignty & Privacy

Your prompts never leave our machines. We never store or inspect prompt or completion content: the hosted models write no prompt text to disk or logs; content lives in RAM only for the duration of the request. Your data and IP stay sovereign.

!!! warning "Experimental Service & Data Sensitivity"

    Currently, this service is experimental. Spike-1 is classified for **low/medium data sensitivity**. The LLM hosting is experimental with **no GDPR/NIS2 guarantee**. By requesting an API key, you acknowledge these risks.

*[EAISI]: Eindhoven Artificial Intelligence Systems Institute
*[SCC]: Supercomputing Center
*[LLM]: Large Language Model
*[LLMs]: Large Language Models
*[GPU]: Graphics Processing Unit
*[GPUs]: Graphics Processing Units
*[RAM]: Random Access Memory
*[SOTA]: State of the Art
