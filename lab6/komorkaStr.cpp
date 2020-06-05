#include "komorkaStr.h"

void KomorkaStr::zmien_wartosc(string nowy)
{
	wartosc = nowy;
}

string KomorkaStr::zwroc_wartosc()
{
	return wartosc;
}

int KomorkaStr::zwroc_typ()
{
	return 1;
}