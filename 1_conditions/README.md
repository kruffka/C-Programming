# 1_conditions

- Ввод с клавиатуры
- Type Casting
- Условия и условные операторы
- Тернарный оператор
- switch-case

## Ссылки

[Лекция](lecture.md)      
[Презентация](1_conditions.pdf)         
[Примеры](src/)           

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
gcc prog.c -o prog  
./prog
```

or  
```bash
gcc prog.c  
./a.out
```
