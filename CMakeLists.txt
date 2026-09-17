cmake_minimum_required(VERSION 3.31)

project(dynamic-array)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++14")

set(include_dir "${PROJECT_SOURCE_DIR}/include")

set(source_dir "${PROJECT_SOURCE_DIR}/src")

file(GLOB source_files "${source_dir}/*.cpp")
file(GLOB include_files "${include_dir}/*.h")

add_executable(dynamic-array ${source_files} ${include_files})

target_include_directories(dynamic-array PUBLIC ${include_dir})
