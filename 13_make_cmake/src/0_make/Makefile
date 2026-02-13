main: main.o init.o utils.o
	gcc -o main main.o init.o utils.o
	
main.o: app/main.c
	gcc -c app/main.c -o main.o -I ./include

init.o: src/init.c
	gcc -c src/init.c -o init.o -I ./include

utils.o: src/utils.c
	gcc -c src/utils.c -o utils.o -I ./include

# - комментарий
# main - цель (таргет), то что хотим получить
# : main.o functions.o - зависимости, то что нам нужно, чтобы получить цель
# gcc ... - команда для получения цели