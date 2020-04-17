#include "tablice.h"

int** nowa_tablica(int kolumny, int wiersze)
{	
	int** tab;
	tab=(int**)malloc(kolumny*sizeof(int*));
	for (int i = 0; i < kolumny; i++)
		tab[i] = (int*)malloc(wiersze*sizeof(int));
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[j][i] = 0;
	return tab;
}

int** odczyt(int* kolumny, int* wiersze) 
{
	fstream plik;
	string tmp;
	plik.open(BAZA);
	int i, j;
	i = j = 0;
	if (plik.eof())
	{	*kolumny=1;
		*wiersze=1;
		int** pusta = nowa_tablica(*kolumny, *wiersze);
		cout << "Brak danych, stworzono tablice 1x1\n";
		return pusta;
	}	
	plik >> *kolumny >> *wiersze;
	int** n_tab = nowa_tablica(*kolumny, *wiersze);
	while(i<*wiersze)
	{
		while(j<*kolumny)
		{
			if (plik.eof())
				break;
			plik >> n_tab[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
	return n_tab;
}

void zapis(int** tab, int* kolumny, int* wiersze) {
	fstream plik;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << *kolumny << "\n" << *wiersze << "\n";
	for (int i = 0; i < *wiersze; i++)
	{
		for (int j = 0; j < *kolumny; j++)
			plik << tab[j][i] << " ";
		plik << "\n";
	}
}

void wypisz(int** tab, int kolumny, int wiersze)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			printf("%5d", tab[j][i]);
		cout << endl;
	}
}

void zmien_element(int** tab, int ktory_w, int ktory_k, int kolumny, int wiersze, int nowy)
{
	tab[ktory_k-1][ktory_w-1]=nowy;
	return;
}

int** zmien_rozmiar(int** tab, int* s_kolumny, int* s_wiersze, int n_kolumny, int n_wiersze)
{
	int** n_tablica=nowa_tablica(n_kolumny, n_wiersze);
	int tmp_kolumny = *s_kolumny;
	int tmp_wiersze = *s_wiersze;
	if (n_kolumny < *s_kolumny)
		tmp_kolumny = n_kolumny;
	if (n_wiersze < *s_wiersze)
		tmp_wiersze = n_wiersze;
	for(int i=0;i<tmp_wiersze;i++)
		for(int j=0;j<tmp_kolumny;j++)
			n_tablica[j][i]=tab[j][i];
	*s_kolumny = n_kolumny;
	*s_wiersze = n_wiersze;
	return n_tablica;
}
