CC = gcc
CFLAGS = -Wall -g

# List of object files
OBJS = main_BTREE.o insert_BTREE.o delete_BTREE.o search_BTREE.o levelorder_BTREE.o

# Executable name
TARGET = btree

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
