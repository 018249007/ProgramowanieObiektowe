#ifndef KOMORKASTR_H
#define KOMORKASTR_H
#include "komorka.h"

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
	  * w przypadku braku argumentow ustawia wartosc na ""
	  *
	  * @param[in] a - nowa wartosc
	  */
	KomorkaStr(string a = "")
	{
		wartosc = a;
	}

	~KomorkaStr() {}

	/**
	  * Metoda zmienia wartosc komorki
	  *
	  * @param[in] nowy - nowa wartosc
	  */
	void zmien_wartosc(string nowy);

	// Metoda zwraca wartosc komorki
	string zwroc_wartosc();

	// Metoda zwraca 1
	int zwroc_typ();

	// Operator sprawdza czy dlugosc lancucha < a
	bool operator< (int& a)
	{
		return wartosc.length() < a;
	}

	// Operator sprawdza czy dlugosc lancucha > a
	bool operator> (int& a)
	{
		return wartosc.length() > a;
	}

	// Operator przypisania ustawia wartosc na a
	void operator= (string& a)
	{
		wartosc = a;
	}

	// Operator sumy dodaje dlugosc lancucha do a
	int operator+ (int& a)
	{
		return wartosc.length() + a;
	}

	// Operator rzutowania zwraca wartosc
	operator string() const
	{
		return wartosc;
	}

	// Operator rzutowania zwraca dlugosc lancucha wartosc
	operator int() const
	{
		return wartosc.length();
	}
};

#endif