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

Komorka*** Tablica::alokuj_pamiec(int kolumny, int wiersze, bool czy_int)
{
	Komorka*** tab = new Komorka**[kolumny];
	for (int i = 0; i < kolumny; i++)
	{
		tab[i] = new Komorka*[wiersze];
	}
	if(czy_int)
	{
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				tab[j][i] = new Komorka(0);
			}
		}
	}
	else
	{
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				tab[j][i] = new Komorka();
			}
		}
	}
	return tab;
}

int Tablica::nowa_tablica(int n_kolumny, int n_wiersze, bool czy_int)
{
	if (n_kolumny < 1 || n_wiersze < 1)
	{
		return ERR_INVALID_VALUE;
	}
	zwolnij_pamiec();
	tab = alokuj_pamiec(n_kolumny, n_wiersze, czy_int);
	this->kolumny = n_kolumny;
	this->wiersze = n_wiersze;
	return 0;
}

void Tablica::zwolnij_pamiec() {
	for (int i = 0; i < kolumny; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

int Tablica::odczyt(bool czy_int) 
{
	int i, j;
	i = j = 0;
	if(czy_int)
	{
		fstream plik;
		plik.open(BAZA_INT);
		if (plik.eof())
		{
			return ERR_EOF;
		}
		plik >> kolumny >> wiersze;
		int wartosc;
		tab = alokuj_pamiec(kolumny, wiersze, true);
		while(i<wiersze)
		{
			while(j<kolumny)
			{
				if (plik.eof())
				{
					break;
				}
				plik >> wartosc;
				tab[j][i]->zmien_wartosc(wartosc);
				j += 1;
			}
			i += 1;
			j = 0;
		}
		plik.close();
	}
	else
	{
		fstream plik;
		plik.open(BAZA_STR);
		if (plik.eof())
		{
			return ERR_EOF;
		}
		string tmp = "";
		getline(plik, tmp);
		kolumny = stoi(tmp);
		tmp = "";
		getline(plik, tmp);
		wiersze = stoi(tmp);
		string wartosc;
		tab = alokuj_pamiec(kolumny, wiersze, false);
		while(i<wiersze)
		{
			while(j<kolumny)
			{
				if (plik.eof())
				{
					break;
				}
				getline(plik, wartosc);
				tab[j][i]->zmien_wartosc(wartosc);
				wartosc="";
				j += 1;
			}
			i += 1;
			j = 0;
		}
		plik.close();
	}
	return 0;
}

void Tablica::zapisz(bool czy_int)
{
	fstream plik;
	if(czy_int)
	{
		int wartosc;
		plik.open(BAZA_INT, ios::trunc | ios::out);
		plik << kolumny << "\n" << wiersze << "\n";
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				tab[j][i]->zwroc_zawartosc(&wartosc);
				plik << wartosc << " ";
			}
			plik << "\n";
		}
	}
	else
	{
		string wartosc;
		plik.open(BAZA_STR, ios::trunc | ios::out);
		plik << kolumny << "\n" << wiersze << "\n";
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				tab[j][i]->zwroc_zawartosc(&wartosc);
				plik << wartosc << endl;
				wartosc="";
			}
		}
	}
}

void Tablica::wypisz()
{
	if(tab[0][0]->zwroc_typ())
	{
		int wartosc;
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				cout.width(5);
				tab[j][i]->zwroc_zawartosc(&wartosc);
				cout << wartosc;
			}
			cout << endl;
		}
	}
	else
	{
		string wartosc;
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
			{
				cout.width(10);
				tab[j][i]->zwroc_zawartosc(&wartosc);
				cout << wartosc;
				cout << " | ";
				wartosc = "";
			}
			cout << endl;
		}
	}
}

