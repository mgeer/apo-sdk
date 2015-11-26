cmake_minimum_required(VERSION 2.8)
project(apollo_api)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(./)

aux_source_directory(./ SOURCE_FILES)

add_library(apollo_api ${SOURCE_FILES})
target_link_libraries(apollo_api thrift)