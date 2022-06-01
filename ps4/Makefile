CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wconversion
LDLIBS=-lm
OUTPUT=make

all: $(OUTPUT)

$(OUTPUT): bmp.o transformations.o
		cppcheck --enable=performance, unusedFunction --error-exitcode=1 *.c
		gcc $(CFLAGS) bmp.o transformations.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
		gcc $(CFLAGS) -c main.c -o main.o

bmp.o: bmp.c bmp.h
		gcc $(CFLAGS) -c bmp.c -o bmp.o

transformations.o:  transformations.c  transformations.h
		gcc $(CFLAGS) -c  transformations.c -o  transformations.o

clean:
		rm -rf $(OUTPUT) *.o
