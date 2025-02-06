#!/bin/bash

cat << EOL > /etc/nginx/nginx.conf
worker_processes 1;

events {}

http {
    server {
        listen 80;
		include /etc/nginx/mime.types;
	    root /var/www/public;
		index index.html;

        location /new {
			alias /var/www/public;
            index new.html;
        }

        location /all {
            proxy_pass http://xquery-server:8008/all.xquery;
        }

        location /writer {
            proxy_pass http://writer:8009;
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

        location /cows {
            proxy_pass http://xquery-server:8008/cows.xquery;
        }
    }
}

EOL

nginx -g "daemon off;"
