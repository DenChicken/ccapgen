cmake_minimum_required(VERSION 3.0.0)

project("ccapgen" VERSION 0.0.1 DESCRIPTION "C++ library for generation .pcap files")

#add_library(ccapgen SHARED
#    src/main.cpp
#) 

include_directories(include)
add_executable(ccapgen 
    src/main.cpp
    src/layers/l3/ipv4.cpp
 "include/basic/interfaces/IData.h")

set_target_properties(ccapgen PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(ccapgen PROPERTIES SOVERSION 0)

set_target_properties(ccapgen PROPERTIES PUBLIC_HEADER include)
target_include_directories(ccapgen PRIVATE .)
