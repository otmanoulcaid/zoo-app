FROM openjdk:21-alpine

RUN apk update -y && \
apk add xsltproc -y && \
apk add make -y && \
apk add g++ -y

WORKDIR /source

COPY ./source/ /source

RUN mkdir data

ENTRYPOINT ["make"]