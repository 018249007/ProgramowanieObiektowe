#ifndef KOMORKA_H
#define KOMORKA_H
#include <string>
using namespace std;

class Komorka
{
private:
	string* str;
	int* calkowita;

public:
	// Konstruktor bezparametrowy tworzy komorke o wartosci " "
	Komorka()
	{
		str = new string;
		*str = " ";
		calkowita = NULL;
	}

	// Konstruktor tworzy komorke o wartosci str
	Komorka(string str)
	{
		this->str = new string;
		*this->str = str;
		calkowita = NULL;
	}

	// Konstruktor tworzy komorke o wartosci a
	Komorka(int a)
	{
		calkowita = new int;
		*calkowita = a;
		str = NULL;
	}

	// Destruktor zwalnia pamiec
	~Komorka()
	{
		if (str != NULL)
		{
			delete str;
		}
		if (calkowita != NULL)
		{
			delete calkowita;
		}
	}

	/**
	  * Przeciazony operator sumy
	  * w przypadku komorki typu int zwraca i + *calkowita
	  * w przypadku komorku string zwraca i + dlugosc lancucha *str
	  */
	int operator+ (int &i)
	{
		if(zwroc_typ())
		{
			return i + *calkowita;
		}
		else
		{
			return i + (*str).length();
		}
	}

	/**
	  * Przeciazony operator <
	  * dla komorki typu int sprawdza czy i < *calkowita
	  * dla komorki typu string sprawdza czy i < dlugosc lancucha *str
	  */
	bool operator< (int &i)
	{
		if (zwroc_typ())
		{
			return *calkowita < i;
		}
		else
		{
			return (*str).length() < i;
		}
	}

	/**
	  * Przeciazony operator >
	  * dla komorki typu int sprawdza czy i > *calkowita
	  * dla komorki typu string sprawdza czy i > dlugosc lancucha *str
	  */
	bool operator> (int &i)
	{
		if (zwroc_typ())
		{
			return *calkowita > i;
		}
		else
		{
			return (*str).length() > i;
		}
	}

	/**
	  * Metoda zmienia wartosc komorki na typ int
	  *
	  * @param[in] wartosc - nowa wartosc
	  */
	void zmien_wartosc(int wartosc);

	/**
	  * Metoda zmienia wartosc komorki na typ string
	  *
	  * @param[in] wartosc - nowa wartosc
	  */
	void zmien_wartosc(string wartosc);

	/**
	  * Metoda zwraca typ komorki
	  * true dla typu int, false dla string
	  */
	bool zwroc_typ();

	/** 
	  * Metoda zwraca wartosc komorki typu int
	  *
	  * @param[in,out] calkowita - wartosc komorki
	  */
	void zwroc_zawartosc(int* calkowita);

	/**
	  * Metoda zwraca wartosc komorku typu string
	  *
	  * @param[in,out] str - wartosc komorki
	  */
	void zwroc_zawartosc(string* str);

	/**
	  * Metoda zwraca dlugosc lancucha znakow zawartego w komorce
	  *
	  * @return - dlugosc lancucha
	  */
	int str_len();
};

#endif