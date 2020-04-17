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
			int ktory, nowy;
			cout << "Zakres elementow: 1 - " << rozmiar << endl;
			wypisz(tab, rozmiar);
			cout << "Ktory element zmienic? -> ";
			cin >> ktory;
			if ((ktory>rozmiar)||(ktory<1))
			{
                		cout << "Numer elementu poza zakresem tablicy\n";
				break;
			}
			cout << "Nowy element: ";
                	cin >> nowy;
			zmien_element(tab, ktory, rozmiar, nowy);
			break;

			case 4:
			int n_rozmiar, decyzja;
			cout << "Nowy rozmiar -> ";
			cin >> n_rozmiar;
			if(n_rozmiar<1)
			{
				cout << "Rozmiar nie moze byc mniejszy od 1\n";
				break;
			}
			if(n_rozmiar==rozmiar)
			{
				cout << "Rozmiary takie same, nic nie zmieniono\n";
				break;
			}
			if(n_rozmiar<rozmiar)
			{
                                cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
                                cout << "Tak -> 1\nNie -> 0\n";
                              	cin >> decyzja;
			}
			if(decyzja==1)
				tab=zmien_rozmiar(tab, &rozmiar, n_rozmiar);
			else
				cout << "Nic nie zmieniono\n";
			break;

			default:
			wybor=0;
			break;
		}
	}
}
