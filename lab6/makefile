all: main
 
main: tablice.o menu.o main.o
	g++ tablice.o menu.o main.o -o main

tablice.o: tablice.cpp tablice.h Ikomorka.h komorkaInt.h komorkaStr.h komorkaDbl.h
	g++ tablice.cpp -c -o tablice.o

menu.o: menu.cpp menu.h
	g++ menu.cpp -c -o menu.o

main.o: main.cpp menu.h
	g++ main.cpp -c -o main.o

clean:
	rm -f *.o main
