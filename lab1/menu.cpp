#include <iostream>
#include "tablice.h"
using namespace std;

void menu()
{
	int wybor=99;
	while(wybor!=0)
	{	
		cout << endl << "======================" << endl;
		cout << "Nowa tablica -> 1\n";
		cout << "Wypisz zawartosc -> 2\n";
		cout << "Zmien element -> 3\n";
		cout << "Zmien rozmiar -> 4\n";
		cout << "Wyjscie -> 0\n";
		cout << "======================" << endl << endl;
		cout << "Co zrobic? -> ";
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
			case 1:
			int rozmiar;
			int* tab;
			cout << "Podaj rozmiar -> ";
			cin >> rozmiar;
			tab = nowa_tablica(rozmiar);
			break;

			case 2:
			wypisz(tab, rozmiar);
			break;

			case 3:
			int ktory;
			cout << "Zakres elementow: 1 - " << rozmiar << endl;
			wypisz(tab, rozmiar);
			cout << "Ktory element zmienic? -> ";
			cin >> ktory;
			zmien_element(tab, ktory, rozmiar);
			break;

			case 4:
			int n_rozmiar;
			cout << "Nowy rozmiar -> ";
			cin >> n_rozmiar;
			if(n_rozmiar<1)
				cout << "Rozmiar nie moze byc mniejszy od 1\n";
			else
				tab=zmien_rozmiar(tab, &rozmiar, n_rozmiar);
			break;
	
			default:
			wybor=0;
			break;
		}
	}
}
