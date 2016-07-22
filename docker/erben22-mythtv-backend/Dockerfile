FROM ubuntu:15.10

ENV DEBIAN_FRONTEND noninteractive

RUN \
  sed -i 's/# \(.*multiverse$\)/\1/g' /etc/apt/sources.list && \
  echo 'deb http://us.archive.ubuntu.com/ubuntu/ wily multiverse' >> /etc/apt/sources.list && \
  echo 'deb-src http://us.archive.ubuntu.com/ubuntu/ wily multiverse' >> /etc/apt/sources.list && \
  echo 'deb http://us.archive.ubuntu.com/ubuntu/ wily-updates multiverse' >> /etc/apt/sources.list && \
  echo 'deb-src http://us.archive.ubuntu.com/ubuntu/ wily-updates multiverse' >> /etc/apt/sources.list && \
  apt-get update && \
  apt-get -y upgrade

RUN \
  apt-get install -y \
      build-essential \ 
      software-properties-common \ 
      curl \
      unzip \
      vim \
      wget \
      lxde-core \
      lxterminal \
      tightvncserver \
      nano \
      mythtv-backend-master \
      ffmpeg
# && rm -rf /var/lib/apt/lists/*

ENV USER root
ENV HOME /root

WORKDIR /root

#EXPOSE 5901
#EXPOSE 80
#EXPOSE whatever the mythtv backend port is

#CMD bash -c 'vncserver :1 -geometry 1280x800 -depth 24 && tail -F /root/.vnc/*.log'
