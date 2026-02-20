
program: main.o date.o address.o
	g++ -g main.o date.o address.o -o program

main.o: main.cpp date.h address.h
	g++ -g -c main.cpp

date.o: date.h date.cpp 
	g++ -g -c date.cpp

address.o: address.h address.cpp
	g++ -g -c address.cpp

clean:
	rm program
	rm *.o

run: program
	./program

debug: program
	gdb program

valgrind: program
	valgrind --leakcheck=full ./program
