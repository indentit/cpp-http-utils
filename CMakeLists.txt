cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(http_utils LANGUAGES CXX)

add_library(${PROJECT_NAME} http_utils.cpp)

# headers
target_include_directories(http_utils PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/cpp-string-utils
	)

# build the string lib just for private use
add_subdirectory(cpp-string-utils)
target_link_libraries(${PROJECT_NAME} PUBLIC 
	string_utils
	)

# test executable that uses the library
add_executable(http_utils_test test/main.cpp)
target_link_libraries(http_utils_test PRIVATE ${PROJECT_NAME})
