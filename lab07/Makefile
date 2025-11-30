CC = gcc
CFLAGS = -Wall -Iinclude -IUnity/include -fprofile-arcs -ftest-coverage
LDFLAGS = -L. -fprofile-arcs -ftest-coverage
SRC_DIR = src
TEST_DIR = test
UNITY_SRC = Unity/src/unity.c

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:.c=.o)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

EXECUTABLE = main
TEST_EXECUTABLE = run_test

.PHONY: all clean test

all: $(EXECUTABLE)

$(EXECUTABLE) : main.o libpoject.a
	$(CC) $(CFLAGS) -o $@ $^

libpoject.a: $(OBJ_FILES)
	ar rcs $@ $^

main.o: mainc.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES) libpoject.a
	$(CC) $(CFLAGS) -DUNITY_INCLUDE_DOUBLE -DUNITY_DOUBLE_TYPE=double \
	-o $@ $(UNITY_SRC) $^ -lm

clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_EXECUTABLE) *.o libpoject.a *.gcno *.gcda *.gcov coverage.info
	rm -rf coverage_report
