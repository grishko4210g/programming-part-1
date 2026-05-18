CC = clang
CFLAGS = -Wall -Wextra -std=c11

all: clean prep compile

.PHONY: test

prep:
	mkdir -p dist

test:
	clang -Wall -Wextra -std=c11 test/test.c src/lib.c -o test.bin
	./test.bin
	
compile:
	$(CC) $(CFLAGS) src/main.c src/lib.c -o dist/main.bin

clean:
	rm -rf dist