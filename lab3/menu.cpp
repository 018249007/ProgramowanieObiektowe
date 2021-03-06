#include "tablice.h"

void menu(Tablica* arr)
{
	int wybor=99;
	int err = 0;
	while(wybor!=0)
	{	
		cout << endl << "======================" << endl;
		cout << "Odczyt z pliku -> 1\n";
		cout << "Nowa tablica -> 2\n";
		cout << "Zapis do pliku -> 3\n";
		cout << "Wypisz zawartosc -> 4\n";
		cout << "Zmien element -> 5\n";
		cout << "Zmien rozmiar -> 6\n";
		cout << "Sumowanie -> 7\n";
		cout << "Najmniejsze i najwieksze warosci -> 8\n";
		cout << "Srednie wartosci -> 9\n";
		cout << "Wyjscie -> 0\n";
		cout << "======================" << endl << endl;
		cout << "Co zrobic? -> ";
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{	
			case 1:
				err = odczyt(arr);
				if (err)
				{
					cout << "Brak danych\n";
				}
				else
				{
					cout << "Zakonczono wczytywanie\n";
				}
				break;
			case 2:
			{
				int kolumny, wiersze;
				cout << "Podaj liczbe kolumn -> ";
				cin >> kolumny;
				cout << "Podaj liczbe wierszy -> ";
				cin >> wiersze;
				cout << endl;
				err = nowa_tablica(arr, kolumny, wiersze);
				if (err)
				{
					cout << "Nieprawidlowa wartosc\n";
				}
				break;
			}
			case 3:
				zapis(*arr);
				cout << "Zapisano tablice\n";
				break;
			case 4:
				wypisz(*arr);
				break;
			case 5:
			{
				int ktory_w, ktory_k, nowy;
				cout << "Zakres elementow:\nLiczba kolumn -> " << arr->kolumny << endl << "Liczba wierszy -> " << arr->wiersze << endl << endl;
				wypisz(*arr);
				cout << endl;
				cout << "Ktory element zmienic?\nKolumna -> ";
				cin >> ktory_k;
				cout << "Wiersz -> ";
				cin >> ktory_w;
				cout << "Nowy element: ";
				cin >> nowy;
				cout << endl;
				err = zmien_element(arr, ktory_w, ktory_k, nowy);
				if (err)
				{
					cout << "Nieprawidlowa wartosc\n";
					break;
				}
				else
				{
					cout << "Pomyslnie zmieniono\n";
				}
				break;
			}
			case 6:
			{
				int n_kolumny, n_wiersze;
				cout << "Nowa liczba kolumn -> ";
				cin >> n_kolumny;
				cout << "Nowa liczba wierszy -> ";
				cin >> n_wiersze;
				cout << endl;
				err = zmien_rozmiar(arr, n_kolumny, n_wiersze);
				if (err)
				{
					cout << "Nieprawidlowa wartosc\n";
					break;
				}
				else
				{
					cout << "Pomyslnie zmieniono\n";
				}
				break;
			}
			case 7:
			{
				int rowcol, numer;
				int wynik = 0;
				cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
				cin >> rowcol;
				cout << endl;
				if (rowcol == 1)
				{
					wypisz(*arr);
					cout << endl;
					cout << "Zakres: 1 -> " << arr->kolumny << endl << "Numer kolumny: ";
					cin >> numer;
					cout << endl;
					err = sumuj_k(*arr, numer, &wynik);
					if (err)
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
					cout << "Suma: " << wynik << endl;
				}
				if (rowcol == 2)
				{
					wypisz(*arr);
					cout << endl;
					cout << "Zakres: 1 -> " << arr->wiersze << endl << "Numer wiersza: ";
					cin >> numer;
					cout << endl;
					err = sumuj_w(*arr, numer, &wynik);
					if (err)
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
					cout << "Suma: " << wynik << endl;
				}
				else
				{
					cout << "Nieprawidlowa wartosc\n";
				}
				break;
			}
			case 8:
			{
				int minmax, rowcol, numer;
				int wynik = 0;
				cout << "Najmniejsza -> 1\tNajwieksza -> 2\nDecyzja: ";
				cin >> minmax;
				cout << endl;
				if (minmax == 1)
				{
					cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
					cin >> rowcol;
					cout << endl;
					if (rowcol == 1)
					{
						wypisz(*arr);
						cout << endl;
						cout << "Zakres: 1 -> " << arr->kolumny << endl << "Numer kolumny: ";
						cin >> numer;
						cout << endl;
						err = min_k(*arr, numer, &wynik);
						if (err)
						{
							cout << "Nieprawidlowa wartosc\n";
							break;
						}
						cout << "Szukana wartosc: " << wynik << endl;
						break;
					}
					if (rowcol == 2)
					{
						wypisz(*arr);
						cout << endl;
						cout << "Zakres: 1 -> " << arr->wiersze << endl << "Numer wiersza: ";
						cin >> numer;
						cout << endl;
						err = min_w(*arr, numer, &wynik);
						if (err)
						{
							cout << "Nieprawidlowa wartosc\n";
							break;
						}
						cout << endl;
						cout << "Szukana wartosc: " << wynik << endl;
						break;
					}
					else
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
				}
				if (minmax == 2)
				{
					cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
					cin >> rowcol;
					cout << endl;
					if (rowcol == 1)
					{
						wypisz(*arr);
						cout << endl;
						cout << "Zakres: 1 -> " << arr->kolumny << endl << "Numer kolumny: ";
						cin >> numer;
						cout << endl;
						err = max_k(*arr, numer, &wynik);
						if (err)
						{
							cout << "Nieprawidlowa wartosc\n";
							break;
						}
						cout << endl;
						cout << "Szukana wartosc: " << wynik << endl;
						break;
					}
					if (rowcol == 2)
					{
						wypisz(*arr);
						cout << endl;
						cout << "Zakres: 1 -> " << arr->wiersze << endl << "Numer wiersza: ";
						cin >> numer;
						cout << endl;
						err = max_w(*arr, numer, &wynik);
						if (err)
						{
							cout << "Nieprawidlowa wartosc\n";
							break;
						}
						cout << endl;
						cout << "Szukana wartosc: " << wynik << endl;
						break;
					}
					else
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
				}
				else
				{
					cout << "Nieprawidlowa wartosc\n";
				}
				break;
			}
			case 9:
			{
				int rowcol, numer;
				float wynik = 0;
				cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
				cin >> rowcol;
				cout << endl;
				if (rowcol == 1)
				{
					wypisz(*arr);
					cout << endl;
					cout << "Zakres: 1 -> " << arr->kolumny << endl << "Numer kolumny: ";
					cin >> numer;
					cout << endl;
					err = srednia_k(*arr, numer, &wynik);
					if (err)
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
					cout << endl;
					cout << "Srednia wartosc: " << wynik << endl;
					break;
				}
				if (rowcol == 2)
				{
					wypisz(*arr);
					cout << endl;
					cout << "Zakres: 1 -> " << arr->wiersze << endl << "Numer wiersza: ";
					cin >> numer;
					cout << endl;
					err = srednia_w(*arr, numer, &wynik);
					if (err)
					{
						cout << "Nieprawidlowa wartosc\n";
						break;
					}
					cout << endl;
					cout << "Srednia wartosc: " << wynik << endl;
					break;
				}
				else
				{
					cout << "Nieprawidlowa wartosc\n";
				}
				break;
			}
			default:
				wybor=0;
				break;
		}
	}
}
