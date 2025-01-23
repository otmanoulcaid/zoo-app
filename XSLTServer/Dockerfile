FROM debian:stable-slim

RUN apt update -y && \
apt install xsltproc -y && \
apt install make -y && \
apt install g++ -y

WORKDIR /source

COPY ./source /source

ENTRYPOINT ["make"]