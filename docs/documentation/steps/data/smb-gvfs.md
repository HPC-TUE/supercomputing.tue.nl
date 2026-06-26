# Windows file shares (gvfs)

The `gio` command (which comes with
[GVfs](https://wiki.gnome.org/Projects/gvfs)) can be used to access a.o.
Windows file shares.

## Connecting

1.  [Connect](../access/index.md) to any of the cluster's login nodes.

2.  Connect to the Windows file share using the following command:
    ```
    gio mount smb://<server>/<share>
    ```
    Then, enter your username, domain, and password when prompted.  The default
    username is likely OK.  The domain should be `TUE`.
    ```
    Password required for share software on campusmp.campus.tue.nl
    User [20232655]:
    Domain [SAMBA]: TUE
    Password:
    ```

3.  GVfs mounts all shares in `$XDG_RUNTIME_DIR/gvfs`.  To see what dir this
    is, run:
    ```
    echo $XDG_RUNTIME_DIR/gvfs
    ```

4.  List mounted share names using the following command:
    ```
    ls $XDG_RUNTIME_DIR/gvfs
    ```

5.  To get the local path to your share, simply append the share name obtained in
    step 4 to the dir name obtained in step 3, e.g.
    ```
    echo $XDG_RUNTIME_DIR/gvfs/'smb-share:server=campusmp.campus.tue.nl,share=software'
    ```

!!! note

    The mounted Windows file share is only available on the login node that you
    ran these commands on. It is not automatically available on other login
    nodes, nor on the compute nodes.

## Using

To browse the Windows file share, you can simply `cd` to the local path that
you obtained in step 6 above.  Moving, copying, and removing files on the
Windows file share can be done using standard Linux tools such as `mv`, `cp`,
and `rm`.

## Disconnecting

1.  Run the following command:
    ```
    gio mount -u smb://<server>/<share>
    ```

(To get a list of mounted shares, run `gio mount -l`.)
