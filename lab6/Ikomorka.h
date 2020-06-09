#ifndef IKOMORKA_H
#define IKOMORKA_H
#include <iostream>
#include <string>
using namespace std;

class Komorka
{
public:

	//Destruktor wirtualny
	virtual ~Komorka() {}

	// Operator sumy
	virtual double operator+ (double& a) = 0;

	// Operator porownania <
	virtual bool operator< (double& a) = 0;

	// Operator porownania >
	virtual bool operator> (double& a) = 0;

	// Operator przypisania
	virtual void operator= (const string& s) = 0;

	// Operator rzutowania
	virtual operator double() const = 0;

	// Metoda zwraca wartosc komorki
	virtual string zwroc_wartosc() = 0;
};

#endif
