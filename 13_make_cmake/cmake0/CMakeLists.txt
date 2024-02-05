# - комментарий
# для сборки:
# mkdir build
# cd build
# cmake ..
# make
# cmake сгенерит Makefile'ы, а командой make соберется весь проект.

cmake_minimum_required(VERSION 3.10) # Минимальная требуемая версия cmake, если на хосте будет версия ниже, 
                                     # то не соберется
add_executable(main main.c functions.c)	# Создает исполняемый файл с именем main
									    # из исходников