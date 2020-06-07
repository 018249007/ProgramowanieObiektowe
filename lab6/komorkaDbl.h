#ifndef KOMORKADBL_H
#define KOMORKADBL_H
#include "komorka.h"

/**
  * Klasa przechowuje wartosc typu double
  *
  * @param wartosc - przechowywana liczba
  */
class KomorkaDbl :
	public Komorka
{
private:
	double wartosc;

public:

	/**
	  * Konstruktor domyslny
	  *
	  * w przypadku braku argumentow ustawia wartosc na 0
	  *
	  * @param[in] a - nowa wartosc
	  */
	KomorkaDbl(double a = 0)
	{
		wartosc = a;
	}

	~KomorkaDbl() {}

	/**
	  * Metoda zwraca wartosc komorki w postaci string
	  *
	  * @return wartosc
	  */
	string zwroc_wartosc() { return to_string(wartosc); }

	/**
	  * Metoda zwraca typ komorki
	  *
	  * @return typ (double -> 2)
	  */
	int zwroc_typ() { return 2; }

	// Operator sprawdza czy wartosc < a
	bool operator< (double& a) { return wartosc < a; }

	// Operator sprawdza czy wartosc > a
	bool operator> (double& a) { return wartosc > a; }

	// Operator przypisania ustawia wartosc na a
	void operator= (double& a) { wartosc = a; }

	// Operator sumy dodaje wartosc do a
	double operator+ (double& a) { return wartosc + a; }

	// Operator rzutowania na double
	operator double() const { return wartosc; }

};

#endif
