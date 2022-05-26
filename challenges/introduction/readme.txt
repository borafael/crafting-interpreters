Build and run java code:

docker build -f ./java.Dockerfile -t dockerized-java-hello-world .
docker run -it --rm dockerized-java-hello-world

Build and run c code:

docker build -f ./c.Dockerfile -t dockerized-c-double-linked-list .
docker run -it --rm dockerized-c-double-linked-list


