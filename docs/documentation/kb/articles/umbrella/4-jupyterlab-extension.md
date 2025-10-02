---
date: 2025-02-18
authors: [ e.loomeijer ]
type: kb
slug: "4"
tags: [ "Umbrella", "Knowledge Base", "Software", "Jupyter" ]
categories: [ "Jupyter", "Software", "Umbrella" ]
---

# Troubleshooting JupyterLab: Removing Problematic Extensions

## Problem

**Issue:** After installing an extension, JupyterLab is no longer functioning correctly.

## Solution

To resolve this issue, you can remove all installed JupyterLab extensions. This can be done by accessing your system via
SSH or using the terminal in Open OnDemand.

## Steps to Remove Extensions

1. **Access Your System:**
    - **SSH:** Use an SSH client to log into your system.
    - **Open OnDemand:** Navigate to the terminal feature.

2. **Execute the Command:**
    - Run the following command to remove all JupyterLab extensions:

      ```shell
      rm -rf $HOME/.local/share/jupyter/labextensions
      ```

   This command deletes the directory where JupyterLab extensions are stored, effectively removing all installed
   extensions.

## Considerations

- **Backup:** Before executing the command, consider backing up your data.
- **Reinstallation:** After removing extensions, you may need to reinstall necessary and compatible extensions.
- **Compatibility:** Ensure extensions are compatible with your JupyterLab version before reinstalling.

## Conclusion

Removing extensions can quickly resolve issues caused by incompatible or faulty extensions. Always verify compatibility
before installing extensions to prevent future issues. If problems persist, further investigation into specific error
logs may be necessary.
