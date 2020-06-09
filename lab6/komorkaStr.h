#ifndef KOMORKASTR_H
#define KOMORKASTR_H
#include "Ikomorka.h"

/**
  * Klasa przechowuje wartosc typu string
  *
  * @param wartosc - przechowywany lancuch
  */
class KomorkaStr :
	public Komorka
{
private:
	string wartosc;

public:

	/**
	  * Konstruktor domyslny
	  *
	  * w przypadku braku argumentow ustawia wartosc na 0
	  *
	  * @param[in] a - nowa wartosc
	  */
	KomorkaStr(string a = "")
	{
		wartosc = a;
	}

	~KomorkaStr() {}

	/**
	  * Metoda zwraca wartosc komorki
	  *
	  * @return wartosc
	  */
	string zwroc_wartosc() { return wartosc; }

	// Operator sprawdza czy dlugosc lancucha < a
	bool operator< (double& a) { return wartosc.length() < a; }

	// Operator sprawdza czy dlugosc lancucha > a
	bool operator> (double& a) { return wartosc.length() > a; }

	// Operator przypisania ustawia wartosc na s
	void operator= (const string& s) { wartosc = s; }

	// Operator sumy dodaje dlugosc lancucha do a
	double operator+ (double& a) { return wartosc.length() + a; }

	// Operator rzutowania na double
	operator double() const { return wartosc.length(); }
};

#endif
