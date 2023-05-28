CC=gcc
CFLAGS= -Wall -ansi 
LDFLAGS= -g -lrt -lm

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

FILE = ./data/output.txt

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRCS))

EXECUTABLE = lzw

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

-include $(DEPS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

run: $(EXECUTABLE)
	@./$(EXECUTABLE)

clean:
	$(RM) $(OBJS) $(EXECUTABLE) $(FILE)