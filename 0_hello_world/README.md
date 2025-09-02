## Ссылки

[Лекция](https://github.com/kruffka/C-Programming/blob/d08d7e75f2adc9935c9089b66ae8c19487ba45d0/0_hello_world/lecture.md)      
[Презентация](https://github.com/kruffka/C-Programming/blob/2025-2026/0_hello_world/0_hello_world.pdf)         
[Исходный код](https://github.com/kruffka/C-Programming/blob/425ce515c4de4afe295e00edbed655d204011dc7/0_hello_world/src/)           

-----------

## Команды в терминале  

mkdir my_dir # Создать каталог с именем my_dir
ls           # Просмотреть список файлов в текущем каталоге  
pwd          # Вывести имя текущей директории  
cd my_dir    # Перейти в каталог my_dir  
cd ..        # Подняться на каталог "выше" (вернуться назад)  
nano hello.c # открыть файл в текст. редакторе nano  
rm file_name # удалить файл с именем file_name  

## Команды в текст. редакторе nano   
CTRL+O (^O) # save program  
CTRL+X (^X) # exit program  

----------

# Compile and run
Версия компилятора (проверка что вообще установлен)
-----------
```bash
gcc --version
```
Compile and run program
-----------
```bash
gcc hello_world.c -o hello_world  
./hello_world
```

or  
```bash
gcc hello_world.c  
./a.out
```


# Compilation steps

Input:  
Source file: hello.c

Preprocessor (*.i)
-----------
```bash
gcc -E hello.c -o hello.i  
```
Assembly (*.s)
-----------
```bash
gcc -S hello.i -o hello.s
```
Machine Code (object file, *.o)
-----------
```bash
gcc -c hello.s -o hello.o
```
#### ELF Header  
```bash
readelf -h hello.o  
```
#### Machine code (disassemble)
```bash
objdump -s hello.o  
objdump -d hello.o  
```

Binary executable
-----------
```bash
gcc hello.o -o hello
```

Output:  
binary executable program  
```bash
./hello
```
