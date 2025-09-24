# DIRS AND FILES - Tên các thư mục
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
LIB_DIR = lib

# EXECUTABLES - Tên chương trình kiểm thử (.exe)
TEST_RUNNER = test_runner

# CFLAGS AND LDFLAGS - Tên trình biên dịch và các cờ
CC = gcc
CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lCUnit

# BUILD RULE : Rule mặc định: BUILD TEST
all: $(TEST_RUNNER)

# Rule to compile the test runner executable
# Rule để biên dịch chương trình kiểm thử
$(TEST_RUNNER): $(TEST_DIR)/test_tinh_tong.c $(SRC_DIR)/my_functions.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Cleanup rule - Rule để dọn dẹp các file đã biên dịch
clean:
	rm -f $(TEST_RUNNER)

