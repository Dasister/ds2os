FROM ubuntu AS build

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -q -y g++ curl zip unzip tar binutils cmake git yasm

COPY ./ /build
WORKDIR /build/Tools
RUN ./generate_make_release.sh
WORKDIR /build
RUN cd intermediate/make && make -j$(nproc || echo 4)

FROM steamcmd/steamcmd:latest AS steam

# Make steamcmd download steam client libraries so we can copy them later.
RUN steamcmd +login anonymous +quit

FROM ubuntu AS runtime

RUN mkdir -p /opt/ds2os/Saved \
    && useradd -r -s /bin/bash -u 1000 ds2os \
    && chown ds2os:ds2os /opt/ds2os/Saved

COPY --from=build /build/bin/x64_release/ /opt/ds2os/
COPY --from=steam /root/.steam/steamcmd/linux64/steamclient.so /opt/ds2os/steamclient.so

ENV LD_LIBRARY_PATH="/opt/ds2os"

USER ds2os
WORKDIR /opt/ds2os
ENTRYPOINT /opt/ds2os/Server 
