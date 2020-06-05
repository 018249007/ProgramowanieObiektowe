#include "tablice.h"
#define ERR_INVALID_VALUE 1
#define ERR_EOF 1
 
int Tablica::ile_k()
{
	return kolumny;
}

int Tablica::ile_w()
{
	return wiersze;
}

int Tablica::zwroc_typ(int numer, int* typ)
{
	if (numer<1 || numer>kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	else
	{
		*typ = typy[numer - 1];
	}
	return 0;
}

Komorka*** Tablica::alokuj_pamiec(int kolumny, int wiersze, int* typy)
{
	Komorka*** tab = new Komorka * *[kolumny];
	for (int i = 0; i < kolumny; i++)
	{
		tab[i] = new Komorka * [wiersze];
	}
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			if (typy[j] == 0)
			{
				tab[j][i] = new KomorkaInt();
			}
			else if (typy[j] == 1)
			{
				tab[j][i] = new KomorkaStr();
			}
			else if (typy[j] == 2)
			{
				tab[j][i] = new KomorkaDbl();
			}
		}
	}
	return tab;
}

int Tablica::nowa_tablica(int n_kolumny, int n_wiersze)
{
	if (n_kolumny < 1 || n_wiersze < 1)
	{
		return ERR_INVALID_VALUE;
	}
	zwolnij_pamiec();
	this->kolumny = n_kolumny;
	this->wiersze = n_wiersze;
	int tmp_typ;
	for (int i = 0; i < kolumny; i++)
	{
		cout << "Typ kolumny nr " << i + 1 << ": ";
		cin >> tmp_typ;
		if (tmp_typ != 0 && tmp_typ != 1 && tmp_typ != 2)
		{
			return ERR_INVALID_VALUE;
		}
		typy[i] = tmp_typ;
	}
	tab = alokuj_pamiec(n_kolumny, n_wiersze, typy);
	return 0;
}

