#ifndef KOMORKA_H
#define KOMORKA_H
#include <iostream>
#include <string>
using namespace std;

class Komorka
{
private:
	int cos;

public:

	Komorka(int a = 0)
	{
		cos = a;
	}

	//Destruktor wirtualny
	virtual ~Komorka() {};

	// Operator sumy zwraca cos + a
	virtual double operator+ (double& a) { return cos + a; };

	// Operator porownania sprawdza czy cos < a
	virtual bool operator< (double& a) { return cos < a; };

	// Operator porownania  sprawdza czy cos > a
	virtual bool operator> (double& a) { return cos > a; };

	// Operator przypisania dla int
	virtual void operator= (const int& a) {};

	// Operator przypisania dla string
	virtual void operator= (const string& s) {};

	// Operator przypisania dla double
	virtual void operator= (const double& d) {};

	// Operator rzutowania zwraca cos jako lancuch
	virtual operator string() const { return to_string(cos); };

	// Operator rzutowania zwraca cos
	virtual operator int() const { return cos; };

	// Operator rzutowania zwraca cos
	virtual operator double() const { return double(cos); };

	// Metoda zwraca typ komorki (int - 0)
	virtual int zwroc_typ() { return 0; };

	// Metoda zwraca cos jako lancuch
	virtual string zwroc_wartosc() { return to_string(cos); };

	/**
	  * Metoda zmienia wartosc komorki typu int
	  *
	  * @param[in] nowy - nowa wartosc
	  */
	virtual void zmien_wartosc(int nowy) {};

	/**
	  * Metoda zmienia wartosc komorki typu string
	  *
	  * @param[in] nowy - nowa wartosc
	  */
	virtual void zmien_wartosc(string nowy) {};

	/**
	  * Metoda zmienia wartosc komorki typu double
	  *
	  * @param[in] nowy - nowa wartosc
	  */
	virtual void zmien_wartosc(double nowy) {};
};

#endif
