#include "menu.h"

int main()
{
	Tablica* tablica = new Tablica();
	menu(tablica);
	delete tablica;
	return 0;
}
