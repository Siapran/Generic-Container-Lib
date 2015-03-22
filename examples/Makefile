CC=gcc
CFLAGS=-W -Wall -std=c89
LDFLAGS=
EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)


all: $(EXEC)

main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean rmproper

clean:
	@rm -rf $(OBJ)

rmproper: clean
	@rm -rf $(EXEC)

main.o: gcl.h gcl/vector.h gcl/vector.def gcl/map.h gcl/map.def
