В этом файле рассмотрим что такое многофайловые проекты, зачем они нужны, а также системы сборки.  

## Многофайловые проекты.  

Почему не пишут проекты в одном файле, зачем разбивают на файлы если можно все написать в одном файле и оно заработает.   
Конечно так можно сделать и оно действительно заработает, однако чем больше будет такой проект тем менее читабельнее он как и для самого разработчика так и для тех людей, которым он достанется в наследство для дальнейшей разработки.  
Реальные проекты часто состоят из нескольких тысяч, а иногда даже и нескольких миллионов строк кода. Например взять то же ядро Linux и попробовать посчитать кол-во строк кода и можно приятно удивиться цифрам: [wiki кол-во строк кода в Linux ядре](https://ru.wikipedia.org/wiki/%D0%9A%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%BE_%D1%81%D1%82%D1%80%D0%BE%D0%BA_%D0%BA%D0%BE%D0%B4%D0%B0#%D0%9F%D0%BE%D0%B4%D1%81%D1%87%D1%91%D1%82_%D0%BA%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%B0_%D1%81%D1%82%D1%80%D0%BE%D0%BA_%D0%BA%D0%BE%D0%B4%D0%B0)    
Итого 18кк (18 373 471) строк кода содерижтся в проекте Linux 2017 года. Если данный проект переложить в один файл и пытаться его открыть прочитать, то даже ваш пк может сойти с ума.  

**Таким образом**, при разработке достаточно больших программ бывает удобным разрабатывать программу не в виде одного файла, а в виде нескольких. В отдельном файле сохраняем функцию main(), подпрограммы — каждую в отдельном файле или группируем по назначению.
Что это даёт? 
* Если у нас есть файл с функциями, решающий определенные задачи и мы захотим его перенести в другой проект, то без труда обычным копированием это сделаем. А если говорить о проекте с одним файлом, то здесь придется помучиться.
* Если над проектом работает больше одного программиста, то в проекте с одним файлом у вас будут вечно возникать конфликты с версиями кода.  
* При изменении файла в многофайловом проекте сборка проекта будет быстрее, т.к. нужно пересобрать лишь конкретный файл.  

**Итого**: многофайловый проект - есть способ разбить программу на отдельные модули, каждый из которых имеет собственный функционал и они не зависимы друг от друга. Также ткие модули можно использовать в других проектах.

Многофайловый проект в C состоит из файлов с расширениями .c и .h. В C++ расширения .cpp (либо сейчас модно .cc) и .h (или .hpp).  
Файлы с расширением '.c' (либо .cc или .cpp) - содержат исходный код программы с функциями, решающие конкретные задачи.  
Файлы с расширение '.h' (или .hpp) - называются заголовочные файлы (от англ. Header) т.к. в таких файлах содержатся заголовки функций (прототипы). И такие .h файлы обычно включаются в файлы .c директивой #include.   

Один из способов разбиения файлов в многофайловом можно представить примерно так в виде дерева:  
```
-my_project          // Мой проект
  |-app              // Само приложение, здесь все начинается и находится main()
  |-task1            // Код программы, решающий проблемы задачи 1  
  |  |-src           // Здесь исходники    
  |     |- *.c       // Файлы с функциями    
  |  |-include       // Здесь заголовки     
  |     |- *.h       // Заголовочные файлы    
  |-task2            // Код программы, решающий проблемы задачи 2
  |   |- task2.1     // подзадачи
  |   |   |- *.c *.h // и исходники и заголовочные файлы    
  |   |- task2.2     // подзадачи  
  |-common           // Какие-то общие вещи для всех   
  |-third-party      // Сторонние проекты   
  |-docs             // Какая-то документация
  |-tests            // или examples: Какие-то тесты и примеры с функциями из task1, task2  
  |-README.md        // Краткая подсказка по вашему проекту, например: что за проект и как собрать   
```

В данном примере у нас есть проект с названием my_project, содержащий каталоги task1, task2, в которых код разбит еще на каталоги. Так можно разбивать очень долго, но всегда нужно это делать в меру и не заниматься маразмом.   
Выделить крупные задачи несложно, скажем пишем мы мобильное приложение для работы с банком, можно попробовать разбить это на более крупные проблемы, которые в свою очередь поделить на более мелкие:  
* Авторизация (Логин пароль при входе)
* Интерфейс взаимодействия с пользователем (User Interface)
  * Кнопка отправить деняк другу
    * Исходники кнопки
  * Получить информацию о том сколько деняков на счету
  * Кнопка считать QR-code
  * ...
* Реализация кнопки чтения QR-code (работа с камерой телефона)
* Интерфейс с сервером банка
  * Отправить запрос
  * Получить ответ
* ...
  
Говоря про разбиение на файлы мы немного затрагиваем архитектуру приложений, а это очень большая и непростая тема, которую нужно осваивать самостоятельно. Например "Современный подход к архитектуре ПО" (в эиосе есть архив, где лежит эта книга).   


## Сборка многофайловых проектов

При написании таких проектов можно столкнуться с проблемой повторного включения заголовочных файлов, ее решение дано на слайдах лекции про препроцессор и директивы. (#ifndef #define #endif)     

Для сборки файлов достаточно в компилятор передать файлы через пробел, например если мы находимся в папке app с main.c и собираем func.c из src:    
```bash
gcc main.c ../src/func.c -I ../include
```

Так мы получим один исполняемый файл, собранный из двух исходных файлов.   
Опция -I говорит о том, что мы хотим подключить заголовочный файл из include папки и при этом в .c файлах не прописывать полный путь в #include "имя файла"    

Если мы вспомним этапы компиляции и объектные файлы, то можно собрать проект немножко иначе.   
Объектный файл (расширение .o) - это файл, содержащий в себе машинный код, получается на 3 этапе компиляции GCC. Такой файл хоть и содержит код, который уже понимает процессор, но файл все еще не связан с функциями других библиотек (например printf) и в файле не говорится как ОС его запустить.  
Получить объектный файл можно опцией -c:   
```bash
gcc -c main.c  
gcc -c func1.c  
gcc -c func2.c  
```
На выходе получим эти самые объектные файлы наших исходников main.o, func1.o и func2.o     
Теперь их можно связать и получить бинарник,        
```bash
gcc main.o func1.o func2.o    
```
который уже можно запускать.   
В чем смысл такой компиляции? Смысл следующий: если мы поменяем что-либо в коде файла func2.c, то нет необходимости пересобирать все наши файлы, т.е. время сборки немного сократиться за счет того, что пересобирать нам нужно лишь func2.c и затем связать с объектными файлами main.o и func1.o.  
В действительно больших программах это очень существенно, вам при каждом малейшем изменении программы не нужно ждать пару часов пока весь проект соберется, вместо этих часов он соберется за секунды, т.к нужно скомпилировать один отдельный файлик.     

С многофайловыми проектами более менее разобрались, а что если мне другой разработчик дает проект с кучей разных файлов, которые я вижу в первый раз, мне же придется искать все *.c и *.h файлы и разбираться где какие зависимости у файлов и функци. Как-то сложно..   
Но для таких ситуаций у нас есть такие штуки как системы сборки.   
  
**Системы сборки кода** — это специальные программы, которые собирают и пересобирают код проекта в автоматическом режиме по заранее заданным правилам.    
Эти системы определяют зависимости между файлами с исходным кодом и выходными файлами (программами, библиотеками и конфигурационными файлами) и в нескольких параллельных процессах выполняют команды компиляции для всех изменившихся со времени последней сборки файлов, соблюдая зависимости.    
Вторая задача систем сборок — это поиск в операционной системе и подключение к проекту библиотек и программ, которая реализуется наиболее удобными способами в зависимости от операционной системы.    
Рассмотрим пару самых популярных.   

## Make  

**make** — это утилита для автоматизации сборки программного обеспечения, особенно часто используемая в проектах на языках программирования, таких как C и C++.      
**Makefile** — это файл, который хранится в репозитории проекта и обычно находится в его корне. Он служит как документация и исполняемый код, упрощая команды для утилиты make, которая запускает их из текущей директории. Makefile состоит из набора правил, описывающих цели, реквизиты и команды:    
1) Цель (то, что мы хотим получить)  
2) Реквизит (зависимость) (то, что необходимо для выполнения правила и получения целей)  
3) Команда (Рецепт) (Какие команды выполнить с реквизитами, чтобы получить цель)  

