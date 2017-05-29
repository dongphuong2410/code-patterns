CC=gcc
CFLAGS=
LDFLAGS=

.PHONY : clean

SRC=test1 test2

all: test1 test2

%:%.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	for file in $(SRC); do\
		rm -rf $$file; \
	done
