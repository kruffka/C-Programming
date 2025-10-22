<!-- vscode-markdown-toc -->
* 1. [include](#1)
* 2. [define](#2)
	* 2.1. [Предопределенные константы](#2.1)
* 3. [Условная компиляция](#3)
* 4. [Защита от повторного включения](#4)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

# 8_preprocessor

Это первый этап обработки при компиляции.             
Все, что начинается на символ `#` - директива препроцессора.                    

##  1. <a name='1'></a>include

include - дословно включить (включать/подключать). Включаем мы только заголовочные файлы (.h), в которых содержится описания прототипов функций либо объявления новых типов данных (структуруы, объединения)              

Угловные скобки <> - говорят компилятору искать в стандартных путях (обычно /usr/include в linux)      
```c
#include <stdio.h>
```
Двойные "" - искать сначала в текущем каталоге                       
```c
#include "my_header.h"
```
Опцией –I компилятору можно задать путь до заголовочных файлов компилятору, чтобы в include не прописывать полный путь до заголовочного файла                   

```c
// вместо ./include/my_header.h просто my_header.h т.к. при компиляции укажем каталог где искать этот файл
#include "my_header.h" 
// ..
```
```bash
gcc prog.c -o prog -I ./include/
```
- где ./include - каталог с заголовочным файлом my_header.h                

Подключать мы можем и .c файлы, но этим обычно никто не занимается, т.к. это плохая практика. Если поменять хоть одну строку в коде включаемого файла, то все файлы, что включают его необходимо будет перекомпилировать (если проект большой, то это займет немало времени)                           

##  2. <a name='2'></a>define

#define – директива, предназначенная для макро определений.                   
С точки зрения хорошего стиля кода принято все макро определения пишут большими буквами.                     

#define используется обычно в двух случаях [define.c](https://github.com/kruffka/C-Programming/blob/2025-2026/8_preprocessor/src/define.c):            
- для определения констант            
```c
#define K 123 // K определена как 123

void func() {
    printf("K = %d\n", K); // K = 123
}

#undef K // а теперь K больше не существует

int main() {
    printf("K = %d\n", K); // ошибка: K больше не существует
    func();
    return 0;
}
```

- для определения макросов (макрос - подобие функции, но это не функция)
```c
#define MIN(a, b) ((a < b) ? a : b)
// ..
// MIN(1, 2) раскроется на 1 этапе компиляции как: ((1 < 2) ? (1 : 2)) и будет равно 1
MIN(1, 2);
```

**Самостоятельно:** Почему следующее использование макроса плохо? 
```c
MIN(func1(), func2());
```
<details>               
<summary>Ответ</summary> 
Два вызова одной и той же функции: ((func1() < func2()) ? (func1() : func2()))
</details>                   
<br>    

Еще один неудачный макрос:
```c
#define ADD(a, b) a + b
int a = 5, b = 3;
int c = ADD(a, b); // чему равна c?
int d = 4 * ADD(a, b); // чему равна d?
```
<details>               
<summary>Ответ</summary> 
c = a + b = 5 + 3 = 8;
<br>
d = 4 * a + b = 4 * 5 + 3 = 23;
<br>
Можно исправить результат, поставив скобки:
<br>
#define ADD(a, b) (a + b)
<br>
тогда d = 32
</details>                   
<br>    


###  2.1. <a name='2.1'></a>Предопределенные константы

Существует много различных предопределенных констант, вот некоторые из них, что могут пригодиться нам:        
- __LINE__     - номер строки 
- __FILE__     - имя файла
- __FUNCTION__ - имя функции
- __DATE__     - дата компиляции программы
- __TIME__     - дата компиляции программы

Например [constants.c](https://github.com/kruffka/C-Programming/blob/2025-2026/8_preprocessor/src/constants.c):
```c
printf("Error at LINE=%d, FILE=%s, function=%s\n", __LINE__, __FILE__, __FUNCTION__);
//..
printf("Compilation time: date=%s, time=%s\n", __DATE__, __TIME__);
```
```bash
Compilation time: date=Oct 21 1970, time=09:59:25
Error at LINE=5, FILE=src/constants.c, function=func
```

Интересно:           
```c
// позволяет в VSCode прыгнуть в этот файл зажав CTRL + лкм по этой ссылке
printf("%s:%d\n", __FILE__, __LINE__); 
```
```bash
src/constants.c:7
```

##  3. <a name='3'></a>Условная компиляция

Позволяет выбрать на этапе компиляции какой код вставить в нашу программу и компилировать далее, например:
```c
#if B == 5
    // Если B определена как 5, то этот код вставится в программу
#else
    // иначе этот код войдет в программу
#endif
```
Определить можно через define, либо при компиляции через опцию -D:
```bash
gcc src/cond.c -o cond -DB=5
```
- где -D (от слова define), B=5 - определяем B как 5

**Важно:** Все эти директивы выполняются во время компиляции, а не во время работы программы!
Т.е. директивы не будут работать с внутренними переменными языка Си.                    

Полезно для добавления дебаг (отладочного) кода или для переносимости на различные архитектуры или ОС, а также для учитывания версии библиотек и т.д.           
```c
#ifdef DEBUG 
    // ..
#endif
```
Или
```c
#ifndef DEBUG
    // ..
#else
    // ..
#endif
```
Примерчик:  
```c
int sum(int x, int y) {
    int sum = x + y;
#ifdef DEBUG
    // этот код будет скомпилирован только если DEBUG определен
    printf("DEBUG: Value of x = %d\n", x);
    printf("DEBUG: Value of y = %d\n", y);
    printf("DEBUG: Sum calculated as %d\n", sum);
#endif
    return sum;
}
```


Еще один пример с макросами и условной компиляции:
```c
#define PRINT_DEBUG(format, ...)                                                                        \
	do {                                                                                                \
            printf("%s:%d:%s(): ", format,  __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);             \
    } while(0)
```
где do .. while(0) здесь нужен для того чтобы мы подобно вызовам функций в конце вызова макроса ставили `;`
```c
PRINT_DEBUG("Error: %s\n", message); // `;` точка с запятой обязательно
```
А также для случаев, когда макрос находится внутри if..else, чтобы не запутаться в фигурных скобках {}              
```c
#define MY_MACRO_BAD { statement1; statement2; } // Не ок
#define MY_MACRO_GOOD do { statement1; statement2; } while(0) // Ок
// Usage:
if (condition) MY_MACRO_GOOD; // Работает
if (condition) MY_MACRO_BAD; // Expands to: if (condition) { statement1; statement2; };, а это syntax error
```


Полный пример в [cond.c](https://github.com/kruffka/C-Programming/blob/2025-2026/8_preprocessor/src/cond.c)              

```bash
gcc src/cond.c -o cond -DB=5 -DDEBUG=1
./cond
```


##  4. <a name='4'></a>Защита от повторного включения

Вернемся к этому когда будем проходить многофайловые проекты                   

```c
// test.c

#include "test.h"
#include "test2.h"

// ..
```

```c
// test.h

#ifndef _TEST_H_
#define _TEST_H_
// ..
int a; // определение чего-либо
// ..
#endif // _TEST_H_
```

```c
// test2.h
#ifndef _TEST2_H_
#define _TEST2_H_

#include "test.h"

// ..
#endif // _TEST2_H_

```