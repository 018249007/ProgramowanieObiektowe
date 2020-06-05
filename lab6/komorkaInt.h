#ifndef KOMORKAINT_H
#define KOMORKAINT_H
#include "komorka.h"

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
	  * Metoda zmienia wartosc komorki
	  *
	  * @param[in] nowy - nowa wartosc
	  */
	void zmien_wartosc(int nowy);

	// Metoda zwraca wartosc komorki
	string zwroc_wartosc();

	// Metoda zwraca typ (int -> 0)
	int zwroc_typ();

	// Operator sprawdza czy wartosc < a
	bool operator< (int& a)
	{
		return wartosc < a;
	}

	// Operator sprawdza czy wartosc > a
	bool operator> (int& a)
	{
		return wartosc > a;
	}

	// Operator przypisania ustawia wartosc na a
	void operator= (int& a)
	{
		wartosc = a;
	}

	// Operator sumy dodaje wartosc do a
	int operator+ (int& a)
	{
		return wartosc + a;
	}

	// Operator rzutowania zwraca wartosc
	operator int() const
	{
		return wartosc;
	}
};

#endif
