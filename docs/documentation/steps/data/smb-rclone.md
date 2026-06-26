# Windows file shares (rclone)

Rclone can be used to access Windows file shares. To do so, the share must
first be configured as an rclone remote.

## Configuring

1.  [Connect](../access/index.md) to any of the cluster's login nodes.

2.  Run the following command to start the `rclone` configuration:
    ```
    rclone
    ```

3.  Follow the wizard.  Relevant info to be entered:
     - name: name of the remote; you can make something up
     - storage: `smb`
     - host: hostname of server, e.g. `campusmp.campus.tue.nl`
     - user: your TU/e username; for most people this is an 8 digit number
     - port: leave blank
     - password: your TU/e password
     - domain: `TUE`
     - spn: leave blank
     - use\_kerberos: leave blank
     - advanced config: no

!!! warning

    Rclone stores passwords in your home dir. This is not very safe.  Consider
    encrypting the rclone configuration with `rclone config encryption set`.
    This will ask you for a password to encrypt the configuration with.  Each
    subsequent invocation of rclone will ask you for this password, so it can
    read your rclone configuration.

## Using

Rclone can be used for Windows file shares in the same way it can be used for OneDrive; please see our [documentation](onedrive.md#usage).
