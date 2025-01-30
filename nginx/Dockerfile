FROM openjdk:21-alpine

RUN apk add --no-cache nginx

COPY nginx.conf /etc/nginx/nginx.conf

ENTRYPOINT ["nginx", "-g", "daemon off;"]