В общем виде синтаксис makefile можно представить так:  
цель1: реквизит1 реквизит2  
	команда1 # для отступа используется табуляция, это важно  
	команда2 # команды будут выполняться последовательно и только в случае успеха предыдущей  
 
Make используется для автоматизации и сборки различных проектов: например Makefile можно встретить в таких крупных проектах как как Kubernetes, Babel и Ansible.   

make - утилита и ее необходимо установить, команда примерно следующая:
```bash
sudo apt install build-essential  
или только make  
sudo apt install make  
```

### Пример 1   

Рассмотрим [Пример 1](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/0_make) как собрать простой проект из нескольких файлов.  
В проекте уже имеется Makefile и исходный код.  
![image](https://github.com/user-attachments/assets/a2ada151-b4ee-4b93-995a-1f7c13fb2ea4)    
Если запустить   
```bash
make
```
то программа попытается найти файл с именем по умолчание Makefile в текущем каталоге и выполнить инструкции из него. Если в текущем каталоге есть несколько Makefile, то можно указать на нужный вот таким образом:
```bash
make -f MyMakefile
```
Есть еще множество других параметров, нам пока не нужных. О них можно узнать в [мануале make](https://www.gnu.org/software/make/manual/make.html).

Пробуем зайти в каталог с Makefile и запустить команду make:   
![image](https://github.com/user-attachments/assets/e79d2ced-b905-4a26-8c02-c094a5d52d41)   
Увидим, что на экран вывелись некоторые команды компиляции, но как оказывается эти команды выполнились в терминале и на самом деле, то что мы сейчас сделали - так это собрали этот мини-проект. Мы не знаем что в исходниках и не знаем их зависимостей, мы лишь вводим команду make и видим что все собралось успешно и мы можем запускать программу, что бы она не делала.  

Рассмотрим поближе само содержимое Makefile:  
```make
main: main.o functions.o
	gcc -o main main.o functions.o
	
main.o: main.c
	gcc -c main.c -o main.o

functions.o: functions.c
	gcc -c functions.c -o functions.o

# - комментарий
# main - цель (таргет), то что хотим получить
# : main.o functions.o - зависимости, то что нам нужно, чтобы получить цель
# gcc ... - команда для получения цели
```
Все что начинается с решетки - комментарий на всю строку.    
Итак, мы видим нашу цель в самом начале до двоеточия, это "main", т.е. первая цель этого Makefile - получить некоторый main файл. Для него требуется две зависимости - то, что стоит после двоеточия, а точнее main.o и functions.o. Так как этих объектных файлов у нас нет, то мы пойдем искать цель как их собрать. Ниже можем наблюдать цель для main.o и ее зависимость после двоеточия - main.c файл. Так как этот .c файл у нас есть, то мы выполним команду для получения нашей цели main.o   
```bash
gcc -c main.c -o main.o
```
Все тоже самое для functions.o. И как только цели main.o и functions.o будут выполнены, мы сможем выполнить цель main командой   
```bash
gcc -o main main.o functions.o
```

Таким образом и получаются эти команды в консоли:  
```bash
gcc -c main.c -o main.o
gcc -c functions.c -o functions.o
gcc -o main main.o functions.o
```  

Что еще мы можем сейчас сделать с make? Попробуем запустить его еще раз и увидим примерно следующее:  
![image](https://github.com/user-attachments/assets/95ea2d05-1c61-4591-97f4-e434ca392025)  
Данное сообщение говорит о том, что в нашем проекте нет никаких изменений и наш исполняемый файл самый актуальный (already up to date)  

Попробуем поменять содержимое например main.c файла и снова ввести команду make:    
![image](https://github.com/user-attachments/assets/bbc3f3f6-1e53-4b4b-b835-61117caa81c7)     
Увидим, что make пересобирает лишь тот файл, в котором действительно были изменения.   
Т.е. Make понимает какие изменения были внесены в проект и знает как его собрать быстрее.    
Еще одна фишка make и Makefile в том, что необязательно выполнять все содержимое из Makefile, можно выбрать и выполнить лишь одну цель. Например:  
```bash
make functions.o
```
Командой выше мы говорим сделать functions.o, где functions.o есть наша цель, в итоге make выполнить только команду:  
```bash
gcc -c functions.c -o functions.o
```
Также обращаю внимание на то, что цель main - находится в самом верху. Сделано это для того, чтобы make собрал именно main, если вынести цель main.o наверх, то выполнится лишь main.o, т.е. Make выполняет лишь самую первую цель сверху.  

### Пример 2  
Посмотрим [Пример 2](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/1_make), что чуточку сложнее.    
Его содержимое уже состоит из устрашающих аж 15 строчек: 
```make
.PHONY: clean # Если у нас будет файл clean в директории и у нас есть target clean, то для работы таргета нужно добавить .PHONY

all: main

main.o: main.c
	gcc -c main.c

functions.o: functions.c
	gcc -c functions.c

main: main.o functions.o
	gcc -o main main.o functions.o

clean:
	rm -rf *.o main
```
Здесь появились три новые вещи - .PHONY, цели all и clean.  
all — является стандартной целью по умолчанию. При вызове make ее можно явно не указывать. Т.е. после all указывается, то что хочется получить по умолчанию с помощью make.  
clean - цель, которая не имеет реквизитов, т.е. чтобы ее выполнить, необходимо прописать в консоли make clean и выполнится команда 
```bash
rm -rf *.o main
```
которая удалит все объектные файлы и исполняемый файл, полученные во время сборки. Иногда бывает удобно почистить все собранные файлы.   
.PHONY - с англ. фальшивые, Для того чтобы make не искал файлы с такими же именами как у целей, например clean, install и т.д., их следует определить в Makefile, при помощи директивы .PHONY.  
Если у нас будет где-то лежать файл с именем clean и у нас есть цель с таким же именем clean, то make clean не будет корректно отрабатывать и выполнять цель clean.  

### Пример 3  
Еще усложним Makefile: [Пример 3](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/2_make)    
```make
CC = gcc # Переменная с именем CC, содержащая значение gcc, чтобы разыменовать и вытащить значение переменной - $(CC)
CFLAGS = -Wall
TARGET = main

.PHONY: clean

all: $(TARGET)

main.o: main.c
			$(CC) -c -o main.o main.c
functions.o: functions.c
			$(CC) -c -o functions.o functions.c

$(TARGET): main.o functions.o
			$(CC) -o $(TARGET) $(CFLAGS) main.o functions.o

clean:
	rm $(TARGET) *.o
```
Здесь добавляются переменные. Как и в любом ЯП мы можем хранить некоторые значения в переменных, так и здесь мы можем хранить одно либо множество значений в виде имен, например список файлов или список опций. Для создания переменной пишется (обычно принято большими буквами) название переменной, затем знак = и после = пишем чему равно, например переменная хранящая в себе список исходных файлов:  
```make
SOURCES = main.c functions.c
```
Для ее использования в make ее нужно разименовать с помощью конструкции $(SOURCES), где SOURCES в скобках - есть имя некоторой нашей переменной.  

Еще примеры с Make: [Makefile для самых маленьких (хабр)](https://habr.com/ru/articles/155201/)   

Также есть такое понятие как автоматические переменные (automatic variables).  
Автоматические переменные предназначены для упрощения Makefile, но на самом деле негативно сказываются на их читабельности. Пример нескольких:  
* $@ Имя цели обрабатываемого правила
* $< Имя первой зависимости обрабатываемого правила
* $^ Список всех зависимостей обрабатываемого правила

Использовать их или нет решайте сами)  

Утилита make содержит много опций, одна из самых полезных - это опция для ускорения сборки проекта "-j" - данной опцией мы говорим сколько потоков забрать для сборки проекта.        
Например make -j8 - сборка с 8 потоками одновременно (параллельная сборка возможно благодаря независимости различных целей и компиляции их в объектные файлы).     

Makefile используется не только для сборки проектов, но и для выполнения команд в командной строке, например для докера. Это такая штука, работающая с виртуальными машинами и чтобы не прописывать различные докер команды и опции можно их описать в Makefile в виде правил up и скажем down - означающее подними (up) все виртуальные машины или потуши (выключи - down) все виртуальные машины при обращении к ним через make up, make down соответственно.     


## CMake  

CMake - кроcсплатформенная утилита для автоматической сборки программы из исходного кода.   
Функций в cmake очень-очень много (например ctest, macro-определения, поиск пакетов и пр. фичи) и все я здесь не буду описывать, лишь несколько часто встречаемых и необходимых, поэтому оставлю здесь ссылку покурить [CMake мануал](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)  
Еще примеры и почитать дополительно [Введение в CMake (хабр)](https://habr.com/ru/articles/155467/)   
[ИТМО wiki CMake](https://neerc.ifmo.ru/wiki/index.php?title=CMake_Tutorial)  

CMake еще одна утилита, что на самом деле является некоторой более удобной версией make. CMake сам по себе не соберет проект, он создан упростить написание файлов для сборки и при выполнении cmake генерирует Makefile, а через make мы уже умеем собирать.   

Для того что бы собрать проект средствами CMake для начала нужно его установить:    
```bash
sudo apt install cmake
И желательно это во избежание ошибок при сборках.  
sudo apt install build-essential  
```
Главное отличие в файлах проекта при использовании CMake, это наличие обычно в корне дерева исходников файла CMakeLists.txt (вместо Makefile), хранящий правила и цели сборки.  


### Пример 1  

Посмотрим на все тот же маленький проект из нескольких файлов, но с CMake: [Пример 1](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/cmake0)  
Все исходные файлы такие же, что и у make, однако вместо Makefile появляется новый гость - CMakeLists.txt.   
Для сборки проекта используя cmake все также потребуется make. Собирается проект довольно просто, используя всего несколько простых шагов:  
```bash
mkdir build && cd build
cmake ..
make
```

1) Создаем каталог build и заходим в него.
2) Вызываем утилиту cmake для генерации Makefile и прописываем через пробел путь до CMakeLists.txt (.. - две точки означает на каталог выше, т.е. в предыдущей папке)
3) Собираем проект с помощью make.  

Либо тоже самое двумя командами, используя лишь cmake:   
```bash
cmake -B build
cmake --build build
```  

cmake вызывается лишь один раз, далее при изменении файлов мы вызываем make для пересборки файлов. cmake повторно имеет смысл вызывать если что-то меняется в самом CMakeLists.txt.   
В итоге в каталоге build у нас соберется исполняемый файл, а также все Makefile и объектные файлы тоже будут хранится в отдельном каталоге build. Это удобно хранить все, что не относится к исходному коду в отдельной папке и в случае чего легко ее снести.  

Эта инструкция из нескольких шагов встречается повсеместно и даже в очень крупных проектах. Ее необходимо запомнить и понять. Создаем папку билд -> заходим в нее -> генерим makefile -> вызываем make -> done.   

Рассмотрим теперь само содержимое и синтаксис CMake файла CMakeLists.txt:   
```cmake
# - комментарий
cmake_minimum_required(VERSION 3.10) # Минимальная требуемая версия cmake, если на хосте будет версия ниже, 
                                     # то не соберется
project(hello_cmake)                            # Имя проекта
add_executable(main main.c functions.c)	# Создает исполняемый файл с именем main
									    # из исходников
```
Комментарии здесь как и в Makefile начинаются с #.  Для сборки проекта минимум, что необходимо так это две функции cmake:   
```cmake
cmake_minimum_required(VERSION x.xx)
```
где указывается минимальная необходимая версия cmake для сборки вашего проекта. Это необходимо для использования различных фич из более новых версий CMake для сборки проектов.   
Также здесь указывается имя проекта через project(), который сохраняет его в переменной PROJECT_NAME, а также инициализирует некоторые переменные хранящие пути проекта, пример:    
* PROJECT_SOURCE_DIR или <PROJECT-NAME>_SOURCE_DIR - Абсолютный путь к исходному каталогу проекта.  
* PROJECT_BINARY_DIR или <PROJECT-NAME>_BINARY_DIR - Абсолютный путь к бинарному каталогу проекта.

И самое главное это добавление цели - add_executable(цель исходники). Данная функция в примере скажет make'у собрать исполняемый файл main из исходников main.c и functions.c.       


### Пример 2  

Усложняем..  [Пример 2](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/cmake1)   
```cmake
cmake_minimum_required(VERSION 3.10)	  # Проверка версии CMake.
										                    # Если версия установленой программы
										                    # старее указаной, произойдёт аварийный выход.

project(hello_cmake)			# Название проекта

set(SOURCE_EXE main.c)		# Установка переменной со списком исходников для исполняемого файла, чтобы разыменовать и
                            # вытащить значение переменной используется ${имя_переменной}
set(SOURCE_LIB functions.c)			# Тоже самое, но для библиотеки

add_library(MY_LIB STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем MY_LIB из SOURCE_LIB (functions.c)

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(main MY_LIB)		# Линковка программы с библиотекой
```
Из нового здесь - это библиотеки и их линковка, мы их пока не проходили и все что стоит о них знать, так то, что библиотеки бывают как память (массивы) статические и динамические. Чтобы собрать **статическую библиотеку** используем слово **STATIC** в add_library(), для **динамической SHARED**. В данном примере мы засунули в библиотеку наш файл с некоторыми функциями и для того чтобы наш основной файл работал с функциями из библиотеки их необходимо связать, связывается при помощи функции CMake - target_link_libraries().  
Помимо библиотек есть переменные - устанавливаются они с помощью функции set(), для разименования используется фигурные скобки, а не круглые как в make - ${VARIABLE}.  

Также полезно знать, что переменные cmake хранит у себя в CMakeCache.txt и если удалить этот файл, то при следующем вызове cmake будет генерация cmake с самого начала.       

### Пример 3   

Посмотрим проект, состоящий из нескольких CMakeLists.txt [Пример 3](https://github.com/kruffka/C-Programming/blob/master/2024-2025/9_make_cmake/cmake2)     

Корневой CMakeLists.txt:
```cmake
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
```
Пойдем почти порядку.  
include_directories() - используется для указанию компилятору подобно опции -I пути до заголовочных файлов, чтобы в исходниках в директивах #include не прописывать полные пути до заголовочников.   
add_definitions() - аналог #define в Си и опции -D при компиляции через gcc, мы определяем так некоторые #define для условной компиляции. Например, тот же DEBUG для отладки.      

Следующая вещь полезна когда идет речь о многофайловых проектах, содержащих множество поддиректорий и это:    
add_subdirectory() - указываем путь до CMakeLists.txt находящегося где-то внутри проекта для сборки некоторого отдельного модуля. Вызвав данную функцию cmake нырнет в эту поддиректорию и начнет выполнять оттуда CMakeLists.txt, в котором у нас следующее содержимое:   
```cmake
set(SOURCE_LIB functions.c)	
add_library(MY_LIB SHARED ${SOURCE_LIB})	# Создание дин. библиотеки с именем MY_LIB
```

Некоторые часто используемые переменные в CMake:    
CMAKE_BUILD_TYPE: Типичные значения включают Debug, Release, RelWithDebInfoи MinSizeRel, но также можно определить свои типы сборки.   
1. Release: Высокий уровень оптимизации, без отладочной информации.  
2. Debug: Без оптимизаций, содержит отладочную информацию для дебага.  
3. RelWithDebInfo: Оптимизирован, но содержит отладочную инфу.  
4. MinSizeRel: Тоже что и Release, но оптимизация здесь заключается в размере файла, чем в скорости.  

Если говорить как компилятор, то флаги будут примерно следующие:    
1. Release: `-O3 -DNDEBUG`  
2. Debug: `-O0 -g`  
3. RelWithDebInfo: `-O2 -g -DNDEBUG`  
4. MinSizeRel: `-Os -DNDEBUG`  
Где определение NDEBUG добавляется к платформам, поддерживающим это (отключает например assert()).   

Переменные в cmake можно присвоить двумя способами, первый через set присвоить в CMakeLists.txt:  
```cmake
set(CMAKE_BUILD_TYPE Release)
```
и второй через опцию при вызове cmake:      
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Так можно придумать способ определения некоторых констант, например воспользуемся условиями в cmake (if() endif()).  
```cmake  
if (${TEST_DEF})  
	add_definitions("-DTEST_DEF=${TEST_DEF}")   
endif()  
```  
Как пользоваться такой конструкцией? просто пишем после переменную через -D:  
```cmake
cmake .. -DTEST_DEF=123
```
Эта запись создаст переменную в cmake и внутри CMakeLists.txt отработает условие и добавится определение TEST_DEF в наш код. При запуске кода увидим новый printf() с test_def равным 123.   

### VSCode и CMake

К слову VSCode умеет и понимает CMake. В VSCode можно установить расширение CMake и запускать cmake и make прям из VSCode по кнопке F7. А также хранить все переменные CMake'а в конфигурационном файле. Это немного удобнее чем всегда таскать с собой кучу опций для сборки проекта в консоли. Ну и появляется интерфейс в самом VSCode, где можно мышкой жмакать собрать проект, очистить и т.д..        
Также кому интересно самостоятельно гуглим и разбираемся:    
https://learn.microsoft.com/ru-ru/vcpkg/get_started/get-started-vscode?pivots=shell-powershell
https://code.visualstudio.com/docs/cpp/cmake-quickstart    
https://stackoverflow.com/questions/73328916/how-to-set-cmake-build-configuration-in-vscode    


### Реальный проект с CMake.   

Как найти какой-нибудь проект с открытым исходным кодом на CMake? Откроем github.com и введем в поиске "language:CMake" или вместо CMake C/C++ и несложно наткнуться на проекты, использующие эту систему сборки. Можно открыть парочку любых и посмотреть что описано в самом CMakeLists.txt. Также очень часто можно встретить в корне файл README.md, в котором описывается как собрать проект используя cmake и пару простых команд в командой строке.                
Например введем snake и выберем язык С в github, а также отсортируем по кол-ву звездочек:     
![image](https://github.com/user-attachments/assets/70d2d995-14d2-47e0-b5a5-2ed2d1353b7f)       
В первом же проекте будет простенький CMakeLists.txt в корне, а также простая команда по сборке         
![image](https://github.com/user-attachments/assets/3c317231-92a2-494d-b30a-12d5945ca79e)       
Но не стоит забывать, что некоторые проекты используют различные библиотеки и зависимости, которые нужно отдельно устанавливать. Такие вещи обычно также описываются в README.md проекта.     

### Ninja

Ninja (с англ. — «ниндзя») — это кроссплатформенная консольная утилита, представляющая из себя систему сборки программного обеспечения из исходного кода. Утилита Ninja была разработана Эваном Мартином, сотрудником компании Google.  
Ninja представляет собой улучшенную и доработанную версию утилиты Make. Главная цель которой — автоматизация сборки и её ускорение, а также ускорение последующих пересборок.   
Короче говоря есть такая утилита как Ninja, она подобна make, только должна быть быстрее make по скорости сборки/пересборки.  Отдельно можно почитать и посмотреть как использовать ninja с cmake.   
[Ссылка на ninja](https://github.com/ninja-build/ninja)   


### Meson  
 
Помимо CMake также можно встретить такую систему сборки как Meson.    
[Meson ссылка](https://mesonbuild.com/)    
[Meson wiki](https://ru.wikipedia.org/wiki/Meson_(%D1%81%D0%B8%D1%81%D1%82%D0%B5%D0%BC%D0%B0_%D1%81%D0%B1%D0%BE%D1%80%D0%BA%D0%B8))     
Оставлю на Meson лишь ссылки для почитать и останавливаться тут долго не будем, т.к. последующие курсы в основном вы столкнетесь с CMake и make.   
