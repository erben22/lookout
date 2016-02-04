# Version: 0.0.1
FROM resin/rpi-raspbian
MAINTAINER R. Cody Erben "erben22@mtnaircomputer.net"
ENV REFRESHED_AT 2016-02-03
ENV RTL_SDR_REPO /tmp/rtl-sdr

RUN echo 'deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi' >> /etc/apt/sources.list

RUN apt-get update && apt-get -y upgrade
RUN apt-get -y install git
RUN apt-get build-dep rtl-sdr
RUN apt-get clean

RUN rm -rf /var/lib/apt/lists/*

RUN echo 'blacklist dvb_usb_rtl28xxu' > /etc/modprobe.d/raspi-blacklist.conf

RUN git clone git://git.osmocom.org/rtl-sdr.git $RTL_SDR_REPO

RUN mkdir $RTL_SDR_REPO/build
RUN cd $RTL_SDR_REPO/build && cmake ../ -DINSTALL_UDEV_RULES=ON -DDETACH_KERNEL_DRIVER=ON
RUN cd $RTL_SDR_REPO/build && make
RUN cd $RTL_SDR_REPO/build && make install
RUN ldconfig

RUN rm -rf $RTL_SDR_REPO

EXPOSE 1234

#sudo echo -e "blacklist rtl2832\n\
#blacklist r820t\n\
#blacklist rtl2830\n\
#blacklist dvb_usb_rtl28xxu" > /etc/modprobe.d/rtlsdr-blacklist.conf

ENTRYPOINT ["/usr/local/bin/rtl_tcp", "-a", "172.17.0.1"]
#echo "/usr/local/bin/rtl_tcp -a 192.168.2.6 &"


