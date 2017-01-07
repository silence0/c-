cmake_minimum_required(VERSION 3.6)
project(c__reset)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    Edge.h
    Graph.cpp
    Graph.h
    main.cpp
    Node.h function.h)

add_executable(c__reset ${SOURCE_FILES})