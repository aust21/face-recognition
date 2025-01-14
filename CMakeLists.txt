cmake_minimum_required(VERSION 3.16)

project(face-recognition LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(face-recognition main.cpp)

target_include_directories(face-recognition PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(face-recognition PRIVATE ${OpenCV_LIBS})

include(GNUInstallDirs)
install(TARGETS face-recognition
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
