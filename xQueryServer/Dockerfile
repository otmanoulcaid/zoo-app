FROM debian:stable-slim

RUN apt update -y && \
apt install basex -y && \
apt install make -y && \
apt install g++ -y

WORKDIR /source

COPY ./source /source

ENTRYPOINT ["make"]