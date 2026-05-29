=== ":fontawesome-brands-windows: Windows"

    === ":octicons-terminal-16: MobaXterm"

        For Windows users, we recommend installing MobaXterm. Follow the steps below to download and install MobaXterm.

        1. **Visit the MobaXterm Website**

            Directly download MobaXterm from the [official website](https://mobaxterm.mobatek.net).

        2. **Select the Edition**

            The free [Home Edition](https://mobaxterm.mobatek.net/download-home-edition.html){:target=_blank} is
            generally adequate, offering a choice between a Portable Edition and an Installer Edition.

            - If uncertain, opt for the **Installer Edition** for ease of use.

    === ":material-powershell: PowerShell"

        OpenSSH should be available by default on most Windows 11 installations. For Windows 10 or if manual installation is required, refer to the [Microsoft documentation](https://learn.microsoft.com/en-us/windows-server/administration/openssh/openssh_install_firstuse?tabs=gui#install-openssh-for-windows) for further instructions.

        !!! note "Only install the "OpenSSH Client"."

            You'll only need to install the **OpenSSH Client**! Please **do not** install the "OpenSSH Server" unless you're sure it's needed.

        ??? info "GUI Applications/X11 Forwarding"

            For loading X11/GUI applications from the terminal, consider installing the following tool: [VcXsrv](https://sourceforge.net/projects/vcxsrv/){:target=_blank}

            This will facilitate GUI applications and X11 forwarding on your system.

=== ":fontawesome-brands-linux: Linux"

    No extra software is needed. SSH is usually already installed.

    Please refer to documentation of your [Linux distro](https://www.cyberciti.biz/faq/find-linux-distribution-name-version-number/){:target=_blank} if this isn't the case.

=== ":fontawesome-brands-apple: MacOS"

    You don't need to install anything extra. SSH is already set up and ready to use in the [terminal](https://support.apple.com/guide/terminal/open-or-quit-terminal-apd5265185d-f365-44cb-8b09-71a064a42125/mac){:target=_blank}.
