=== ":fontawesome-brands-windows: Windows"

    1. **Launch MobaXterm**:

        Open MobaXterm by double-clicking its icon on your desktop or finding it in your Start menu.

    2. **Start a New SSH Session**:

        To initiate a new SSH session, click on the `Session` icon in the top left corner of the MobaXterm window. In the session settings window, select `SSH`.

    3. **Configure Your SSH Settings**:

        In the SSH session configuration, fill in the following details:

        - **Remote host**: Enter `hpc.tue.nl`.
        - **Specify username**: Enter your SSH username, e.g., `s133320`.
        - **Port**: Leave this set to `22`, the default SSH port.

        If you have a private key for authentication, check the box for `Use private key` and browse to the key file location, typically `C:\Users\yourusername\.ssh\id_rsa`.

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

=== ":fontawesome-brands-linux: Linux"

    1. **Open the Terminal**:

        Open the Terminal by pressing `Ctrl + Alt + T`, or find it through your system’s application menu under **System Tools** or **Accessories**.

    2. **Initiate an SSH Connection**:

        Use the `ssh` command. The command format is as follows:

        ```bash
        ssh username@hpc.tue.nl
        ```

        For example, if your SSH username is `s133320`, the command would be:

        ```bash
        ssh s133320@hpc.tue.nl
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

=== ":fontawesome-brands-apple: MacOS"

    1. **Open the Terminal**:

        Launch the Terminal by navigating to **Applications > Utilities > Terminal**, or use Spotlight Search (⌘ + Space) and type "Terminal," then hit Enter.

    2. **Initiate an SSH Connection**:

        Use the `ssh` command. The command format is as follows:

        ```bash
        ssh username@hpc.tue.nl
        ```

        For example, if your SSH username is `s133320`, the command would be:

        ```bash
        ssh s133320@hpc.tue.nl
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
