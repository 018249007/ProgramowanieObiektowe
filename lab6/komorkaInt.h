#ifndef KOMORKAINT_H
#define KOMORKAINT_H
#include "Ikomorka.h"

/**
  * Klasa przechowuje wartosc typu int
  *
  * @param wartosc - przechowywana liczba
  */
class KomorkaInt :
	public Komorka
{
private:
	int wartosc;

public:

	/**
	  * Konstruktor domyslny
	  *
	  * w przypadku braku argumentow ustawia wartosc na ""
	  *
	  * @param[in] a - nowa wartosc
	  */
	KomorkaInt(int a = 0)
	{
		wartosc = a;
	}

	~KomorkaInt() {}

	/**
	  * Metoda zwraca wartosc komorki w postaci string
	  *
	  * @return wartosc
	  */
	string zwroc_wartosc() { return to_string(wartosc); }

	// Operator sprawdza czy wartosc < a
	bool operator< (double& a) { return wartosc < a; }

	// Operator sprawdza czy wartosc > a
	bool operator> (double& a) { return wartosc > a; }

	// Operator przypisania ustawia wartosc na s
	void operator= (const string& s) { wartosc = stoi(s); }

	// Operator sumy dodaje wartosc do a
	double operator+ (double& a) { return wartosc + a; }

	// Operator rzutowania na double
	operator double() const { return wartosc; }
};

#endif
