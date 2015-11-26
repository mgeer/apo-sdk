cmake_minimum_required(VERSION 2.8)
project(apollo_sdk_test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(./)
include_directories(../apollo-api)
include_directories(../apollo-sdk)
include_directories(../gtest-1.6.0/include)
aux_source_directory(./ SOURCE_FILES)

add_executable(apollo_sdk_test ${SOURCE_FILES})

target_link_libraries(apollo_sdk_test apollo_sdk gtest)