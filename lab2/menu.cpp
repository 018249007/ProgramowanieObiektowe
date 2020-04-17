#include "tablice.h"

void menu(int** tab, int *kolumny, int *wiersze)
{
	int wybor=99;
	while(wybor!=0)
	{	
		cout << endl << "======================" << endl;
		cout << "Odczyt z pliku -> 1\n";
		cout << "Nowa tablica -> 2\n";
		cout << "Zapis do pliku -> 3\n";
		cout << "Wypisz zawartosc -> 4\n";
		cout << "Zmien element -> 5\n";
		cout << "Zmien rozmiar -> 6\n";
		cout << "Wyjscie -> 0\n";
		cout << "======================" << endl << endl;
		cout << "Co zrobic? -> ";
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{	
			case 1:
				tab = odczyt(kolumny, wiersze);
				cout << "Zakonczono wczytywanie\n";
				break;
			case 2:
				cout << "Podaj liczbe kolumn -> ";
				cin >> *kolumny;
				cout << "Podaj liczbe wierszy -> ";
				cin >> *wiersze;
				tab = nowa_tablica(*kolumny, *wiersze);
				break;
			case 3:
				zapis(tab, kolumny, wiersze);
				cout << "Zapisano tablice\n";
				break;
			case 4:
				wypisz(tab, *kolumny, *wiersze);
				break;
			case 5:
				int ktory_w, ktory_k, nowy;
				cout << "Zakres elementow:\nLiczba kolumn -> " << *kolumny << endl << "Liczba wierszy -> " << *wiersze << endl;
				wypisz(tab, *kolumny, *wiersze);
				cout << "Ktory element zmienic?\nKolumna -> ";
				cin >> ktory_k;
				cout << "Wiersz -> ";
				cin >> ktory_w;
				if ((ktory_k>*kolumny)||(ktory_k<1)||(ktory_w>*wiersze)||(ktory_k<1))
				{
			                cout << "Numer elementu poza zakresem tablicy\n";
					break;
				}
				else
			        {
                			cout << "Nowy element: ";
                			cin >> nowy;
				}
				zmien_element(tab, ktory_w, ktory_k, *kolumny, *wiersze, nowy);
				break;
			case 6:
				int n_kolumny, n_wiersze, decyzja;
				cout << "Nowa liczba kolumn -> ";
				cin >> n_kolumny;
				cout << "Nowa liczba wierszy -> ";
				cin >> n_wiersze;
				if((n_kolumny < 1) || (n_wiersze <1))
				{
					cout << "Rozmiar nie moze byc mniejszy od 1\n";
					break;
				}
				if((n_kolumny==*kolumny)&&(n_wiersze==*wiersze))
			        {
        			        cout << "Rozmiary takie same, nic nie zmieniono\n";
                			break;
        			}
				if((n_kolumny<*kolumny)||(n_wiersze<*wiersze))
			        {
                			cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
                			cout << "Tak -> 1\nNie -> 0\n";
                			cin >> decyzja;
				}
				if(decyzja==0)
				{
					cout << "Nic nie zmieniono\n";
					break;
				}
				else
					tab=zmien_rozmiar(tab, kolumny, wiersze, n_kolumny, n_wiersze);
				break;
			default:
				wybor=0;
				free(tab);
				break;
		}
	}
}
