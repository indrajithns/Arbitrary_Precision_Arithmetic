# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Object files
OBJ = main.o dlist.o operations.o

# Target executable
TARGET = apc

# Default target
all: $(TARGET)

# Build the executable by linking object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile each .c file to a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f *.o $(TARGET)

