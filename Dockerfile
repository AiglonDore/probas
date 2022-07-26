FROM ubuntu:latest

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install apt-utils gcc make g++ gcc-mingw-w64 g++-mingw-w64 python3 pip -y \
    && python3 -m pip install numpy matplotlib scipy sympy pyinstaller

ADD . /app

WORKDIR /app

EXPOSE 2368/tcp
EXPOSE 2368/udp

VOLUME /app/logs

CMD ["make","probas.out plot.out","RELEASE=TRUE"]