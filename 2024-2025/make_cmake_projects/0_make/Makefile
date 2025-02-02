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