CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = lab10

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o $(TARGET) lab10.txt lab10.bin