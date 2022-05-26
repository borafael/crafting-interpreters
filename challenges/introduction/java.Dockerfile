FROM openjdk:11
COPY ./Main.java /src/Main.java
WORKDIR /src
RUN javac Main.java
CMD ["java", "Main"]
