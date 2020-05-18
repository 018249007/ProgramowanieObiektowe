#include "tablice.h"

int Tablica::ile_k()
{
	return kolumny;
}

int Tablica::ile_w()
{
	return wiersze;
}

void Tablica::nowa_tablica()
{	
	tab = (int**)malloc(kolumny * sizeof(int*));
	for (int i = 0; i < kolumny; i++)
		tab[i] = (int*)malloc(wiersze*sizeof(int));
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			tab[j][i] = 0;
}

void Tablica::zwolnij_pamiec() {
	for (int i = 0; i < kolumny; i++)
		free(tab[i]);
	free(tab);
}

void Tablica::odczyt() 
{
	fstream plik;
	plik.open(BAZA);
	int i, j;
	i = j = 0;
	if (plik.eof())
	{
		cout << "Brak danych\n";
		return;
	}	
	plik >> kolumny >> wiersze;
	nowa_tablica();
	while(i<wiersze)
	{
		while(j<kolumny)
		{
			if (plik.eof())
				break;
			plik >> tab[j][i];
			j += 1;
		}
		i += 1;
		j = 0;
	}
	plik.close();
}

void Tablica::zapis() {
	fstream plik;
	plik.open(BAZA, ios::trunc | ios::out);
	plik << kolumny << "\n" << wiersze << "\n";
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			plik << tab[j][i] << " ";
		plik << "\n";
	}
}

void Tablica::wypisz()
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
			printf("%5d", tab[j][i]);
		cout << endl;
	}
}

void Tablica::zmien_element(int ktory_w, int ktory_k, int nowy)
{
	tab[ktory_k-1][ktory_w-1]=nowy;
	return;
}

void Tablica::zmien_rozmiar(int n_kolumny, int n_wiersze)
{	
	int tmp_kolumny = kolumny;
	int tmp_wiersze = wiersze;
	Tablica* nowa = new Tablica(n_kolumny, n_wiersze);
	if (n_kolumny < kolumny)
		tmp_kolumny = n_kolumny;
	if (n_wiersze < wiersze)
		tmp_wiersze = n_wiersze;
	for(int i=0;i<tmp_wiersze;i++)
		for(int j=0;j<tmp_kolumny;j++)
			nowa->tab[j][i]=tab[j][i];
	zwolnij_pamiec();
	tab = nowa->tab;
	kolumny = n_kolumny;
	wiersze = n_wiersze;
	delete nowa;
}

void Tablica::sumuj_k()
{
	int suma = 0;
	wypisz();
	cout << endl;
	for (int i = 0; i < kolumny; i++)
	{
		for (int j = 0; j < wiersze; j++)
			suma += tab[i][j];
		printf("%5d", suma);
		suma = 0;
	}
	cout << "       Sumy";
	cout << endl;
}

void Tablica::sumuj_w()
{
	int suma = 0;
	char a = ' ';
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			suma += tab[j][i];
			printf("%5d", tab[j][i]);
		}
		cout << "        " << suma << endl;
		suma = 0;
	}
	for (int i = 0; i < kolumny; i++)
		printf("%5c", a);
	cout << "       Sumy" << endl;
}

void Tablica::naj_k()
{
	wypisz();
	cout << endl;
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < kolumny; i++)
	{
		for (int j = 0; j < wiersze; j++)
			if (min > tab[i][j])
				min = tab[i][j];
		printf("%5d", min);
		min = INT16_MAX;
	}
	cout << "       min";
	cout << endl;
	for (int i = 0; i < kolumny; i++)
	{
		for (int j = 0; j < wiersze; j++)
			if (max < tab[i][j])
				max = tab[i][j];
		printf("%5d", max);
		max = INT16_MIN;
	}
	cout << "       max";
	cout << endl;
}

void Tablica::naj_w()
{
	cout << endl;
	char a = ' ';
	int min = INT16_MAX;
	int max = INT16_MIN;
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			if (min > tab[j][i])
				min = tab[j][i];
			if (max < tab[j][i])
				max = tab[j][i];
			printf("%5d", tab[j][i]);
		}
		printf("       %-5d%-5d\n", min, max);
		min = INT16_MAX;
		max = INT16_MIN;
	}
	for (int i = 0; i < kolumny; i++)
		printf("%5c", a);
	cout << "       min  max" << endl;
}

void Tablica::srednia_k()
{
	float suma = 0;
	wypisz();
	cout << endl;
	for (int i = 0; i < kolumny; i++)
	{
		for (int j = 0; j < wiersze; j++)
			suma += tab[i][j];
		printf(" %.2f", suma/wiersze);
		suma = 0;
	}
	cout << "       Srednie";
	cout << endl;
}

void Tablica::srednia_w()
{
	float suma = 0;
	char a = ' ';
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{
			suma += tab[j][i];
			printf("%5d", tab[j][i]);
		}
		cout << "       " << suma/kolumny << endl;
		suma = 0;
	}
	for (int i = 0; i < kolumny; i++)
		printf("%5c", a);
	cout << "       Srednie" << endl;
}