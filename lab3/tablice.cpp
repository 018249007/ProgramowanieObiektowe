#include "tablice.h"

void nowa_tablica(Tablica* arr, int kolumny, int wiersze)
{	
	int** tab = (int**)malloc(kolumny * sizeof(int*));
	for (int i = 0; i < kolumny; i++)
		tab[i] = (int*)malloc(wiersze*sizeof(int));
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[j][i] = 0;
	arr->tab = tab;
	arr->kolumny = kolumny;
	arr->wiersze = wiersze;
}

void odczyt(Tablica* arr) 
{
	fstream plik;
	plik.open(BAZA);
	int wiersze, kolumny;
	int i, j;
	i = j = 0;
	if (plik.eof())
	{
		nowa_tablica(arr, 1, 1);
		cout << "Brak danych, stworzono tablice 1x1\n";
		return;
	}	
	plik >> kolumny >> wiersze;
	nowa_tablica(arr, kolumny, wiersze);
	while(i<arr->wiersze)
	{
		while(j<arr->kolumny)
		{
			if (plik.eof())
				break;
			plik >> arr->tab[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
}

void zapis(Tablica arr) {
	fstream plik;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << arr.kolumny << "\n" << arr.wiersze << "\n";
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
			plik << arr.tab[j][i] << " ";
		plik << "\n";
	}
}

void wypisz(Tablica arr)
{
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
			printf("%5d", arr.tab[j][i]);
		cout << endl;
	}
}

void zmien_element(Tablica* arr, int ktory_w, int ktory_k, int nowy)
{
	arr->tab[ktory_k-1][ktory_w-1]=nowy;
	return;
}

void zmien_rozmiar(Tablica* arr, int n_kolumny, int n_wiersze)
{	
	int tmp_kolumny = arr->kolumny;
	int tmp_wiersze = arr->wiersze;
	Tablica* nowa = (Tablica*)malloc(sizeof(Tablica));
	nowa_tablica(nowa, n_kolumny, n_wiersze);
	if (n_kolumny < arr->kolumny)
		tmp_kolumny = n_kolumny;
	if (n_wiersze < arr->wiersze)
		tmp_wiersze = n_wiersze;
	for(int i=0;i<tmp_wiersze;i++)
		for(int j=0;j<tmp_kolumny;j++)
			nowa->tab[j][i]=arr->tab[j][i];
	free(arr->tab);
	arr->tab = nowa->tab;
	free(nowa);
	arr->kolumny = n_kolumny;
	arr->wiersze = n_wiersze;
}

void sumuj_k(Tablica arr)
{
	int suma = 0;
	wypisz(arr);
	cout << endl;
	for (int i = 0; i < arr.kolumny; i++)
	{
		for (int j = 0; j < arr.wiersze; j++)
			suma += arr.tab[i][j];
		printf("%5d", suma);
		suma = 0;
	}
	cout << "       Sumy";
	cout << endl;
}

void sumuj_w(Tablica arr)
{
	int suma = 0;
	char a = ' ';
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
		{
			suma += arr.tab[j][i];
			printf("%5d", arr.tab[j][i]);
		}
		cout << "       " << suma << endl;
		suma = 0;
	}
	for (int i = 0; i < arr.kolumny; i++)
		printf("%5c", a);
	cout << "       Sumy" << endl;
}

void naj_k(Tablica arr)
{
	wypisz(arr);
	cout << endl;
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < arr.kolumny; i++)
	{
		for (int j = 0; j < arr.wiersze; j++)
			if (min > arr.tab[i][j])
				min = arr.tab[i][j];
		printf("%5d", min);
		min = INT16_MAX;
	}
	cout << "       min";
	cout << endl;
	for (int i = 0; i < arr.kolumny; i++)
	{
		for (int j = 0; j < arr.wiersze; j++)
			if (max < arr.tab[i][j])
				max = arr.tab[i][j];
		printf("%5d", max);
		max = INT16_MIN;
	}
	cout << "       max";
	cout << endl;
}

void naj_w(Tablica arr)
{
	cout << endl;
	char a = ' ';
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
		{
			if (min > arr.tab[j][i])
				min = arr.tab[j][i];
			if (max < arr.tab[j][i])
				max = arr.tab[j][i];
			printf("%5d", arr.tab[j][i]);
		}
		printf("       %-5d%-5d\n", min, max);
		min = INT16_MAX;
		max = INT16_MIN;
	}
	for (int i = 0; i < arr.kolumny; i++)
		printf("%5c", a);
	cout << "       min  max" << endl;
}

void srednia_k(Tablica arr)
{
	float suma = 0;
	wypisz(arr);
	cout << endl;
	for (int i = 0; i < arr.kolumny; i++)
	{
		for (int j = 0; j < arr.wiersze; j++)
			suma += arr.tab[i][j];
		cout << suma/arr.wiersze << "  ";
		suma = 0;
	}
	cout << "       Srednie";
	cout << endl;
}

void srednia_w(Tablica arr)
{
	float suma = 0;
	char a = ' ';
	for (int i = 0; i < arr.wiersze; i++)
	{
		for (int j = 0; j < arr.kolumny; j++)
		{
			suma += arr.tab[j][i];
			printf("%5d", arr.tab[j][i]);
		}
		cout << "       " << suma/arr.kolumny << endl;
		suma = 0;
	}
	for (int i = 0; i < arr.kolumny; i++)
		printf("%5c", a);
	cout << "       Srednie" << endl;
}
