#include "menu.h"

int main()
{
	Tablica* tablica = new Tablica();
	menu(tablica);
	//delete tablica;
	cin.sync();
	cin.get();
	return 0;
}
