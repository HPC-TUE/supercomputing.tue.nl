[![build](https://github.com/HPC-TUE/supercomputing.tue.nl/actions/workflows/documentation.yml/badge.svg)](https://github.com/HPC-TUE/supercomputing.tue.nl/actions/workflows/documentation.yml)

# TU/e Supercomputing Center

The official website of the TU/e Supercomputing Center (SCC).

## Deployment

```shell
docker run -p 8000:8000 ghcr.io/hpc-tue/supercomputing.tue.nl:latest
```

## Development

Normal development installation

```shell
pip install --user --upgrade -e .
```

## Customizations

### Meta

- Backdrop images should, ideally, have an aspect ratio of 21:9 (ultrawide)

#### `hero` property

| Property | Value                  | Description                 |
|----------|------------------------|-----------------------------|
| backdrop | path (or URL) to image | The image shown as backdrop |
| messages | See messages           | The messages to show        |
| button   | Button to show         | The button to show          |

#### Events

We're using a customized plugin for our events, based on the
official [mkdocs-material blog plugin](https://squidfunk.github.io/mkdocs-material/plugins/blog/). All settings listed
here a compatible, with addition of the
following [Metadata](https://squidfunk.github.io/mkdocs-material/plugins/blog/#metadata) options:

| Property        | Value                          | Description              |
|-----------------|--------------------------------|--------------------------|
| type (required) | `news`, `maintenance`, `event` | Article type (see below) |

##### Type `news`

No additional properties available. Please refer to
the [official documentation](https://squidfunk.github.io/mkdocs-material/plugins/blog/) of this plugin.

##### Type `maintenance`

In addition to `news`:

| Property       | Value                              | Description                        |
|----------------|------------------------------------|------------------------------------|
| start          | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS | Start date/time of the maintenance |
| end            | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS | End date/time of the maintenance   |
| banner.enabled | Boolean                            | Show banner                        |
| banner.message | String                             | Message to show within the banner  |

##### Type `event`

In addition to `news`:

| Property | Value                                                                                                           | Description                                        |
|----------|-----------------------------------------------------------------------------------------------------------------|----------------------------------------------------|
| start    | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS                                                                              | Start date/time of the event                       |
| end      | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS                                                                              | End date/time of the event                         |
| price    | 0.00 (free), or any other digit number                                                                          | The entree fee of the event                        |
| location | String, Event location                                                                                          | Location of where the event will take place        |
| image    | URL or relative path from the `/docs` folder                                                                    | Image shown with the event                         |
| scheme   | `autumn`, `spring`                                                                                              | Change default color scheme for the specific event |
| speakers | see [authors](https://squidfunk.github.io/mkdocs-material/plugins/blog/#meta.authors){target=_blank}            | The speaker(s) of the event                        |
| sponsors | same syntax as [authors](https://squidfunk.github.io/mkdocs-material/plugins/blog/#meta.authors){target=_blank} | The sponsors of the event                          |
| schedule | see [schedule](#schedule)                                                                                       | The detailed schedule of the event                 |

##### `schedule`

| Property | Value                                                                                                     | Description                 |
|----------|-----------------------------------------------------------------------------------------------------------|-----------------------------|
| start    | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS                                                                        | Start date/time of the item |
| end      | YYYY-MM-DD<br/>YYYY-MM-DDTHH:II:SS                                                                        | End date/time of the item   |
| title    | String                                                                                                    | The shown title of the item |
| icon     | See [supported icons](https://squidfunk.github.io/mkdocs-material/reference/icons-emojis/){target=_blank} | Icon of the item            |
| speakers | see [authors](https://squidfunk.github.io/mkdocs-material/plugins/blog/#meta.authors){target=_blank}      | The speaker(s) of the event |
| schedule | see [schedule](#schedule)                                                                                 | The subschedule of the item |
