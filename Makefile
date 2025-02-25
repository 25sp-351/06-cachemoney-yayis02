CC = gcc
CFLAGS = -Wall -g
EXEC = cache_money
SRC = cache_money.c
OBJ = cache_money.o
OUTPUT = output.txt

# Targets

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

run: $(EXEC)
	./$(EXEC) > $(OUTPUT)
	cat $(OUTPUT)

clean:
	rm -f $(OBJ) $(EXEC) $(OUTPUT)

.PHONY: all run clean
