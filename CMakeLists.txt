cmake_minimum_required(VERSION 3.13)
project(Json)

set(CMAKE_CXX_STANDARD 14)

add_library(strview strview/strview.cpp strview/strview.h)

add_library(json json/json.cpp json/json.h)

target_link_libraries(json strview)

add_executable(teststrview strview/teststrview.cpp)

add_executable(testjson json/testjson.cpp)

target_link_libraries(teststrview strview)

target_link_libraries(testjson json)