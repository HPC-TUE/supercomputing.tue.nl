---
date: 2025-02-18
authors: [ e.loomeijer ]
type: kb
slug: "2"
tags: [ "Umbrella", "Knowledge Base", "SSH" ]
categories: [ "Umbrella", "SSH" ]
draft: true
---

# How can I resolve 'Host key verification failed'?

This error suggests a mismatch in known host keys.

- **Windows (MobaXterm)**: Navigate to Settings > Configuration > SSH for host key management.
- **Windows (OpenSSH), Linux, MacOS**: Edit or remove the conflicting entry in the ~/.ssh/known_hosts file. Use the
  following command to remove the host entry:
    ```shell
    ssh-keygen -R hpc.tue.nl
    ```

To verify the SSH key fingerprints from the server you can consult the following table:

--8<-- "documentation/steps/access/ssh/fingerprints.inc"
