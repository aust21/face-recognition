# Use an official base image with OpenCV pre-installed
FROM ubuntu:22.04

# Set up environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libopencv-dev \
    pkg-config \
    && apt-get clean

# Create a working directory
WORKDIR /app

# Copy the entire project to the container
COPY . /app

# Compile the program
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Set the entry point to run the program
ENTRYPOINT ["./build/Desktop_Qt_6_8_1-Debug/face-recognition"]
