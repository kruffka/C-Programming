.PHONY: clean all

CC = gcc 
CFLAGS = -Wall    
TARGET = main   
SOURCE_DIR = src

all: $(TARGET)

$(TARGET): main.o init.o utils.o
	$(CC) -o $(TARGET) main.o init.o utils.o
	
main.o: app/main.c
	$(CC) -c app/main.c -o main.o -I ./include

init.o: $(SOURCE_DIR)/init.c
	$(CC) -c $(SOURCE_DIR)/init.c -o init.o -I ./include

utils.o: $(SOURCE_DIR)/utils.c
	$(CC) -c $(SOURCE_DIR)/utils.c -o utils.o -I ./include

clean:
	rm -rf *.o $(TARGET)