CC=g++

CFLAGS=-c -Wall -I . 

all: diode_controller

diode_controller: main.o commandmanager.o commandresult.o commutator.o diode.o tools.o
	$(CC) main.o commandmanager.o commandresult.o commutator.o diode.o tools.o -o diode_controller

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

command.o: command.cpp
	$(CC) $(CFLAGS) command.cpp

commandmanager.o: commandmanager.cpp
	$(CC) $(CFLAGS) commandmanager.cpp

commandresult.o: commandresult.cpp
	$(CC) $(CFLAGS) commandresult.cpp

diode.o: diode.cpp
	$(CC) $(CFLAGS) diode.cpp

tools.o: tools.cpp
	$(CC) $(CFLAGS) tools.cpp

clean:
	rm -rf *.o diode_controller
