# SSH

High-Performance Computing (HPC) clusters are typically accessed via a Command Line Interface (CLI). Remote access is
the standard method for connecting to these clusters.

This is achieved using the Secure SHell (SSH) protocol. GNU/Linux and MacOS systems have built-in SSH tools. 
For Windows 11 users, OpenSSH can be installed, or you can use third-party software like MobaXterm, 
which offers a user-friendly interface for SSH connections.

## Required Software

--8<-- "software.inc"

## Logging in

To access the TU/e HPC Umbrella cluster use SSH with the address `hpc.tue.nl`. Typically, this can be done by using: 

```shell 
ssh username@hpc.tue.nl
```

!!! example "If your TU/e username is `s123123`, enter the following command in your terminal:"

    ```
    ssh s123123@hpc.tue.nl
    ```

    The majority of usernames are numeric, ranging from `0` to `9`, although some may begin with an `s` for students.

??? note "Click here if you need detailed instructions on how to connect to the cluster"

    --8<-- "access.inc"

??? info "Server Key Fingerprints Overview for Verification"

    If you get a question about SSH key fingerprints from the server, you
    can verify them with the values below:

    --8<-- "fingerprints.inc"

## Passwordless Authentication

A critical aspect of SSH is its key-based authentication, which employs a pair of cryptographic keys: a public key and a
private key.

Imagine you need to securely access a house, but instead of using a traditional lock and key, you're using a digital
system. This is essentially how Secure Shell (SSH) operates—by ensuring secure communication between devices using a
pair of cryptographic keys.

The public key acts like a lock that you install on the house (the server). It can be shared openly with anyone who
needs to access the server securely. The private key, on the other hand, is your personal key that unlocks this lock,
and it's crucial to keep it safe and secret.

In this analogy, servers are like houses, each one secured and waiting for your lock (your public key) to be added. Once
your lock is in place, only your private key can grant you access. Consequently, this system ensures that your data and
connections remain private and protected.

- **Server (:material-home:)** — Represents the "house" you're accessing securely.
- **Public key (:material-lock:)** — The "lock" you install on the **server (:material-home:)**.
- **Private key (:material-key:)** — Your personal key that unlocks the "lock".

??? abstract "Why Use Keys Instead of Password Authentication?"

    While password authentication is common, it has several drawbacks:

    1. **Vulnerability to Brute Force Attacks**: Passwords can be guessed through repeated attempts, especially if they are weak or reused across multiple accounts.
    2. **Phishing Risks**: Users can be tricked into revealing passwords through malicious websites or emails.
    3. **Management Challenges**: Strong, unique passwords are hard to remember, and storing them securely can be cumbersome.

    Key-based authentication addresses these issues:
    
    - **Stronger Security**: Private keys are much longer and more complex than passwords, making them resistant to brute force attacks.
    - **No Password Transmission**: Since passwords are not transmitted over the network, phishing attacks are ineffective.
    - **Convenience**: Once set up, key-based authentication allows seamless access without repeatedly entering passwords.

!!! danger ""

    You (as a user) are responsible for keeping your private key safe, as it serves as the personal key to unlock 
    systems where your public key is accepted, including the TU/e network and systems. If compromised, your private key 
    can allow unauthorized access, leading to data breaches and system abuse, with attackers potentially infiltrating 
    sensitive research data or exploiting the network for further attacks. This not only jeopardizes your personal data 
    but also threatens the integrity and security of the entire network and its systems. To prevent such risks, store 
    your private key securely, use strong encryption, and monitor for unauthorized access.

Now that you understand the analogy, let’s set up your secure access and ensure your communications are protected.

[Start Guide to SSH Key-Based Authentication](step-1.md){ .md-button .md-button--primary }
