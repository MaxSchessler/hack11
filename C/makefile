all: airportTester


airportTester: airport.o 
	gcc airport.o airportTester.c -o airportTester

airport.o: airport.c airport.h 
	gcc -c airport.c -lm

clean: 
	rm -rf *.o airportTester