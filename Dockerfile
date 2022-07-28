FROM ubuntu:latest

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install apt-utils make g++

ADD . /app

WORKDIR /app

EXPOSE 2368/tcp
EXPOSE 2368/udp

VOLUME /app/logs

CMD ["./docker_script.sh"]