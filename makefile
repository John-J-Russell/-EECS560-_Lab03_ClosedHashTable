lab3: main.o ClosedHashtable.o
	g++ -g -Wall -std=c++11 main.o ClosedHashtable.o -o lab3

main.o: main.cpp ClosedHashtable.h
	g++ -g =Wall -std=c++11 -c main.cpp

ClosedHashtable.o: ClosedHashtable.cpp
	g++ -g -Wall -std=c++11 -c ClosedHashtable.cpp

clean:
	rm *.o lab3