int Tablica::zmien_element(int ktory_w, int ktory_k, string nowy, bool czy_int)
{
	if ((ktory_k > ile_k()) || (ktory_k < 1) || (ktory_w > ile_w()) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	if(czy_int)
	{
		tab[ktory_k-1][ktory_w-1]->zmien_wartosc(stoi(nowy));
	}
	else
	{
		tab[ktory_k-1][ktory_w-1]->zmien_wartosc(nowy);
	}
	return 0;
}

int Tablica::zmien_rozmiar(int n_kolumny, int n_wiersze, bool czy_int)
{	
	if ((n_kolumny < 1) || (n_wiersze < 1))
	{
		return ERR_INVALID_VALUE;
	}
	if ((n_kolumny == ile_k()) && (n_wiersze == ile_w()))
	{
		return 0;
	}
	if ((n_kolumny < ile_k()) || (n_wiersze < ile_w()))
	{
		int decyzja;
		cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
		cout << "Tak -> 1\nNie -> 0\nDecyzja: ";
		cin >> decyzja;
		cout << endl;
		if (decyzja == 0)
		{
			return 0;
		}
	}
	int tmp_kolumny = kolumny;
	int tmp_wiersze = wiersze;
	Komorka*** nowa = alokuj_pamiec(n_kolumny, n_wiersze, czy_int);
	if (n_kolumny < kolumny)
	{
		tmp_kolumny = n_kolumny;
	}
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
	return 0;
}

int Tablica::sumuj_k(int numer, int* wynik)
{
	if (numer<1 || numer>ile_k())
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < wiersze; i++)
	{
		*wynik = *tab[numer-1][i]+ *wynik;
	}
	return 0;
}

int Tablica::sumuj_w(int numer, int* wynik)
{
	if (numer<1 || numer>ile_w())
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < kolumny; i++)
	{
		*wynik = *tab[i][numer-1]+ *wynik;
	}
	return 0;
}

int Tablica::min_k(int numer, int* wynik, bool czy_int)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	if (czy_int)
	{
		tab[numer - 1][0]->zwroc_zawartosc(wynik);
		for (int i = 1; i < wiersze - 1; i++)
		{
			if (*tab[numer - 1][i] < *wynik)
			{
				tab[numer - 1][i]->zwroc_zawartosc(wynik);
			}
		}
	}
	else
	{
		*wynik = tab[numer - 1][0]->str_len();
		for (int i = 1; i < wiersze - 1; i++)
		{
			if (*tab[numer - 1][i]< *wynik)
			{
				*wynik = tab[numer - 1][i]->str_len();
			}
		}
	}
	return 0;
}

int Tablica::min_w(int numer, int* wynik, bool czy_int)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	if (czy_int)
	{
		tab[0][numer - 1]->zwroc_zawartosc(wynik);
		for (int i = 1; i < kolumny; i++)
		{
			if (*tab[i][numer - 1] < *wynik)
			{
				tab[i][numer - 1]->zwroc_zawartosc(wynik);
			}
		}
	}
	else
	{
		*wynik = tab[0][numer - 1]->str_len();
		for (int i = 1; i < kolumny; i++)
		{
			if (*tab[i][numer - 1] < * wynik)
			{
				*wynik = tab[i][numer - 1]->str_len();
			}
		}
	}
	return 0;
}

int Tablica::max_k(int numer, int* wynik, bool czy_int)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	if (czy_int)
	{
		tab[numer - 1][0]->zwroc_zawartosc(wynik);
		for (int i = 1; i < wiersze - 1; i++)
		{
			if (*tab[numer - 1][i] > * wynik)
			{
				tab[numer - 1][i]->zwroc_zawartosc(wynik);
			}
		}
	}
	else
	{
		*wynik=tab[numer - 1][0]->str_len();
		for (int i = 1; i < wiersze - 1; i++)
		{
			if (*tab[numer - 1][i] > *wynik)
			{
				*wynik = tab[numer - 1][i]->str_len();
			}
		}
	}
	return 0;
}

int Tablica::max_w(int numer, int* wynik, bool czy_int)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	if (czy_int)
	{
		tab[0][numer - 1]->zwroc_zawartosc(wynik);
		for (int i = 1; i < kolumny; i++)
		{
			if (*tab[i][numer - 1] > *wynik)
			{
				tab[i][numer - 1]->zwroc_zawartosc(wynik);
			}
		}
	}
	else
	{
		*wynik = tab[0][numer - 1]->str_len();
		for (int i = 1; i < kolumny; i++)
		{
			if (*tab[i][numer - 1] > *wynik)
			{
				*wynik = tab[i][numer - 1]->str_len();
			}
		}
	}
	return 0;
}

int Tablica::srednia_k(int numer, float* wynik, bool czy_int)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	int suma = 0;
	sumuj_k(numer, &suma);
	*wynik = (float)suma / wiersze;
	return 0;
}

int Tablica::srednia_w(int numer, float* wynik, bool czy_int)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	int suma = 0;
	sumuj_w(numer, &suma);
	*wynik = (float)suma / kolumny;
	return 0;
}