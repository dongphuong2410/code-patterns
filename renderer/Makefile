CC=gcc
CFLAGS=-ggdb -O0
LDFLAGS=

all: renderer

renderer: renderer.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clear:
	rm -f renderer
