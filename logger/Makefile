CC=gcc
CFLAGS=
LDFLAGS=

test: test.c logger.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) -DCURRENT_LEVEL=LV_WARN

clean:
	rm -rf test
