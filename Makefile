CC = gcc
CFLAGS = -g -c -m32 -pthread
AR = ar -rc
RANLIB = ranlib

all: libvm.a

libvm.a: vm.o
	$(AR) libvm.a vm.o
	$(RANLIB) libvm.a

vm.o: vm.c vm.h
	$(CC) $(CFLAGS) -o vm.o vm.c

clean:
	rm -rf *.o *.a
