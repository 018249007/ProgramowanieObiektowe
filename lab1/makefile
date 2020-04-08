all: main

main: tablice.o menu.o main.o
	g++ tablice.o menu.o main.o -o main

tablice.o: tablice.cpp tablice.h
	g++ tablice.cpp -c -o tablice.o

menu.o: menu.cpp tablice.h
	g++ menu.cpp -c -o menu.o

main.o: main.cpp tablice.h menu.h
	g++ main.cpp -c -o main.o

clean:
	rm -f *.o
