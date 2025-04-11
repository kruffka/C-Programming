#### Посмотреть все этапы компиляции
```bash
gcc app.c -o app -###
```
 
#### Посмотреть таблицу символов - утилита nm
#### Посмотреть зависимости - ldd

#### Многофайловый проект (без библиотек):  
```bash
gcc src/app.c src/log.c -I ./include 
```

Запускаем:  
```bash
./a.out   
```

#### Статическая библиотека:   
##### Получаем объектные файлы .o:   
```bash
gcc src/app.c src/log.c -c -I ./include   
```
##### Создаем статическую библиотеку MY_LOG, расширение .a из объектного файла с функциями  
```bash
ar r libMY_LOG.a log.o  
```

##### Линкуем (компонуем) библиотеку с объектным файлом app.o:  
```bash
gcc app.o -L. -lMY_LOG -o static_exe  
```
 -L - путь до библиотеки, -l - название  
  
##### Запускаем:  
./static_exe  
   
#### Динамическая библиотека:  
##### Объектный файл с главной функцией:   
```bash
gcc -c src/app.c -I ./include
```
##### Объектный файл для создания дин. либы:    
```bash
gcc -c -fPIC src/log.c -I ./include
```
##### Собираем дин. библиотеку:  
```bash
gcc -shared -o libMY_LOG.so log.o  
```

##### Линковка и запуск:    
```bash
gcc -o dynamic_exe app.o -L. -lMY_LOG -Wl,-rpath,.  

./dynamic_exe  
```
##### Линковка и запуск без rpath
```bash
gcc -o dynamic_exe app.o -L. -lMY_LOG

LD_LIBRARY_PATH=. ./dynamic_exe
```

#### Сборка в CMake:
[CMake пример](https://github.com/kruffka/C-Programming/blob/master/2024-2025/libraries/CMakeLists.txt)

https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Library.html           
https://cmake.org/cmake/help/latest/command/target_link_libraries.html#command:target_link_libraries