CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = src/entity.c src/list.c
TEST_SRC = test/test.c

APP = app
TEST_APP = test_app

.PHONY: all test clean

all:
	$(CC) $(CFLAGS) src/main.c $(SRC) -o $(APP)

test:
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(TEST_APP)
	./$(TEST_APP)

clean:
	rm -f $(APP) $(TEST_APP)