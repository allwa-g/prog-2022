#all:
#	gcc -std=c11 -Werror -Wall main.c playfair.c bmp.c -lm -o ps1
#clean:
#	rm -f *o ps1


# TARGET: DEFENDENCIES
# [TAB] SYSTEM_COMMANDS

CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
OUTPUT=ps1
all: $(OUTPUT)

$(OUTPUT): playfair.o bmp.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) $(LDLIBS) playfair.o bmp.o main.o -lm -o $(OUTPUT)

ps1: playfair.o bmp.o main.o
	$(CC) $(CFLAGS) $(LDLIBS) playfair.o bmp.o main.o -lm -o $(OUTPUT)

main.o: main.c
	gcc $(CFLAGS) -lm -c main.c -o main.o

playfair.o: playfair.c playfair.h
	gcc $(CFLAGS) -lm -c playfair.c -o playfair.o

bmp.o: bmp.c bmp.h
	gcc $(CFLAGS) -lm -c bmp.c -o bmp.o

tests: bmp.o tests_bmp.c
	$(CC) $(CFLAGS) bmp.c tests_bmp.c $(LDLIBS) -o $@
	./tests


clean:
	rm -rf *.o $(OUTPUT) tests

