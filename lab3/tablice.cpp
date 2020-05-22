#include "tablice.h"
#define ERR_INVALID_VALUE 1
#define ERR_EOF 1

int nowa_tablica(Tablica* arr, int kolumny, int wiersze)
{	
	if (kolumny < 1 || wiersze < 1)
	{
		return ERR_INVALID_VALUE;
	}
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
	arr->tab = tab;
	arr->kolumny = kolumny;
	arr->wiersze = wiersze;
	return 0;
}

void zwolnij_pamiec(Tablica* tab)
{
	for (int i = 0; i < tab->kolumny; i++)
	{
		delete[] tab->tab[i];
	}
	delete[] tab->tab;
}

int odczyt(Tablica* arr) 
{
	fstream plik;
	plik.open(BAZA);
	int wiersze, kolumny;
	int i, j;
	i = j = 0;
	if (plik.eof())
	{
		return ERR_EOF;
	}	
	plik >> kolumny >> wiersze;
	nowa_tablica(arr, kolumny, wiersze);
	while(i<arr->wiersze)
	{
		while(j<arr->kolumny)
		{
			if (plik.eof())
			{
				break;
			}
			plik >> arr->tab[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
	return 0;
}

void zapis(Tablica arr) {
	fstream plik;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << arr.kolumny << "\n" << arr.wiersze << "\n";
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
		{
			plik << arr.tab[j][i] << " ";
		}
		plik << "\n";
	}
}

void wypisz(Tablica arr)
{
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
		{
			printf("%5d", arr.tab[j][i]);
		}
		cout << endl;
	}
}

int zmien_element(Tablica* arr, int ktory_w, int ktory_k, int nowy)
{
	if ((ktory_k > arr->kolumny) || (ktory_k < 1) || (ktory_w > arr->wiersze) || (ktory_k < 1))
	{
		return ERR_INVALID_VALUE;
	}
	arr->tab[ktory_k-1][ktory_w-1]=nowy;
	return 0;
}

int zmien_rozmiar(Tablica* arr, int n_kolumny, int n_wiersze)
{	
	if ((n_kolumny < 1) || (n_wiersze < 1))
	{
		return ERR_INVALID_VALUE;
	}
	if ((n_kolumny == arr->kolumny) && (n_wiersze == arr->wiersze))
	{
		return 0;
	}
	if ((n_kolumny < arr->kolumny) || (n_wiersze < arr->wiersze))
	{
		int decyzja = 99;
		cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
		cout << "Tak -> 1\nNie -> 0\nDecyzja: ";
		cin >> decyzja;
		cout << endl;
		if (decyzja == 0)
		{
			return 0;
		}
	}
	int tmp_kolumny = arr->kolumny;
	int tmp_wiersze = arr->wiersze;
	Tablica* nowa = (Tablica*)malloc(sizeof(Tablica));
	nowa_tablica(nowa, n_kolumny, n_wiersze);
	if (n_kolumny < arr->kolumny)
	{
		tmp_kolumny = n_kolumny;
	}
	if (n_wiersze < arr->wiersze)
	{
		tmp_wiersze = n_wiersze;
	}
	for (int i = 0; i < tmp_wiersze; i++)
	{
		for (int j = 0; j < tmp_kolumny; j++)
		{
			nowa->tab[j][i] = arr->tab[j][i];
		}
	}
	free(arr->tab);
	arr->tab = nowa->tab;
	free(nowa);
	arr->kolumny = n_kolumny;
	arr->wiersze = n_wiersze;
	return 0;
}

int sumuj_k(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < arr.wiersze; i++)
	{
		*wynik += arr.tab[numer-1][i];
	}
	return 0;
}

int sumuj_w(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	for (int i = 0; i < arr.kolumny; i++)
	{
		*wynik += arr.tab[i][numer-1];
	}
	return 0;
}

int max_k(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MIN;
	for (int i = 0; i < arr.wiersze; i++)
	{
		if (arr.tab[numer-1][i] > *wynik)
		{
			*wynik = arr.tab[numer-1][i];
		}
	}
	return 0;
}

int max_w(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MIN;
	for (int i = 0; i < arr.kolumny; i++)
	{
		if (arr.tab[i][numer - 1] > *wynik)
		{
			*wynik = arr.tab[i][numer - 1];
		}
	}
	return 0;
}

int min_k(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MAX;
	for (int i = 0; i < arr.wiersze; i++)
	{
		if (arr.tab[numer - 1][i] < *wynik)
		{
			*wynik = arr.tab[numer - 1][i];
		}
	}
	return 0;
}

int min_w(Tablica arr, int numer, int* wynik)
{
	if (numer < 1 || numer > arr.wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	*wynik = INT16_MAX;
	for (int i = 0; i < arr.kolumny; i++)
	{
		if (arr.tab[i][numer - 1] < *wynik)
		{
			*wynik = arr.tab[i][numer - 1];
		}
	}
	return 0;
}

int srednia_k(Tablica arr, int numer, float* wynik)
{
	if (numer < 1 || numer > arr.kolumny)
	{
		return ERR_INVALID_VALUE;
	}
	int suma = 0;
	sumuj_k(arr, numer, &suma);
	*wynik = (float)suma / arr.wiersze;
	return 0;
}

int srednia_w(Tablica arr, int numer, float* wynik)
{
	if (numer < 1 || numer > arr.wiersze)
	{
		return ERR_INVALID_VALUE;
	}
	int suma = 0;
	sumuj_w(arr, numer, &suma);
	*wynik = (float)suma / arr.kolumny;
	return 0;
}