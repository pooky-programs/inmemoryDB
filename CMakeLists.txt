cmake_minimum_required(VERSION 3.24)
project(EC_DataProcessing)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(EC_DataProcessing
        database.h
        database.cpp
        main.cpp database.cpp)
