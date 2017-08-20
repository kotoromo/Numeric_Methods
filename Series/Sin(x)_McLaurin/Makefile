CC = gcc
CFLAGS = -Wall -g
DEPS = util.h
OBJ = main.o util.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

./bin/sin: $(OBJ)
	gcc $(CFLAGS) -o $@ $^ -lm
