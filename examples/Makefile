CC=gcc
CFLAGS=-W -Wall -std=c89
LDFLAGS=
EXEC= word_count stack


all: $(EXEC)

$(EXEC): %: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean rmproper

clean:
	@rm -f *.o *~

rmproper: clean
	@rm -f $(EXEC)

stack.o: gcl.h gcl/vector.h gcl/vector.def gcl/map.h
stack.o: gcl/map.def gcl/deque.h gcl/deque.def
word_count.o: gcl.h gcl/vector.h
word_count.o: gcl/vector.def gcl/map.h gcl/map.def gcl/deque.h gcl/deque.def
