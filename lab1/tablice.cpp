#include "tablice.h"

int** nowa_tablica(int kolumny, int wiersze)
{	
	int** tab;
	tab=(int**)malloc(kolumny*sizeof(int));
	for (int i = 0; i < kolumny; i++)
		tab[i] = (int*)malloc(wiersze*sizeof(int));
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[j][i] = 0;
	return tab;
}

int** odczyt(int* kolumny, int* wiersze) {
	fstream plik;
	plik.open(BAZA);
	int i, j;
	i = j = 0;
	if (plik.eof())
		cout << "Brak danych";
	else
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
	cout << "Wczytano tablice z pliku\n";
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
	cout << "Zapisano tablice do pliku\n";
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

void zmien_element(int** tab, int ktory_w, int ktory_k, int kolumny, int wiersze)
{
	if ((ktory_k>kolumny)||(ktory_k<1)||(ktory_w>wiersze)||(ktory_k<1))
		cout << "Numer elementu poza zakresem tablicy\n";
	else
	{
		int nowy;
		cout << "Nowy element: ";
		cin >> nowy;
		tab[ktory_k-1][ktory_w-1]=nowy;
	}
	return;
}

int** zmien_rozmiar(int** tab, int* s_kolumny, int* s_wiersze, int n_kolumny, int n_wiersze)
{
	if((n_kolumny==*s_kolumny)&&(n_wiersze==*s_wiersze))
	{
		cout << "Rozmiary takie same, nic nie zmieniono\n";
		return tab;
	}
	int** n_tablica=nowa_tablica(n_kolumny, n_wiersze);
	if((n_kolumny<*s_kolumny)||(n_wiersze<*s_wiersze))
	{
		int decyzja;
		cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
		cout << "Tak -> 1\nNie -> 0\n";
		cin >> decyzja;
		if(decyzja==1)
		{
			int tmp_kolumny, tmp_wiersze;
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
		else
		{
			cout << "Nie zmieniono rozmiaru\n";
			return tab;
		}
	}
	else
	{
		for (int i = 0; i < *s_kolumny; i++)
			for (int j = 0; j < *s_wiersze; j++)
				n_tablica[i][j] = tab[i][j];
		*s_kolumny = n_kolumny;
		*s_wiersze = n_wiersze;
		return n_tablica;
	}
}
