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