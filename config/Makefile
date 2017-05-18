CC=gcc
CFLAGS=-O0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LDFLAGS=-lglib-2.0

main: main.c config.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
