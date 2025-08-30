cmake_minimum_required(VERSION 3.10) 	# Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произойдёт аварийный выход.

project(hello_cmake)					# Название проекта

set(SOURCE_EXE main.c)					# Установка переменной со списком исходников

include_directories("./subdir")			# Расположение заголовочных файлов

add_executable(main ${SOURCE_EXE})		# Создает исполняемый файл с именем main

add_subdirectory("./subdir")			# Добавление подпроекта, указывается имя дирректории

add_definitions("-DTEST_DEF=5")			# Аналогично обьявлению в коде #define TEST_DEF 5

target_link_libraries(main MY_LIB)		# Линковка программы с библиотекой