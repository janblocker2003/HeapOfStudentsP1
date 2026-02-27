
program: main.o date.o address.o student.o
	g++ -g main.o date.o address.o student.o -o program

main.o: main.cpp date.h address.h student.h
	g++ -g -c main.cpp

student.o: student.h date.h address.h student.cpp
	g++ -g -c student.cpp

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
	valgrind --leak-check=full ./program
