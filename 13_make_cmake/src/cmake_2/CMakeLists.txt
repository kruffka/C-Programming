cmake_minimum_required(VERSION 3.10)

project(hello_cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Выполнить CMakeLists.txt из src/
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

# #define TEST_DEF 5
add_definitions(-DTEST_DEF=5)

add_executable(main app/main.c)
target_link_libraries(main UTIL_LIB)
