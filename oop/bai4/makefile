# Compiler
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11

# Directories
SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

# Output executable
TARGET = $(BIN_DIR)/main.exe

# Find all C++ source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Generate object file names
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule (build and run)
all: build run

# Rule to compile the project
build: $(TARGET)

# Link objects to create the executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary directories if not exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	del /s /q obj bin 2>nul || rmdir /s /q obj bin

# Phony targets
.PHONY: all build run clean
