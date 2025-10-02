=== ":fontawesome-brands-windows: Windows"

    === ":octicons-terminal-16: MobaXterm"

        1. **Launch MobaXterm**:

            Open MobaXterm by double-clicking its icon on your desktop or finding it in your Start menu, or by continuing with an existing session if one is already open.

        2. **Start a New SSH Session**:

            To initiate a new SSH session, click on the `Session` icon in the top left corner of the MobaXterm window. In the session settings window, select `SSH`.

        3. **Configure Your SSH Settings**:

            In the SSH session configuration, fill in the following details:

            - **Remote host**: Enter `hpc.tue.nl`.
            - **Specify username**: Enter your SSH username, e.g., `s133320`.
            - **Port**: Leave this set to `22`, the default SSH port.

            If you have a private key for authentication, check the box for `Use private key` and browse to the key file location, typically `C:\Users\yourusername\.ssh\id_rsa`.  Note that this only works if you have manually added this key your HPC account's `.ssh/authorized_keys` file.

        4. **Save and Start the Session**:

            Click `OK` to save the session settings and connect to the server. MobaXterm will attempt to establish a connection.

        5. **Verify the Connection**:

            On your first connection, you'll be prompted to verify the server's authenticity. You'll see a message like this:

            ```
            The server's host key is unknown. Do you trust this host key?
            ```

            Choose `Yes` to add the server's fingerprint to the known hosts, allowing future connections without prompts.

        6. **Access the Server**:

            After a successful connection, you will have access to the server's command line interface in the terminal tab that opens, where you can execute commands.

        7. **Close the SSH Session**:

            To disconnect from the server, simply close the terminal tab or exit MobaXterm. This action will end the SSH session.

        By following these steps, you'll be able to securely connect to `hpc.tue.nl` using MobaXterm on Windows with your SSH key, enhancing security by avoiding password entry for each login.

    === ":material-powershell: PowerShell"

        1. **Open PowerShell or Command Prompt**:

            You can start PowerShell by searching for it in the Start Menu and selecting it, by pressing **Win + X** and choosing "Windows PowerShell" from the menu, or by continuing with an existing session if one is already open.

        2. **Check for OpenSSH Client**:

            Ensure that OpenSSH Client is installed on your system. In PowerShell or Command Prompt, run:

            ```powershell
            ssh
            ```

            If the command is not recognized, you may need to install the OpenSSH Client via **Settings > Apps > Optional Features**.

        3. **OpenSSH Key Location**:

            Determine where your private key is stored. This guide assumes it is in your user profile's `.ssh` directory. The typical path is:

            ```
            C:\Users\yourusername\.ssh\id_rsa
            ```

        4. **Initiate an SSH Connection**:

            Use the `ssh` command with the `-i` flag to specify the path to your private key file. The command format is as follows:

            ```powershell
            ssh -i C:\Users\yourusername\.ssh\id_rsa username@hpc.tue.nl
            ```

            For example, if your SSH username is `s133320` and your Windows username is `yourusername`, the command would be:

            ```powershell
            ssh -i C:\Users\yourusername\.ssh\id_rsa s133320@hpc.tue.nl
            ```

        5. **Verify the Connection**:

            On your first connection, you'll be prompted to verify the server's authenticity. You'll see a message like this:

            ```
            The authenticity of host 'hpc.tue.nl (xx.xx.xx.xx)' can't be established.
            ECDSA key fingerprint is SHA256:abcdefg...
            Are you sure you want to continue connecting (yes/no/[fingerprint])?
            ```

            Type `yes` and press Enter. This action will add the server's fingerprint to your `C:\Users\yourusername\.ssh\known_hosts` file, allowing future connections without prompts.

        6. **Access the Server**:

            After a successful connection, you will have access to the server's command line interface, where you can execute commands.

        7. **Close the SSH Session**:

            To disconnect from the server, type `exit` and press Enter. This command will close the connection and return you to your local terminal session.

        By following these steps, you'll be able to securely connect to `hpc.tue.nl` using your SSH key, enhancing security by avoiding password entry for each login.

=== ":fontawesome-brands-linux: Linux"

    1. **Open the Terminal**:

        Start your terminal application. You can typically find it in the application menu or use a keyboard shortcut (e.g., `Ctrl + Alt + T` on some systems), or by continuing with an existing session if one is already open.

    2. **Initiate an SSH Connection**:

        Use the `ssh` command with the `-i` flag to specify the path to your private key file. The command format is as follows:

        ```bash
        ssh -i /home/yourusername/.ssh/id_rsa username@hpc.tue.nl
        ```

        For example, if your SSH username is `s133320` and your Linux username is `yourlinuxuser`, the command would be:

        ```bash
        ssh -i /home/yourlinuxuser/.ssh/id_rsa s133320@hpc.tue.nl
        ```

    3. **Verify the Connection**:

        On your first connection, you'll be prompted to verify the server's authenticity. You'll see a message like this:

        ```
        The authenticity of host 'hpc.tue.nl (xx.xx.xx.xx)' can't be established.
        ECDSA key fingerprint is SHA256:abcdefg...
        Are you sure you want to continue connecting (yes/no/[fingerprint])?
        ```

        Type `yes` and press Enter. This action will add the server's fingerprint to your `~/.ssh/known_hosts` file, allowing future connections without prompts.

    4. **Access the Server**:

        After a successful connection, you will have access to the server's command line interface, where you can execute commands.

    5. **Close the SSH Session**:

        To disconnect from the server, type `exit` and press Enter. This command will close the connection and return you to your local terminal session.

    By following these steps, you'll be able to securely connect to `hpc.tue.nl` using your SSH key, enhancing security by avoiding password entry for each login.

=== ":fontawesome-brands-apple: MacOS"

    1. **Open the Terminal**:

        Launch the Terminal by navigating to **Applications > Utilities > Terminal**, or use Spotlight Search (⌘ + Space) and type "Terminal," then hit Enter, or by continuing with an existing session if one is already open.

    2. **Initiate an SSH Connection**:

        Use the `ssh` command with the `-i` flag to specify the path to your private key file. The command format is as follows:

        ```bash
        ssh -i /Users/yourusername/.ssh/id_rsa username@hpc.tue.nl
        ```

        For example, if your SSH username is `s133320` and your macOS username is `yourmacuser`, the command would be:

        ```bash
        ssh -i /Users/yourmacuser/.ssh/id_rsa s133320@hpc.tue.nl
        ```

    3. **Verify the Connection**:

        On your first connection, you'll be prompted to verify the server's authenticity. You'll see a message like this:

        ```
        The authenticity of host 'hpc.tue.nl (xx.xx.xx.xx)' can't be established.
        ECDSA key fingerprint is SHA256:abcdefg...
        Are you sure you want to continue connecting (yes/no/[fingerprint])?
        ```

        Type `yes` and press Enter. This action will add the server's fingerprint to your `~/.ssh/known_hosts` file, allowing future connections without prompts.

    4. **Access the Server**:

        After a successful connection, you will have access to the server's command line interface, where you can execute commands.

    5. **Close the SSH Session**:

        To disconnect from the server, type `exit` and press Enter. This command will close the connection and return you to your local terminal session.

    By following these steps, you'll be able to securely connect to `hpc.tue.nl` using your SSH key, enhancing security by avoiding password entry for each login.
