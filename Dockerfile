FROM python:3-alpine@sha256:18159b2be11db91f84b8f8f655cd860f805dbd9e49a583ddaac8ab39bf4fe1a7 AS devcontainer

WORKDIR /app

ENV PYTHONPATH="/app" \
    GIT_PYTHON_REFRESH="quiet"

COPY pyproject.toml pyproject.toml
COPY src/ src/

RUN apk --no-cache add git openssh \
 && pip3 install -e .

CMD ["mkdocs", "serve", "--dev-addr", "0.0.0.0:8000"]

FROM python:3-alpine@sha256:18159b2be11db91f84b8f8f655cd860f805dbd9e49a583ddaac8ab39bf4fe1a7 AS build

WORKDIR /app

ENV PYTHONPATH="/app"

COPY --from=devcontainer /usr/local /usr/local

COPY src/ src/
COPY mkdocs.yml mkdocs.yml
COPY docs/ docs/
COPY overrides/ overrides/
COPY .git/ .git/

RUN apk --no-cache add git \
 && mkdocs build --site-dir /site

FROM caddy:2-alpine@sha256:e2e3a089760c453bc51c4e718342bd7032d6714f15b437db7121bfc2de2654a6

EXPOSE 80

COPY --from=build /site /usr/share/caddy
