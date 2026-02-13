# Я комментарий
# Задаем планку версии. Если у разработчика CMake старее — он увидит ошибку
cmake_minimum_required(VERSION 3.10)

# Инициализирует проект и создает полезные переменные типа ${CMAKE_CURRENT_SOURCE_DIR},
# что означает текущий каталог с исходниками
project(hello_cmake)

# Создание переменных APP_DIR и SOURCE_DIR
set(APP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/app)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES 
    ${SOURCE_DIR}/utils.c
    ${SOURCE_DIR}/init.c
)

# Аналог опции -I
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Главная цель: что собрать и из чего.
# Формат: add_executable(ИМЯ_ПРОГРАММЫ ИСХОДНИКИ)
add_executable(main ${APP_DIR}/main.c ${SOURCES})
