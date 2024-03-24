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