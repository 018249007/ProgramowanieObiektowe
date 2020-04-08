#include "menu.h"
#include "tablice.h"

int main()
{
	int** tab;
	int kolumny, wiersze;
	kolumny = wiersze = 1;
	tab = nowa_tablica(kolumny, wiersze);
	menu(tab, &kolumny, &wiersze);
	return 0;
}
