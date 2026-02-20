//make file

Program: main.o student.o date.o address.o
	g++ -g main.o student.o date.o address.o -o Program

main.o: main.cpp student.h date.h address.h
	g++ -g -c main.cpp

student.o: student.h student.cpp
	g++ -g -c student.cpp

date.o: date.h date.cpp student.h
	g++ -g -c date.cpp

address.o: address.h address.cpp student.h
	g++ -g -c address.cpp

clean:
	rm Program
	rm *.o

run: Program
	./Program

debug: Program
	gdb Program
