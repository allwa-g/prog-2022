CFLAGS = -std=c11 -Werror -Wall -Wconversion -lm
OUTPUT = ps2

all : $(OUTPUT)

$(OUTPUT): main.o hof.o k.o ui.o
	gcc $(CFLAGS) main.o hof.o k.o ui.o -lm -o $(OUTPUT)

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o



clean:
	rm -rf *.o $(OUTPUT)
