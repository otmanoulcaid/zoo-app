#!/bin/bash

cat << EOL > /etc/nginx/nginx.conf
worker_processes 1;

events {}

http {
    server {
        listen 80;
		include /etc/nginx/mime.types;
	    root /var/www/public;

        location /all {
            proxy_pass http://xquery-server:8008/all.xquery;
        }
        
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
