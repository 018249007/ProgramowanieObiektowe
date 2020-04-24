#include "menu.h"
#include "tablice.h"

int main()
{
	Tablica* tablica = (Tablica*)malloc(sizeof(Tablica));
	nowa_tablica(tablica, 1, 1);
	menu(tablica);
	free(tablica);
	return 0;
}
