cmake_minimum_required(VERSION 2.8)
project(apollo_sdk_cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(CMAKE_VERBOSE_MAKEFILE on)
#set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_subdirectory(apollo-api)
add_subdirectory(apollo-sdk)
add_subdirectory(apollo-sdk-test)
add_subdirectory(gtest-1.6.0)

