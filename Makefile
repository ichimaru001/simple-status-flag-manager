CC = gcc
CFLAGS = -Wall -Wextra

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXEC = status_manager

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)