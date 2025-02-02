worker_processes 1;

events {
    worker_connections 1024;
}

#!/bin/bash


mkdir -p /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -subj "/C=MO/ST=KH/O=42/OU=42/CN=otman.ma"

cat << EOL > /etc/nginx/nginx.conf
worker_processes 1;

events {}

http {
    include /etc/nginx/mime.types;

    server {
        listen 443 ssl;
        server_name otman.ma;

        ssl_certificate /etc/nginx/ssl/inception.crt;
        ssl_certificate_key /etc/nginx/ssl/inception.key;
        ssl_protocols TLSv1.3;

        location /dogs {
            proxy_pass http://xquery-server:8008/dogs.xquery;
        }
        
        location /cats {
            proxy_pass http://xquery-server:8008/cats.xquery;
        }

        location /birds {
            proxy_pass http://xquery-server:8008/birds.xquery;
        }
    }
}
EOL

nginx -g "daemon off;"
