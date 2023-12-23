CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = super_tic_tac_toe

SRC = main.c input.c gamePlay.c display.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	#$(EXEC)
	$(RM) $(OBJ)

# Detect the operating system for the 'clean' target
ifeq ($(OS),Windows_NT)
    #EXEC = super_tic_tac_toe.exe
    RM = del /Q
else
    #EXEC = ./super_tic_tac_toe
    RM = rm -f
endif
