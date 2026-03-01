CC = gcc
CFLAGS = -g -Wall -Wextra -pthread
SRC_DIR = src
BUILD_DIR = builds
TESTS_DIR = tests
TEST_LOGS = $(TESTS_DIR)/logs

SRCS = $(filter-out %mylib.c %main.c, $(wildcard $(SRC_DIR)/lab_*/*.c))
BINS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))
TEST_SCRIPTS = $(wildcard $(TESTS_DIR)/test_lab*.sh)

.PHONY: all clean test

all: $(BINS) $(BUILD_DIR)/lab_6/main

$(BUILD_DIR)/lab_6/libmylib.so: $(SRC_DIR)/lab_6/mylib.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC -shared $< -o $@

$(BUILD_DIR)/lab_6/main: $(SRC_DIR)/lab_6/main.c $(BUILD_DIR)/lab_6/libmylib.so
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -L$(BUILD_DIR)/lab_6 -lmylib -Wl,-rpath,'$$ORIGIN' -o $@

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

lab_%:
	@$(MAKE) $(filter $(BUILD_DIR)/lab_$*%, $(BINS) $(BUILD_DIR)/lab_6/main)

test: all
	@mkdir -p $(TEST_LOGS)
	@for test in $(TEST_SCRIPTS); do \
		echo "--- Running $$test ---"; \
		bash $$test; \
	done

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TEST_LOGS)
