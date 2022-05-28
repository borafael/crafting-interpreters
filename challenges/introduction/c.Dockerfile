FROM ubuntu:latest
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install build-essential valgrind -y
COPY ./main.c /src/main.c
WORKDIR /src
RUN gcc -o main main.c
CMD ["/usr/bin/valgrind", "-s", "--track-origins=yes", "./main"]
