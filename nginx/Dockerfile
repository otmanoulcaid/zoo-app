FROM debian:stable-slim

RUN apt update -y && apt install nginx -y

COPY nginx.conf /etc/nginx/nginx.conf

ENTRYPOINT ["nginx", "-g", "daemon off"]