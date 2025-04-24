ARG CI="false"

FROM python:3.13-alpine AS dev

WORKDIR /tmp

COPY pyproject.toml pyproject.toml
COPY src src

RUN apk --no-cache add git \
 && pip3 install --root-user-action ignore -e .

CMD ["mkdocs", "serve", "--dev-addr", "0.0.0.0:8000"]

FROM scratch AS build

ARG CI

WORKDIR /tmp

COPY --from=dev / /

COPY README.md README.md
COPY mkdocs.yml mkdocs.yml
COPY docs docs
COPY overrides overrides
COPY .git .git

ENV PYTHONPATH="/tmp" \
    CI="${CI}"

RUN mkdocs build

FROM caddy:2-alpine

COPY --from=build /tmp/site .

CMD ["caddy", "file-server"]
