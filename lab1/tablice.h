#ifndef TABLICE_H
#define TABLICE_H
#define BAZA "Baza.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int** nowa_tablica(int, int);
int** odczyt(int*, int*);
void zapis(int**, int*, int*);
void wypisz(int**, int, int);
void zmien_element(int**, int, int, int, int);
int** zmien_rozmiar(int**, int*, int*, int, int);

#endif
