# Licenses

## License servers

The TU/e provides centralized licenses for some commercial application via license servers. Some Facuties or Departments are also hosting their own license servers. Other commercial applications may depend on the excistance of a license file.

### FlexLM

FlexLM stands for "Flexible License Manager". It is used to restrict who can use what software on what computer, and is also a source of usability issues. Below a selection of various diagnostics that can be done.

#### Checking the availability and available featres of a FlexLM license

`/sw/rl8/zen/lic/lmutil lmstat -a -c [port]:[hostname]`

#### Checking out a license feature

`/sw/rl8/zen/lic/lmutil lmdiag [feature] -c [port]:[hostname]`

#### Using and specifing a lisense

When using the [module system](https://supercomputing.tue.nl/documentation/steps/software/) to load an application the application specific setting for the license are included. Sometimes to setup a different license sever for the same application, there is an extra module available.

`ANSYS/2025R2` uses the default (research) license, while `ANSYS/2025R2-edu` uses the educational license.

When starting a Interactive Session via [Umbrella OnDemand](https://supercomputing.tue.nl/documentation/steps/access/openondemand/) the license server is configured for the application sellected.

Often, an application-specific environment variable can be used to
specify the location of the license file or license server. For ANSYS applications,
like Lumerical, this is `ANSYSLMD_LICENSE_FILE` (this environment variable is set when using. `module load Lumerical/2024-R1.3`). To specify a specific license server, set this variable to `[port]:[hostname]`.

Optionally, set the environment variable `FLEXLM_DIAGNOSTICS` to `1`,
`2`, or `3`. This might provide more info, but also be blocked by the
application and do nothing. Source:
[here](https://www-local.pdc.kth.se/doc/pgi/3.3/flexuser/chap8.htm){:target=_blank}.

### MathLM

MathLM is the license server software used by Wolfram Mathematica. It is used to restrict who can use what software on what computer, and is also a source of usability issues.

#### Checking the availablility of the MathLM license server

`/sw/rl8/zen/lic/monitorlm [hostname] -health`

#### Checking the availability and available featres of a MathLM license

`/sw/rl8/zen/lic/monitorlm [hostname]`

#### Using and specifing a MathLM lisense

When using the [module system](https://supercomputing.tue.nl/documentation/steps/software/) to load the Mathematica application, the application specific setting for the license are included. `module load Mathematica/14.1.0`. When starting a Interactive Session via [Umbrella OnDemand](https://supercomputing.tue.nl/documentation/steps/access/openondemand/) the license server is configured but can be changed using the Mathematica Interface.
