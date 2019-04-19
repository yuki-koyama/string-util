cmake_minimum_required(VERSION 3.1)
project(string-util CXX)
set(CMAKE_CXX_STANDARD 11)

set(headers ${CMAKE_CURRENT_SOURCE_DIR}/include/string-util.hpp)

add_library(string-util INTERFACE)
target_sources(string-util INTERFACE ${headers})
target_include_directories(string-util INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/string-util.hpp DESTINATION include)
