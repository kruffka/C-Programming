cmake_minimum_required(VERSION 3.10)

project(hello_cmake)

set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/app)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES 
    ${SOURCE_DIR}/utils.c
    ${SOURCE_DIR}/init.c
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Сборка библиотеки
add_library(UTIL_LIB STATIC ${SOURCES}) 
# Статическая библиотека STATIC
# Для динамических SHARED, для "плагин" библиотек - MODULE

add_executable(main ${APP_DIR}/main.c)
target_link_libraries(main UTIL_LIB) # Линковка
