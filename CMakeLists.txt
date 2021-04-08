cmake_minimum_required(VERSION 3.16)
project(xx1 CXX)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_C)

add_executable(xx1 main.cc ${SRC_C})