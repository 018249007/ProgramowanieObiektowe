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

void zmien_element(int* tab, int ktory, int rozmiar, int nowy)
{
	tab[ktory-1]=nowy;
	return;
}

int* zmien_rozmiar(int* tab, int* s_rozmiar, int n_rozmiar)
{
	int* n_tablica=nowa_tablica(n_rozmiar);
	int tmp_rozmiar=*s_rozmiar;
	if(n_rozmiar<*s_rozmiar)
		tmp_rozmiar=n_rozmiar;
	for(int i=0;i<tmp_rozmiar;i++)
		n_tablica[i]=tab[i];
	*s_rozmiar=n_rozmiar;
	return n_tablica;
}
