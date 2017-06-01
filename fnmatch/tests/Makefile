ROOTDIR=../
CC=gcc
CFLAGS=-I$(ROOTDIR) -ggdb -O0
LDFLAGS=

TESTS=$(shell ls | egrep '^test[0-9]+.c$$' | awk '{split($$0,a,"."); print a[1] }' | sort -n)

all: $(TESTS)

SRCS=$(ROOTDIR)/fnmatch.c 

%:%.c $(SRCS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	for dir in $(TESTS); do\
		rm -rf $$dir; \
	done
