

help:
	$(info make help   - show this message)
	$(info make all    - alternative for: foo large test)
	$(info make foo    - build foo from sources)
	$(info make large  - create large file for test)
	$(info make test   - run test and output results to test.out)
	$(info make clean  - delete all created files)
	@true

CC = gcc
LD = gcc

CSOURCES= \
foo.c

COBJECTS = $(CSOURCES:.c=.o)

.c.o:
	$(CC) -c $< -o $@

foo: $(COBJECTS) 
	$(LD) $(COBJECTS) -o foo

large:
	head -c 5G /dev/zero > large_file

all: foo large test

test:
	echo './foo -l > test.out' > test.out
	echo ''  >> test.out
	./foo -l >> test.out
	echo ''  >> test.out
	echo './foo >> test.out' >> test.out
	echo ''  >> test.out
	./foo >> test.out

clean:
	rm -f foo.o
	rm -f foo
	rm -f large_file
	rm -f test.out
