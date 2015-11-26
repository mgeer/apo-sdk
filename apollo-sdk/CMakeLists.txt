cmake_minimum_required(VERSION 2.8)
project(apollo_sdk)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(./)
include_directories(../apollo-api)

aux_source_directory(./ SOURCE_FILES)
add_library(apollo_sdk ${SOURCE_FILES})

if(APPLE)
    target_link_libraries(apollo_sdk apollo_api boost_system)
else(APPLE)
    target_link_libraries(apollo_sdk apollo_api boost_thread)
endif(APPLE)

