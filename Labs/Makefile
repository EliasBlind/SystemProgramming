CC = gcc
CFLAGS = -g -Wall -Wextra -pthread
SRC_DIR = src
BUILD_DIR = builds
TEST_LOGS = tests/logs

LABS = $(wildcard $(SRC_DIR)/lab_*)
SRCS = $(wildcard $(SRC_DIR)/lab_*/*.c)
BINS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))

.PHONY: all clean

all: $(BINS)

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

lab_%:
	@$(MAKE) $(filter $(BUILD_DIR)/lab_$*%, $(BINS))

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(TEST_LOGS)
