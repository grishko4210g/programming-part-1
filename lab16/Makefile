CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC = src/list.c src/entity.c src/menu.c
MAIN = src/main.c
TEST = test/test.c

OUT = main
TEST_OUT = test_bin

all: $(OUT)

$(OUT): $(SRC) $(MAIN)
	$(CC) $(CFLAGS) $(SRC) $(MAIN) -o $(OUT)

test: $(TEST) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(TEST) -o $(TEST_OUT)

run:
	./$(OUT)

run_test:
	./$(TEST_OUT)

clean:
	rm -f $(OUT) $(TEST_OUT)