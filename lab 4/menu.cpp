#include "tablice.h"

void menu(Tablica* arr)
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
		cout << "Sumuj kolumny -> 7\n";
		cout << "Sumuj wiersze -> 8\n";
		cout << "Najmniejsze i najwieksze wartosci w kolumach -> 9\n";
		cout << "Najmniejsze i najwieksze wartosci w wierszach -> 10\n";
		cout << "Srednie wartosci dla kolumn -> 11\n";
		cout << "Srednie wartosci dla wierszy -> 12\n";
		cout << "Wyjscie -> 0\n";
		cout << "======================" << endl << endl;
		cout << "Co zrobic? -> ";
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{	
			case 1:
				arr->odczyt();
				cout << "Zakonczono wczytywanie\n";
				break;
			case 2:
				int kolumny, wiersze;
				cout << "Podaj liczbe kolumn -> ";
				cin >> kolumny;
				if (kolumny < 1)
				{
					cout << "Liczba nie moze byc mniejsza od 1\n";
					break;
				}
				cout << "Podaj liczbe wierszy -> ";
				cin >> wiersze;
				if (wiersze < 1)
				{
					cout << "Liczba nie moze byc mniejsza od 1\n";
					break;
				}
				arr->zwolnij_pamiec();
				arr = new Tablica(kolumny, wiersze);
				break;
			case 3:
				arr->zapis();
				cout << "Zapisano tablice\n";
				break;
			case 4:
				arr->wypisz();
				break;
			case 5:
				int ktory_w, ktory_k, nowy;
				cout << "Zakres elementow:\nLiczba kolumn -> " << arr->ile_k() << endl << "Liczba wierszy -> " << arr->ile_w() << endl;
				arr->wypisz();
				cout << "Ktory element zmienic?\nKolumna -> ";
				cin >> ktory_k;
				cout << "Wiersz -> ";
				cin >> ktory_w;
				if ((ktory_k>arr->ile_k())||(ktory_k<1)||(ktory_w>arr->ile_w())||(ktory_k<1))
				{
			                cout << "Numer elementu poza zakresem tablicy\n";
					break;
				}
				else
			        {
                			cout << "Nowy element: ";
                			cin >> nowy;
				}
				arr->zmien_element(ktory_w, ktory_k, nowy);
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
				if((n_kolumny==arr->ile_k())&&(n_wiersze==arr->ile_w()))
			        {
        			        cout << "Rozmiary takie same, nic nie zmieniono\n";
                			break;
        			}
				if((n_kolumny<arr->ile_k())||(n_wiersze<arr->ile_w()))
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
					arr->zmien_rozmiar(n_kolumny, n_wiersze);
				break;
			case 7:
				arr->sumuj_k();
				break;
			case 8:
				arr->sumuj_w();
				break;
			case 9:
				arr->naj_k();
				break;
			case 10:
				arr->naj_w();
				break;
			case 11:
				arr->srednia_k();
				break;
			case 12:
				arr->srednia_w();
				break;
			default:
				wybor=0;
				break;
		}
	}
}
