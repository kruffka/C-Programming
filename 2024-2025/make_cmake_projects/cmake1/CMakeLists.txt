cmake_minimum_required(VERSION 3.10)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произойдёт аварийный выход.

project(hello_cmake)			# Название проекта

set(SOURCE_EXE main.c)		# Установка переменной со списком исходников для исполняемого файла, чтобы разыменовать и
                            # вытащить значение переменной используется ${имя_переменной}
set(SOURCE_LIB functions.c)			# Тоже самое, но для библиотеки

add_library(MY_LIB STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем MY_LIB

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main MY_LIB)		# Линковка программы с библиотекой