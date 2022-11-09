cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(http_utils LANGUAGES CXX)

add_library(http_utils http_utils.cpp)
target_include_directories(http_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(http_utils_test test/main.cpp)
target_link_libraries(http_utils_test PRIVATE http_utils)
