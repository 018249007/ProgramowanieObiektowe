all: main

main: komorkaDbl.o komorkaInt.o komorkaStr.o tablice.o menu.o main.o
	g++ komorkaDbl.o komorkaStr.o komorkaInt.o tablice.o menu.o main.o -o main

komorkaDbl.o: komorkaDbl.cpp komorkaDbl.h komorka.h
	g++ komorkaDbl.cpp -c -o komorkaDbl.o

komorkaInt.o: komorkaInt.cpp komorkaInt.h komorka.h
	g++ komorkaInt.cpp -c -o komorkaInt.o

komorkaStr.o: komorkaStr.cpp komorkaStr.h komorka.h
	g++ komorkaStr.cpp -c -o komorkaStr.o

tablice.o: tablice.cpp tablice.h
	g++ tablice.cpp -c -o tablice.o

menu.o: menu.cpp menu.h
	g++ menu.cpp -c -o menu.o

main.o: main.cpp menu.h
	g++ main.cpp -c -o main.o

clean:
	rm -f *.o main
