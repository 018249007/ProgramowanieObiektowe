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

int** Tablica::alokuj_pamiec(int kolumny, int wiersze)
{
	int** tab = new int*[kolumny];
	for (int i = 0; i < kolumny; i++)
	{
		tab[i] = new int[wiersze];
	}
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			tab[j][i] = 0;
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
	tab = alokuj_pamiec(n_kolumny, n_wiersze);
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

int Tablica::odczyt() 
{
	fstream plik;
	plik.open(BAZA);
	int i, j;
	i = j = 0;
	if (plik.eof())
	{
		return ERR_EOF;
	}	
	plik >> kolumny >> wiersze;
	tab = alokuj_pamiec(kolumny, wiersze);
	while(i<wiersze)
	{
		while(j<kolumny)
		{
			if (plik.eof())
			{
				break;
			}
			plik >> tab[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
	return 0;
}

void Tablica::zapis() {
	fstream plik;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << kolumny << "\n" << wiersze << "\n";
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			plik << tab[j][i] << " ";
		}
		plik << "\n";
	}
}

void Tablica::wypisz()
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			cout.width(5);
			cout << tab[j][i];
		}
		cout << endl;
	}
}

int Tablica::zmien_element(int ktory_w, int ktory_k, int nowy)
{
	if ((ktory_k > ile_k()) || (ktory_k < 1) || (ktory_w > ile_w()) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	tab[ktory_k-1][ktory_w-1]=nowy;
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
	int** nowa = alokuj_pamiec(n_kolumny, n_wiersze);
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
		*wynik += tab[numer-1][i];
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
		*wynik += tab[i][numer-1];
	}
	return 0;
}

int Tablica::min_k(int numer, int* wynik)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MAX;
	for (int i = 0; i < wiersze; i++)
	{
		if (tab[numer - 1][i] < *wynik)
		{
			*wynik = tab[numer - 1][i];
		}
	}
	return 0;
}

int Tablica::min_w(int numer, int* wynik)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MAX;
	for (int i = 0; i < kolumny; i++)
	{
		if (tab[i][numer - 1] < *wynik)
		{
			*wynik = tab[i][numer - 1];
		}
	}
	return 0;
}

int Tablica::max_k(int numer, int* wynik)
{
	if (numer < 1 || numer > kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MIN;
	for (int i = 0; i < wiersze; i++)
	{
		if (tab[numer - 1][i] > * wynik)
		{
			*wynik = tab[numer - 1][i];
		}
	}
	return 0;
}

int Tablica::max_w(int numer, int* wynik)
{
	if (numer < 1 || numer > wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MIN;
	for (int i = 0; i < kolumny; i++)
	{
		if (tab[i][numer - 1] > * wynik)
		{
			*wynik = tab[i][numer - 1];
		}
	}
	return 0;
}

int Tablica::srednia_k(int numer, float* wynik)
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

int Tablica::srednia_w(int numer, float* wynik)
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