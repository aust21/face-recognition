cmake_minimum_required(VERSION 3.16)

project(face-recognition LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
add_definitions(-DRESOURCE_DIR="${CMAKE_SOURCE_DIR}/resources")

add_executable(face-recognition
    src/main.cpp
    resources/face_data.xml
    resources/face_data.h
)

target_include_directories(face-recognition PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(face-recognition PRIVATE ${OpenCV_LIBS})
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/resources)  # Add this line

include(GNUInstallDirs)
install(TARGETS face-recognition
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
