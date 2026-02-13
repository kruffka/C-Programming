.PHONY: clean # Если у нас будет файл clean в директории и у нас есть target clean, то для работы таргета нужно добавить .PHONY

all: main

main: main.o init.o utils.o
	gcc -o main main.o init.o utils.o
	
main.o: app/main.c
	gcc -c app/main.c -o main.o -I ./include

init.o: src/init.c
	gcc -c src/init.c -o init.o -I ./include

utils.o: src/utils.c
	gcc -c src/utils.c -o utils.o -I ./include

clean:
	rm -rf *.o main

run: all
	./main