#include "menu.h"
#include "tablice.h"

int main()
{
	Tablica* tablica = new Tablica;
	nowa_tablica(tablica, 1, 1);
	menu(tablica);
	zwolnij_pamiec(tablica);
	delete tablica;
	return 0;
}
