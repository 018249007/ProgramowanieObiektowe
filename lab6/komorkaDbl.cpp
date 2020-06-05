#include "komorkaDbl.h"

void KomorkaDbl::zmien_wartosc(double nowy)
{
	wartosc = nowy;
}

string KomorkaDbl::zwroc_wartosc()
{
	return to_string(wartosc);
}

int KomorkaDbl::zwroc_typ()
{
	return 2;
}
