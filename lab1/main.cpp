#include "menu.h"
#include "tablice.h"

int main()
{
	int** tab;
	int kolumny, wiersze;
	kolumny = wiersze = 1;
	tab = nowa_tablica(kolumny, wiersze);
	// tworzy tablice o jednym wierszu i jednej kolumnie aby mogla byc przekazana do funkcji menu(...)
	menu(tab, &kolumny, &wiersze);
	return 0;
}
