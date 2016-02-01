# Version: 0.0.1
FROM ubuntu:16.04
MAINTAINER R. Cody Erben "erben22@mtnaircomputer.net"

RUN apt-get update && apt-get install -y nginx

# Alternate form we could use if a shell is not available:
#RUN [ "apt-get", " install", "-y", "nginx" ]

RUN echo 'Hi, I am in your container' \
    >/usr/share/nginx/html/index.html
EXPOSE 80
