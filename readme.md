# Facial Recognition

This project is a facial recognition application built using C++, OpenCV, and CMake. The application leverages computer vision techniques to detect and recognize faces from live video streams.

---

## Features
- Face detection using OpenCV.


## Prerequisites
Before building and running the project, ensure the following tools and libraries are installed:

### Required Tools
- **C++ Compiler**: GCC (>= 11.0) or MSVC
- **CMake**: >= 3.16

### Dependencies
- OpenCV: Image processing library
- GTK+: Required by some OpenCV functionalities
- libva-dev: For video acceleration

## Installation and Setup

### Step 1: Clone the Repository
```bash
git clone https://github.com/aust21/face-recognition.git
cd face-recognition
```

### Step 2: Install Dependencies
- **For Linux**: sudo apt-get install libopencv-dev
- **MacOS (Homebrew)**: brew install opencv
- **Windows**: Use a precompiled OpenCV distribution or build it from source.

### Step 3: Build the Project

Run the following commands to build the project:

```bash
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build .
```

### Step 4: Run the Application

Run the generated executable:
```bash
./face-recognition
```

## Usage
1. Prepare a live video feed (default cam).
2. Sit in good lighting.
2. Position a face in view of the camera.

## Acknowledgments
- [OpenCV](https://opencv.org/)
