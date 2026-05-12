CC = clang
CFLAGS = -Wall -Wextra -std=c11

all: clean prep compile

.PHONY: test

prep:
	mkdir -p dist

test:
	mkdir -p dist
	$(CC) $(CFLAGS) test/test.c src/lib.c -o dist/test.bin
	
compile:
	$(CC) $(CFLAGS) src/main.c src/lib.c -o dist/main.bin

clean:
	rm -rf dist