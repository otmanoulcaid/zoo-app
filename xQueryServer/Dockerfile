FROM openjdk:21-slim

RUN apt update -y && \
apt install g++ -y && \
apt install make -y

RUN apt install basex -y && \
apt install libjing-java -y && \
apt install libtagsoup-java -y

WORKDIR /source

COPY ./source/ /source

RUN mkdir data

ENTRYPOINT ["make"]