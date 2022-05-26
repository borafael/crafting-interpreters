FROM gcc:latest
COPY ./main.c /src/main.c
WORKDIR /src
RUN gcc -o main main.c
CMD ["./main"]
