#ifndef TABLICE_H
#define TABLICE_H
#define BAZA_INT "BazaInt.txt"
#define BAZA_STR "BazaStr.txt"
#include <fstream>
#include <iostream>
#include "komorka.h"

/**
  * Klasa przechowuje dane o tablicy
  *
  * @param tab  tablica dwywymiarowa
  * @param wiersze  liczba wierszy
  * @param kolumny  liczba kolumn
  */
class Tablica
{
private:
    Komorka*** tab;
    int wiersze;
    int kolumny;

    /**
  * Metoda alokuje pamiec dla tablicy dwuwymiarowej
  *
  * @param[in] kolumny - liczba kolumn
  * @param[in] wiersze - liczba wierszy
  * @param[in] czy_int - typ danych w komorce (true - int, false - str)
  *
  * @return - tablica dwywymiarowa
  */
    Komorka*** alokuj_pamiec(int kolumny, int wiersze, bool czy_int);

    // Metoda zwalnia pamiec tablicy
    void zwolnij_pamiec();

public:
    /**
      * Konstruktor domyslny
      *
      * w przypadku braku argumentow ustawia wartosci kolumn i wierszy na 1
      *
      * @param[in] kolumny - liczba kolumn
      * @param[in] wiersze - liczba wierszy
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      */
    Tablica(int kolumny = 1, int wiersze = 1, bool czy_int = 0)
    {
        this->kolumny = kolumny;
        this->wiersze = wiersze;
        tab = alokuj_pamiec(kolumny, wiersze, czy_int);
    }

    // Destruktor zwalnia pamiec tablicy dwuwymiarowej
    ~Tablica()
    {
        zwolnij_pamiec();
    }

    // Metoda zwraca liczbe kolumn
    int ile_k();

    // Metoda zwraca liczbe wierszy
    int ile_w();

    /**
      * Metoda tworzy nowy zestaw danych obiektu
      *
      * @param[in] n_kolumny - nowa liczba kolumn
      * @param[in] n_wiersze - nowa liczba wierszy
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int nowa_tablica(int n_kolumny, int n_wiersze, bool czy_int);

    /**
      * Metoda odczytuje dane tablicy int z pliku
      *
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int odczyt(bool czy_int);

    /** Metoda zapisuje dane tablicy int do pliku
      *
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      */
    void zapisz(bool czy_int);

    /** Metoda wypisuje zawartosc tablicy int
      *
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      */
    void wypisz();

    /**
      * Metoda zmienia wartosc danej komorki
      *
      * @param[in] ktory_w - numer wiersza
      * @param[in] ktory_k - numer kolumny
      * @param[in] nowy - nowa wartosc
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int zmien_element(int ktory_w, int ktory_k, string nowy, bool czy_int);

    /**
      * Metoda zmienia rozmiar podanej tablicy
      *
      * @param[in] n_kolumny - nowa liczba kolumn
      * @param[in] n_wiersze - nowa liczba wierszy
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int zmien_rozmiar(int n_kolumny, int n_wiersze, bool czy_int);

    /** 
      * Metoda sumuje wszystkie wartosci w kolumnie
      * dla komorek typu string sumuje dlugosci
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_k(int numer, int* wynik);

    /**
      * Metoda sumuje wszystkie wartosci w wierszu
      * dla komorek typu string sumuje dlugosci
      *
      * @param[in] numer - numer wiersza
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_w(int numer, int* wynik);

    /**
      * Metoda znajduje najmniejsza wartosc w kolumnie
      * dla komorek typu string najkrotszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_k(int numer, int* wynik, bool czy_int);

    /**
      * Metoda znajduje najmniejsza wartosc w wierszu
      * dla komorek typu string najkrotszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_w(int numer, int* wynik, bool czy_int);

    /**
      * Metoda znajduje najwieksza wartosc w kolumnie
      * dla komorek typu string najdluzszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_k(int numer, int* wynik, bool czy_int);

    /**
      * Metoda znajduje najwiieksza wartosc w wierszu
      * dla komorek typu string najdluzszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_w(int numer, int* wynik, bool czy_int);

    /**
      * Metoda oblicza srednia wartosc dla danej kolumny
      * dla komorek typu string srednia dlugosc lancucha
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_k(int numer, float* wynik, bool czy_int);

    /**
      * Metoda oblicza srednia wartosc dla danego wiersza
      * dla komorek typu string srednia dlugosc lancucha
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      * @param[in] czy_int - typ danych w komorce (true - int, false - str)
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_w(int numer, float* wynik, bool czy_int);
};

#endif
