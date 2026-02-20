
program: main.o date.o
	g++ -g main.o date.o -o program

main.o: main.cpp date.h
	g++ -g -c main.cpp

date.o: date.h date.cpp 
	g++ -g -c date.cpp

clean:
	rm program
	rm *.o

run: program
	./program

debug: program
	gdb program

valgrind: program
	valgrind --leakcheck=full ./program
