---
hide: [toc]
title: Datasets and Models
---
# Datasets and Models

!!! tip "No need to download common models and datasets yourselves!"

    On the Umbrella Cluster, we maintain a list of open models and datasets frequently used to either train or benchmark a model, usually in the context of machine learning. Instead of occupying space on your own space or waiting for the download of the data to finish to your own space, freely use the available models and datasets at the dataset folder on Umbrella Cluster.

## List of available datasets

If you want access to a restricted dataset, please see [Getting access to restricted datasets](#getting-access-to-restricted-datasets).
If your dataset is not listed here, please see [Dataset not listed?](#dataset-not-listed)

<table>
  <tr>
    <th>Name</th>
    <th>Versions</th>
    <th>Access</th>
    <th>Path</th>
    <th>License</th>
    <th>References</th>
  </tr>
  <tr>
    <td>ADE20K</td>
    <td>2021-17-01</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/ADE20K</code></td>
    <td><a href="https://groups.csail.mit.edu/vision/datasets/ADE20K/terms/">ADE20K license</a></td>
    <td><a href="https://groups.csail.mit.edu/vision/datasets/ADE20K/">Website</a><br/></td>
  </tr>
  <tr>
    <td colspan="6">
      <p>Note: the ADE20K dataset must be unzipped before use. E.g.:</p>
      <pre>
datadir=$TMPDIR/ade20k  # &lt;-- use this in jobs (and Open OnDemand interactive; and through salloc, srun)
datadir=/scratch-shared/$USER/ade20k  # &lt;-- use this in interactive sessions
mkdir $datadir
unzip /dataset/ADE20K/ADE20K.zip -d $datadir
      </pre>
    </td>
  </tr>
  <tr>
    <td>AlphaFold</td>
    <td>2.3.1</td>
    <td><a href="#free">free</a></td>
    <td>
      <code>/dataset/AlphaFold</code><br/>
      Related module: <code>module load AlphaFold/2.3.1-foss-2022a</code>
    </td>
    <td>
      Model params: <a href="https://creativecommons.org/licenses/by/4.0/legalcode">CC BY 4.0</a><br/>
      Mirrored DBs: various; see website
    </td>
    <td><a href="https://github.com/google-deepmind/alphafold">GitHub</a></td>
  </tr>
  <tr>
    <td colspan="6">
      Note: AlphaFold has a related module: <code>module load AlphaFold/2.3.1-foss-2022a</code>
    </td>
  </tr>
  <tr>
    <td>CAMELYON16</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/CAMELYON16</code></td>
    <td><a href="https://creativecommons.org/publicdomain/zero/1.0/">CC0 1.0</a></td>
    <td><a href="https://camelyon16.grand-challenge.org/">Website</a></td>
  </tr>
  <tr>
    <td>CIFAR-10</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/CIFAR-10</code></td>
    <td>See website</td>
    <td><a href="https://www.cs.toronto.edu/~kriz/cifar.html">Website</a></td>
  </tr>
  <tr>
    <td>ECoG_HB_02</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/ECoG_HB_02</code></td>
    <td><a href="https://creativecommons.org/licenses/by/4.0/legalcode">CC BY 4.0</a></td>
    <td><a href="https://data.mendeley.com/datasets/fp4bv9gtwk/2">Website</a></td>
  </tr>
  <tr>
    <td>ImageNet</td>
    <td>&mdash;</td>
    <td><a href="#poa">POA</a></td>
    <td><code>/dataset/ImageNet</code></td>
    <td><a href="https://www.image-net.org/download">Terms and Conditions</a></td>
    <td><a href="https://www.image-net.org/">Website</a></td>
  </tr>
  <tr>
    <td>inst-voice-neuropro</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/inst-voice-neuropro</code></td>
    <td><a href="https://creativecommons.org/publicdomain/zero/1.0/">CC0 1.0</a></td>
    <td><a href="https://datadryad.org/dataset/doi:10.5061/dryad.2280gb64f">Website</a></td>
  </tr>
  <tr>
    <td>MNIST</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/MNIST</code></td>
    <td><a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></td>
    <td><a href="https://yann.lecun.com/exdb/mnist/">Website</a></td>
  </tr>
  <tr>
    <td>nejm-brain-to-text</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/nejm-brain-to-text</code></td>
    <td><a href="https://creativecommons.org/publicdomain/zero/1.0/">CC0 1.0</a></td>
    <td><a href="https://datadryad.org/dataset/doi:10.5061/dryad.dncjsxm85">Website</a></td>
  </tr>
  <tr>
    <td>online-speech-brain-ALS</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/online-speech-brain-ALS</code></td>
    <td><a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></td>
    <td><a href="https://osf.io/49rt7/overview">Website</a></td>
  </tr>
  <tr>
    <td>SingleWordProductionDutch-iBIDS</td>
    <td>&mdash;</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/SingleWordProductionDutch-iBIDS</code></td>
    <td><a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></td>
    <td><a href="https://osf.io/nrgx6/overview">Website</a></td>
  </tr>
</table>

## List of available models

If you want access to a restricted model, please see [Getting access to restricted datasets](#getting-access-to-restricted-datasets).
If your model is not listed here, please see [Dataset not listed?](#dataset-not-listed)

<table>
  <tr>
    <th>Name</th>
    <th>Versions</th>
    <th>Access</th>
    <th>Path</th>
    <th>License</th>
    <th>References</th>
  </tr>
  <tr>
    <td>DeepSeek</td>
    <td>v3.1</td>
    <td><a href="#free">free</a></td>
    <td><code>/dataset/DeepSeek-v3.1</code></td>
    <td>MIT</td>
    <td><a href="https://huggingface.co/deepseek-ai/DeepSeek-V3.1">Website</a></td>
  </tr>
</table>

## Getting access to restricted datasets

Some datasets and models are not accessible by default on the Umbrella Cluster, because they require explicit acceptance of a license or agreeing to a terms of use on the website of the dataset or model provider.  Or, the dataset is provided a company that has put restrictions on the dataset's use. To ensure *legal* access to datasets, we employ the following access models:

- <a name="free">Free:</a> you can use the dataset **free of cost**, but you still need to adhere to its **license terms** and/or **terms of use**! By using such a dataset you are agreeing to its license.
- <a name="poa">POA:</a> proof of authorization (POA) needed. You can use the dataset after providing a proof of authorization, for example a screenshot of an e-mail of the dataset owner/provider in which they give you access.
- <a name="dmp">DMP:</a> data management plan (DMP) needed. You can use the dataset after providing a data management plan.

If you would like to access a restricted datasets or model on the Umbrella Cluster, please contact the system administrators and provide the required information. If the information you provide is sufficient, we will give you access to the dataset. For legal reasons we will record this process in TOPdesk.

Even if access to a datasets is not restricted, it usually still has a license and a terms of conduct.  By using the dataset or model you are agreeing to both the license and the terms of conduct.

## Dataset not listed?

If a dataset or model is missing, and if you believe that it will be of use to other people as well, it can be installed on the Umbrella Cluster and added to the list above.  This way, we prevent having many duplicates of models or datasets on the system.

To install a dataset on the cluster, a few steps must be taken:

1. Please contact us to request installation of the dataset.
2. We forward your request to the Data Stewards. A data steward is a legal expert that will judge if any [access conditions](#getting-access-to-restricted-datasets) are needed.
3. We install the dataset and inform you.

The Data Stewards maintain a larger list of datasets available within the TU/e [here](https://tue.atlassian.net/wiki/spaces/DA/database/3071213570).
