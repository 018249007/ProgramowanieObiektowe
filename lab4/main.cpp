#include "menu.h"
#include "tablice.h"

int main()
{
	Tablica* tablica = new Tablica();
	menu(tablica);
	delete tablica;
	return 0;
}