void Tablica::zwolnij_pamiec() {
	for (int i = 0; i < kolumny; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

void Tablica::pobierz_typy()
{
	int tmp_typ;
	cout << "0 -> Int, 1 -> String, 2 -> Double\n";
	for (int i = 0; i < kolumny; i++)
	{
		cout << "Kolumna nr " << i + 1 << ": ";
		cin >> tmp_typ;
		if (tmp_typ != 1 && tmp_typ != 0 && tmp_typ != 2)
		{
			cout << "Nieprawidlowa wartosc, jeszcze raz: ";
			i -= 1;
		}
		else
		{
			typy[i] = tmp_typ;
		}
	}
}

int Tablica::ustaw_typ(int numer, int typ)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	if (typ != 0 && typ != 1 && typ != 2)
	{
		return ERR_INVALID_VALUE;
	}
	typy[numer - 1] = typ;
	if (typ == 0)
	{
		for (int i = 0; i < wiersze; i++)
		{
			delete tab[numer - 1][i];
			tab[numer - 1][i] = new KomorkaInt();
		}
	}
	if (typ == 1)
	{
		for (int i = 0; i < wiersze; i++)
		{
			delete tab[numer - 1][i];
			tab[numer - 1][i] = new KomorkaStr();
		}
	}
	if (typ == 2)
	{
		for (int i = 0; i < wiersze; i++)
		{
			delete tab[numer - 1][i];
			tab[numer - 1][i] = new KomorkaDbl();
		}
	}
	return 0;
}

int Tablica::odczyt()
{
	int i, j;
	i = j = 0;
	fstream plik;
	string tmp;
	plik.open(BAZA);
	if (plik.eof())
	{
		return ERR_EOF;
	}
	plik >> kolumny >> wiersze;
	for (int i = 0; i < kolumny; i++)
	{
		plik >> typy[i];
	}
	tab = alokuj_pamiec(kolumny, wiersze, typy);
	plik.clear();
	plik.ignore(INT16_MAX, '\n');
	while (i < wiersze)
	{
		while (j < kolumny)
		{
			getline(plik, tmp);
			if(typy[j] == 0)
			{
				tab[j][i]->zmien_wartosc(stoi(tmp));
			}
			else if (typy[j] == 1)
			{
				tab[j][i]->zmien_wartosc(tmp);
			}
			else
			{
				tab[j][i]->zmien_wartosc(stod(tmp));
			}
			if (plik.eof())
			{
				break;
			}
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
	return 0;
}

void Tablica::zapisz()
{
	fstream plik;
	string wartosc;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << kolumny << " " << wiersze << "\n";
	for (int i = 0; i < kolumny; i++)
	{
		plik << typy[i] << " ";
	}
	plik << endl;
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			wartosc = tab[j][i]->zwroc_wartosc();
			plik << wartosc << "\n";
		}
	}
}

void Tablica::wypisz()
{
	for (int i = 0; i < wiersze; i++)
	{
		cout << "| ";
		for (int j = 0; j < kolumny; j++)
		{
			cout.width(10);
			cout << tab[j][i]->zwroc_wartosc();
			cout << " | ";
		}
		cout << endl;
	}
}

int Tablica::zmien_element(int ktory_w, int ktory_k, string nowy)
{
	if ((ktory_k > ile_k()) || (ktory_k < 1) || (ktory_w > ile_w()) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	tab[ktory_k - 1][ktory_w - 1]->zmien_wartosc(nowy);
	return 0;
}

int Tablica::zmien_element(int ktory_w, int ktory_k, int nowy)
{
	if ((ktory_k > ile_k()) || (ktory_k < 1) || (ktory_w > ile_w()) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	tab[ktory_k - 1][ktory_w - 1]->zmien_wartosc(nowy);
	return 0;
}

int Tablica::zmien_element(int ktory_w, int ktory_k, double nowy)
{
	if ((ktory_k > ile_k()) || (ktory_k < 1) || (ktory_w > ile_w()) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	tab[ktory_k - 1][ktory_w - 1]->zmien_wartosc(nowy);
	return 0;
}

int Tablica::zmien_rozmiar(int n_kolumny, int n_wiersze)
{
	if ((n_kolumny < 1) || (n_wiersze < 1))
	{
		return ERR_INVALID_VALUE;
	}
	if ((n_kolumny == ile_k()) && (n_wiersze == ile_w()))
	{
		cout << "Rozmiary takie same\n";
		return 0;
	}
	if ((n_kolumny < ile_k()) || (n_wiersze < ile_w()))
	{
		int decyzja;
		cout << "Wymiar nowej tablicy jest mniejszy od starej, uciac elementy?\n";
		cout << "Tak -> 1\nNie -> 0\nDecyzja: ";
		cin >> decyzja;
		cout << endl;
		if (decyzja == 0)
		{
			cout << "Nic nie zmieniono\n";
			return 0;
		}
	}
	int tmp_kolumny = kolumny;
	int tmp_wiersze = wiersze;
	int* n_typy = new int[n_kolumny];
	if (n_kolumny < kolumny)
	{
		tmp_kolumny = n_kolumny;
		for (int i = 0; i < n_kolumny; i++)
		{
			n_typy[i] = typy[i];
		}
	}
	else if (n_kolumny == kolumny)
	{
		for (int i = 0; i < kolumny; i++)
		{
			n_typy[i] = typy[i];
		}
	}
	else
	{
		for (int i = 0; i < kolumny; i++)
		{
			n_typy[i] = typy[i];
		}
		cout << "0 -> Int, 1 -> String, Double -> 2\n";
		for (int i = kolumny; i < n_kolumny; i++)
		{
			cout << "Typ kolumny nr " << i + 1 << ": ";
			cin >> n_typy[i];
		}
	}
	Komorka*** nowa = alokuj_pamiec(n_kolumny, n_wiersze, n_typy);
	if (n_wiersze < wiersze)
	{
		tmp_wiersze = n_wiersze;
	}
	for (int i = 0; i < tmp_wiersze; i++)
	{
		for (int j = 0; j < tmp_kolumny; j++)
		{
			nowa[j][i] = tab[j][i];
		}
	}
	zwolnij_pamiec();
	tab = nowa;
	kolumny = n_kolumny;
	wiersze = n_wiersze;
	typy = n_typy;
	return 0;
}

int Tablica::sumuj_k(int numer, double* wynik)
{
	if (numer<1 || numer>ile_k())
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < wiersze; i++)
	{
		*wynik = *tab[numer - 1][i] + *wynik;
	}
	return 0;
}

int Tablica::sumuj_w(int numer, double* wynik)
{
	if (numer<1 || numer>ile_w())
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < kolumny; i++)
	{
		*wynik = *tab[i][numer - 1] + *wynik;
	}
	return 0;
}

int Tablica::min_k(int numer, double* wynik)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = *tab[numer - 1][0];
	for (int i = 1; i < wiersze - 1; i++)
	{
		if (*tab[numer - 1][i] < *wynik)
		{
			*wynik = *tab[numer - 1][i];
		}
	}
	return 0;
}

int Tablica::min_w(int numer, double* wynik)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = *tab[0][numer - 1];
	for (int i = 1; i < kolumny; i++)
	{
		if (*tab[i][numer - 1] < *wynik)
		{
			*wynik = *tab[i][numer - 1];
		}
	}
	return 0;
}

int Tablica::max_k(int numer, double* wynik)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = *tab[numer - 1][0];
	for (int i = 1; i < wiersze - 1; i++)
	{
		if (*tab[numer - 1][i] > * wynik)
		{
			*wynik = *tab[numer - 1][i];
		}
	}
	return 0;
}

int Tablica::max_w(int numer, double* wynik)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = *tab[0][numer - 1];
	for (int i = 1; i < kolumny; i++)
	{
		if (*tab[i][numer - 1] > * wynik)
		{
			*wynik = *tab[i][numer - 1];
		}
	}
	return 0;
}

int Tablica::srednia_k(int numer, double* wynik)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	double suma = 0;
	sumuj_k(numer, &suma);
	*wynik = suma / wiersze;
	return 0;
}

int Tablica::srednia_w(int numer, double* wynik)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	double suma = 0;
	sumuj_w(numer, &suma);
	*wynik = suma / kolumny;
	return 0;
}
