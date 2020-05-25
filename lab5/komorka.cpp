#include "komorka.h"

void Komorka::zmien_wartosc(int wartosc)
{
    if(zwroc_typ())
    {
        *calkowita = wartosc;
    }
    else
    {
        delete str;
        calkowita = new int;
        *calkowita = wartosc;
    }
    return;
}

void Komorka::zmien_wartosc(string wartosc)
{
    if(!zwroc_typ())
    {
        *str = wartosc;
    }
    else
    {
        delete calkowita;
        str = new string;
        *str = wartosc;
    }
    return;
}

bool Komorka::zwroc_typ()
{
    if(str==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Komorka::zwroc_zawartosc(int* calkowita)
{
    *calkowita = *this->calkowita;
}

void Komorka::zwroc_zawartosc(string* str)
{
    *str = *this->str;
}

int Komorka::str_len()
{
    return (*str).length();
}