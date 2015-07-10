CC=g++

CFLAGS=-c -Wall

all: diode_client

diode_client: main.o 
	$(CC) main.o -o diode_client

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o diode_client
