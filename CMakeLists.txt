cmake_minimum_required(VERSION 3.24)
project(ASD)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)
include_directories(HelloWorld)
include_directories(ExOverloading)

add_executable(ASD
        Indovinello/Contenitore.h Indovinello/Anfora.h Indovinello/Indovinello.h
        ExString/StringExample.cpp)
