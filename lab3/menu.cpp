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
				odczyt(arr);
				cout << "Zakonczono wczytywanie\n";
				break;
			case 2:
				int kolumny, wiersze;
				cout << "Podaj liczbe kolumn -> ";
				cin >> kolumny;
				cout << "Podaj liczbe wierszy -> ";
				cin >> wiersze;
				nowa_tablica(arr, kolumny, wiersze);
				break;
			case 3:
				zapis(*arr);
				cout << "Zapisano tablice\n";
				break;
			case 4:
				wypisz(*arr);
				break;
			case 5:
				int ktory_w, ktory_k, nowy;
				cout << "Zakres elementow:\nLiczba kolumn -> " << arr->kolumny << endl << "Liczba wierszy -> " << arr->wiersze << endl;
				wypisz(*arr);
				cout << "Ktory element zmienic?\nKolumna -> ";
				cin >> ktory_k;
				cout << "Wiersz -> ";
				cin >> ktory_w;
				if ((ktory_k>arr->kolumny)||(ktory_k<1)||(ktory_w>arr->wiersze)||(ktory_k<1))
				{
			                cout << "Numer elementu poza zakresem tablicy\n";
					break;
				}
				else
			        {
                			cout << "Nowy element: ";
                			cin >> nowy;
				}
				zmien_element(arr, ktory_w, ktory_k, nowy);
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
				if((n_kolumny==arr->kolumny)&&(n_wiersze==arr->wiersze))
			        {
        			        cout << "Rozmiary takie same, nic nie zmieniono\n";
                			break;
        			}
				if((n_kolumny<arr->kolumny)||(n_wiersze<arr->wiersze))
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
					zmien_rozmiar(arr, n_kolumny, n_wiersze);
				break;
			case 7:
				sumuj_k(*arr);
				break;
			case 8:
				sumuj_w(*arr);
				break;
			case 9:
				naj_k(*arr);
				break;
			case 10:
				naj_w(*arr);
				break;
			case 11:
				srednia_k(*arr);
				break;
			case 12:
				srednia_w(*arr);
				break;
			default:
				wybor=0;
				free(arr->tab);
				break;
		}
	}
}
