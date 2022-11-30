cmake_minimum_required(VERSION 3.24)
project(ASD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(HelloWorld)

add_executable(ASD
        HelloWorld/HelloWorld.cpp)
