FROM debian:stable-slim

RUN apt update && apt install -y nginx

COPY nginx.sh /nginx.sh

RUN chmod +x /nginx.sh

ENTRYPOINT ["/nginx.sh"]
