#include <iostream>
using namespace std;

int* nowa_tablica(int rozmiar)
{	
	int* tab;
	tab=(int*)malloc(rozmiar*sizeof(int));
	for(int i=0;i<rozmiar;i++)
		tab[i]=0;
	return tab;
}

void wypisz(int* tab, int rozmiar)
{
	for(int i=0;i<rozmiar;i++)
		cout << tab[i] << " ";
	cout << endl;
}

void zmien_element(int* tab, int ktory, int rozmiar)
{
	if ((ktory>rozmiar)||(ktory<1))
		cout << "Numer elementu poza zakresem tablicy\n";
	else
	{
		int nowy;
		cout << "Nowy element: ";
		cin >> nowy;
		tab[ktory-1]=nowy;
	}
	return;
}

int* zmien_rozmiar(int* tab, int* s_rozmiar, int n_rozmiar)
{
	if(n_rozmiar==*s_rozmiar)
	{
		cout << "Rozmiary takie same, nic nie zmieniono\n";
		return tab;
	}
	int* n_tablica=nowa_tablica(n_rozmiar);
	if(n_rozmiar<*s_rozmiar)
	{
		int decyzja;
		cout << "Nowa tablica jest mniejsza od starej, uciac elementy?\n";
		cout << "Tak -> 1\nNie -> 0\n";
		cin >> decyzja;
		if(decyzja==1)
		{
			for(int i=0;i<n_rozmiar;i++)
				n_tablica[i]=tab[i];
			*s_rozmiar=n_rozmiar;
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
		for(int i=0;i<*s_rozmiar;i++)
			n_tablica[i]=tab[i];
		*s_rozmiar=n_rozmiar;
		return n_tablica;
	}
}
