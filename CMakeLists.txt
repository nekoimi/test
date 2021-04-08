cmake_minimum_required(VERSION 3.16)
project(brush_test CXX)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_C)

add_executable(brush_test main.cc ${SRC_C})