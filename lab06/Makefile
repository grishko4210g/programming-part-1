CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11 -Iinclude -MMD -MP
LDFLAGS := -lm

BUILD := build
SRC_DIR := src
INC_DIR := include

SRCS := $(wildcard $(SRC_DIR)/*.c) main.c
OBJS := $(patsubst %.c,$(BUILD)/%.o,$(notdir $(SRCS)))
DEPS := $(OBJS:.o=.d)

vpath %.c . $(SRC_DIR)

.PHONY: all exe asm preprocess clean
all: exe

exe: $(BUILD)/app

$(BUILD)/app: $(OBJS) | $(BUILD)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD)/%.o: %.c | $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

asm: | $(BUILD)
	@for s in $(SRCS); do \
		b=$$(basename $${s##*/}); \
		echo " AS $(BUILD)/$$b.s"; \
		$(CC) $(CFLAGS) -S $$s -o $(BUILD)/$$b.s; \
	done

preprocess: | $(BUILD)
	@for s in $(SRCS); do \
		b=$$(basename $${s##*/}); \
		echo " PP $(BUILD)/$$b.i"; \
		$(CC) $(CFLAGS) -E $$s -o $(BUILD)/$$b.i; \
	done

$(BUILD):
	@mkdir -p $(BUILD)

clean:
	@rm -rf $(BUILD)

-include $(DEPS)
