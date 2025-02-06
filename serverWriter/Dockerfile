FROM debian:stable-slim

RUN apt update -y && \
apt install g++ -y && \
apt install make -y

WORKDIR /source

COPY ./source/ /source

ENTRYPOINT ["make"]