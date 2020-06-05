#include "komorkaInt.h"

void KomorkaInt::zmien_wartosc(int nowy)
{
	wartosc = nowy;
}

string KomorkaInt::zwroc_wartosc()
{
	return to_string(wartosc);
}

int KomorkaInt::zwroc_typ()
{
	return 0;
}