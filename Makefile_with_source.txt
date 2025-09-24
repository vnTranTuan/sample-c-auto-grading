# DIRS AND FILES - Tên các thư mục
SRC_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
LIB_DIR = lib
CUNIT_SRC_DIR = cunit-src

# EXECUTABLES - Tên chương trình kiểm thử (.exe)
TEST_RUNNER = test_runner
CUNIT_LIB = $(LIB_DIR)/libCUnit.a

# CFLAGS AND LDFLAGS - Tên trình biên dịch và các cờ
CC = gcc
CFLAGS = -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lCUnit

# CUNIT SOURCE FILES - Các source file của CUnit
CUNIT_SRC = $(wildcard $(CUNIT_SRC_DIR)/*.c)
CUNIT_OBJS = $(CUNIT_SRC:.c=.o)

# BUILD RULE : Rule mặc định: BUILD TEST
all: $(TEST_RUNNER)

# Rule to compile CUnit source files into a static library
# Biên dịch CUnit source files thành thư viện tĩnh
$(CUNIT_LIB): $(CUNIT_SRC)
	$(CC) -c $(CUNIT_SRC) $(CFLAGS)
	ar rcs $@ $(notdir $(CUNIT_OBJS))
	rm -f $(notdir $(CUNIT_OBJS))

# Rule to compile the test runner executable
# Rule để biên dịch chương trình kiểm thử
$(TEST_RUNNER): $(TEST_DIR)/test_tinh_tong.c $(SRC_DIR)/my_functions.c $(CUNIT_LIB)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Cleanup rule - Rule để dọn dẹp các file đã biên dịch
clean:
	rm -f $(TEST_RUNNER) $(CUNIT_LIB)