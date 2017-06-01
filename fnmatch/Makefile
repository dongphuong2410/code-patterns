CC=gcc
CFLAGS=
LDFLAGS=

SRC=tests

.PHONY : $(SRC) clean

all: $(SRC)

$(SRC):
	$(MAKE) -C $@ clean all

clean:
	for dir in $(SRC); do\
		$(MAKE) -C $$dir -f Makefile $@; \
	done

# define TESTDIR
TESTDIR=tests

# include unittest Makefile
include unittest.mk
