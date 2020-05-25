all: main

main: komorka.o tablice.o menu.o main.o
	g++ komorka.o tablice.o menu.o main.o -o main

komorka.o: komorka.cpp komorka.h
	g++ komorka.cpp -c -o komorka.o

tablice.o: tablice.cpp tablice.h komorka.h
	g++ tablice.cpp -c -o tablice.o

menu.o: menu.cpp menu.h tablice.h komorka.h
	g++ menu.cpp -c -o menu.o

main.o: main.cpp menu.h tablice.h komorka.h
	g++ main.cpp -c -o main.o

clean:
	rm -f *.o main
