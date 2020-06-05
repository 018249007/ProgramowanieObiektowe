#include "menu.h"
 
void menu(Tablica* arr)
{
	int wybor = 99;
	int err = 0;
	while (wybor != 0)
	{
		cout << endl << "======================" << endl;
		cout << "Odczyt z pliku -> 1\n";
		cout << "Nowa tablica -> 2\n";
		cout << "Zapis do pliku -> 3\n";
		cout << "Wypisz zawartosc -> 4\n";
		cout << "Zmien element -> 5\n";
		cout << "Zmien rozmiar -> 6\n";
		cout << "Sumowanie -> 7\n";
		cout << "Najmniejsze i najwieksze wartosci -> 8\n";
		cout << "Srednie wartosci -> 9\n";
		cout << "Zmien typ kolumny -> 10\n";
		cout << "Wyjscie -> 0\n";
		cout << "======================" << endl << endl;
		cout << "Co zrobic? -> ";
		cin >> wybor;
		cout << endl;
		switch (wybor)
		{
		case 1:
			err = arr->odczyt();
			if (err)
			{
				cout << "Brak danych\n";
				break;
			}
			cout << "Zakonczono wczytywanie\n";
			break;
		case 2:
		{
			int kolumny, wiersze;
			cout << "Podaj liczbe kolumn -> ";
			cin >> kolumny;
			cout << "Podaj liczbe wierszy -> ";
			cin >> wiersze;
			cout << endl;
			err = arr->nowa_tablica(kolumny, wiersze);
			if (err)
			{
				cout << "Nieprawidlowa wartosc\n";
				break;
			}
			cout << "Pomyslnie utworzono\n";
			break;
		}
		case 3:
			arr->zapisz();
			cout << "Zapisano tablice\n";
			break;
		case 4:
			arr->wypisz();
			break;
		case 5:
		{
			int ktory_w, ktory_k, typ;
			cout << "Zakres elementow:\nLiczba kolumn -> " << arr->ile_k() << endl << "Liczba wierszy -> " << arr->ile_w() << endl;
			arr->wypisz();
			cout << "Ktory element zmienic?\nKolumna -> ";
			cin >> ktory_k;
			cout << "Wiersz -> ";
			cin >> ktory_w;
			err = arr->zwroc_typ(ktory_k, &typ);
			if (err)
			{
				cout << "Nieprawidlowa wartosc\n";
				break;
			}
			if (typ == 1)
			{
				string nowy;
				cout << "Nowy element: ";
				cin.clear();
				cin.ignore(INT16_MAX, '\n');
				getline(cin, nowy);
				arr->zmien_element(ktory_w, ktory_k, nowy);
			}
			else if(typ == 0)
			{
				int nowy;
				cout << "Nowy element: ";
				cin >> nowy;
				arr->zmien_element(ktory_w, ktory_k, nowy);
			}
			else if(typ == 2)
			{
				double nowy;
				cout << "Nowy element: ";
				cin >> nowy;
				arr->zmien_element(ktory_w, ktory_k, nowy);
			}
			cout << "Pomyslnie zmieniono\n";
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
			err = arr->zmien_rozmiar(n_kolumny, n_wiersze);
			if (err)
			{
				cout << "Nieprawidlowa wartosc\n";
				break;
			}
			cout << "Pomyslnie zmieniono\n";
			break;
		}
		case 7:
		{
			int rowcol, numer;
			double wynik = 0;
			cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
			cin >> rowcol;
			cout << endl;
			if (rowcol == 1)
			{
				arr->wypisz();
				cout << endl;
				cout << "Zakres: 1 -> " << arr->ile_k() << endl << "Numer kolumny: ";
				cin >> numer;
				cout << endl;
				err = arr->sumuj_k(numer, &wynik);
				if (err)
				{
					cout << "Nieprawidlowa wartosc\n";
					break;
				}
				cout << "Suma: " << wynik << endl;
				break;
			}
			if (rowcol == 2)
			{
				arr->wypisz();
				cout << endl;
				cout << "Zakres: 1 -> " << arr->ile_w() << endl << "Numer wiersza: ";
				cin >> numer;
				cout << endl;
				err = arr->sumuj_w(numer, &wynik);
				if (err)
				{
					cout << "Nieprawidlowa wartosc\n";
					break;
				}
				cout << "Suma: " << wynik << endl;
				break;
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
			double wynik = 0;
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
					arr->wypisz();
					cout << endl;
					cout << "Zakres: 1 -> " << arr->ile_k() << endl << "Numer kolumny: ";
					cin >> numer;
					cout << endl;
					err = arr->min_k(numer, &wynik);
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
					arr->wypisz();
					cout << endl;
					cout << "Zakres: 1 -> " << arr->ile_w() << endl << "Numer wiersza: ";
					cin >> numer;
					cout << endl;
					err = arr->min_w(numer, &wynik);
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
					arr->wypisz();
					cout << endl;
					cout << "Zakres: 1 -> " << arr->ile_k() << endl << "Numer kolumny: ";
					cin >> numer;
					cout << endl;
					err = arr->max_k(numer, &wynik);
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
					arr->wypisz();
					cout << endl;
					cout << "Zakres: 1 -> " << arr->ile_w() << endl << "Numer wiersza: ";
					cin >> numer;
					cout << endl;
					err = arr->max_w(numer, &wynik);
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
			double wynik = 0;
			cout << "Kolumny -> 1\tWiersze -> 2\nDecyzja: ";
			cin >> rowcol;
			cout << endl;
			if (rowcol == 1)
			{
				arr->wypisz();
				cout << endl;
				cout << "Zakres: 1 -> " << arr->ile_k() << endl << "Numer kolumny: ";
				cin >> numer;
				cout << endl;
				err = arr->srednia_k(numer, &wynik);
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
				arr->wypisz();
				cout << endl;
				cout << "Zakres: 1 -> " << arr->ile_w() << endl << "Numer wiersza: ";
				cin >> numer;
				cout << endl;
				err = arr->srednia_w(numer, &wynik);
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
		case 10:
		{
			int typ, numer;
			cout << "Numer kolumny: ";
			cin >> numer;
			cout << "Nowy typ: ";
			cin >> typ;
			err=arr->ustaw_typ(numer, typ);
			if (err)
			{
				cout << "Nieprawidlowa wartosc\n";
				break;
			}
			cout << "Pomyslnie zmieniono\n";
			break;
		}
		default:
			wybor = 0;
			break;
		}
	}
}
