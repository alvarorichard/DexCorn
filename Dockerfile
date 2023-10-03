FROM debian:stable

RUN apt update && \
    apt install -y \
        g++ \
        cmake \
        
COPY . /app

WORKDIR /app

RUN mkdir build && \
    cd build && \
    cmake .. && \
    make;

CMD [ "/app/build/sources/project" ]

