# Compiler
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
MAIN_NAME = main.c
# Archiver (dùng để tạo thư viện tĩnh)
AR = ar
ARFLAGS = rcs

# Thư mục chứa source và build
SRC_DIR = src
BUILD_DIR = build

# Tên thư viện tĩnh
LIB_NAME = libmymath.a

# Tên file thực thi
EXE_NAME = myprogram

# Danh sách các source file
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Danh sách các file .o tương ứng
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
# Target mặc định: build tất cả object files và tạo thư viện
all: build creatLib complite
# Tạo thư mục build nếu chưa có
$(BUILD_DIR):
	@mkdir $(BUILD_DIR)
# Biên dịch tất cả file .c thành file .o tương ứng trong build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
# Target build để biên dịch tất cả object files
build: $(OBJS)
# Tạo thư viện tĩnh từ các file .o

print-vars:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"

creatLib: $(OBJS)
	$(AR) $(ARFLAGS) $(BUILD_DIR)/$(LIB_NAME) $(OBJS)
# Liên kết thư viện tĩnh với chương trình chính
compile: creatLib
	$(CC) $(CFLAGS) $(MAIN_NAME) $(BUILD_DIR)/$(LIB_NAME) -o $(BUILD_DIR)/$(EXE_NAME)
# Xóa toàn bộ file object và thư viện


