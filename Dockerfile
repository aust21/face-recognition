FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libopencv-dev \
    pkg-config \
    v4l-utils \
    libv4l-dev \
    udev \
    libglib2.0-0 \
    libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    && apt-get clean

WORKDIR /app
COPY . /app

RUN rm -rf build && mkdir build && cd build && \
    cmake .. && \
    make

RUN adduser -u 5678 --disabled-password --gecos "" appuser && \
    adduser appuser video && \
    chown -R appuser /app

USER appuser

ENV LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libv4l/v4l1compat.so

ENTRYPOINT ["./build/face-recognition"]
