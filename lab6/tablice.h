#ifndef TABLICE_H
#define TABLICE_H
#define BAZA "Baza.txt"
#include <fstream>
#include "Ikomorka.h"
#include "komorkaInt.h"
#include "komorkaStr.h"
#include "komorkaDbl.h"

/**
  * Klasa przechowuje dane o tablicy
  *
  * @param tab - tablica dwywymiarowa
  * @param wiersze - liczba wierszy
  * @param kolumny - liczba kolumn
  * @param typy - typy kolumn, 0 - int, 1 - string, 2 - double
  */
class Tablica
{
private:
    Komorka*** tab;
    int* typy;
    int wiersze;
    int kolumny;

    /**
  * Metoda alokuje pamiec dla tablicy dwuwymiarowej
  *
  * @param[in] kolumny - liczba kolumn
  * @param[in] wiersze - liczba wierszy
  * @param[in,out] typy - tablica typow kolumn (0 - int, 1 - string, 2 - double)
  *
  * @return - tablica dwywymiarowa
  */
    Komorka*** alokuj_pamiec(int kolumny, int wiersze, int* typy);

    // Metoda zwalnia pamiec tablicy
    void zwolnij_pamiec();

    // Metoda pobiera typy kolumn od uzytkownika
    void pobierz_typy();

public:

    // Konstruktor bezparametrowy
    Tablica()
    {
        kolumny = 1;
        wiersze = 1;
        typy = new int[1];
        typy[0] = 0;
        tab = alokuj_pamiec(1, 1, typy);
    }

    /**
      * Konstruktor parametrowy
      *
      * @param[in] kolumny - liczba kolumn
      * @param[in] wiersze - liczba wierszy
      */
    Tablica(unsigned int kolumny, unsigned int wiersze)
    {
        this->kolumny = kolumny;
        this->wiersze = wiersze;
        typy = new int[kolumny];
        pobierz_typy();
        tab = alokuj_pamiec(kolumny, wiersze, typy);
    }

    // Destruktor zwalnia pamiec tablicy dwuwymiarowej
    ~Tablica()
    {
        for (int i = 0; i < wiersze;i++)
        {
            for (int j = 0; j < kolumny; j++)
            {
                delete tab[j][i];
            }
        }
        zwolnij_pamiec();
    }

    // Metoda zwraca liczbe kolumn
    int ile_k();

    // Metoda zwraca liczbe wierszy
    int ile_w();

    /**
      * Metoda zmienia typ kolumny
      *
      * @param[in] numer - numer kolumny
      * @param[in] typ - nowy typ
      *
      * @return kod bledu lub 0 w przypadku powodzenia
      */
    int ustaw_typ(int numer, int typ);

    /**
      * Metoda tworzy nowy zestaw danych obiektu
      *
      * @param[in] n_kolumny - nowa liczba kolumn
      * @param[in] n_wiersze - nowa liczba wierszy
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int nowa_tablica(int n_kolumny, int n_wiersze);

    /**
      * Metoda odczytuje dane tablicy int z pliku
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int odczyt();

    // Metoda zapisuje dane tablicy int do pliku
    void zapisz();

    // Metoda wypisuje zawartosc tablicy int
    void wypisz();

    /**
      * Metoda zmienia wartosc danej komorki
      *
      * @param[in] ktory_w - numer wiersza
      * @param[in] ktory_k - numer kolumny
      * @param[in] nowy - nowa wartosc string
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int zmien_element(int ktory_w, int ktory_k, string nowy);

    /**
      * Metoda zmienia rozmiar podanej tablicy
      *
      * @param[in] n_kolumny - nowa liczba kolumn
      * @param[in] n_wiersze - nowa liczba wierszy
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int zmien_rozmiar(int n_kolumny, int n_wiersze);

    /** 
      * Metoda sumuje wszystkie wartosci w kolumnie
      * dla komorek typu string sumuje dlugosci
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_k(int numer, double* wynik);

    /**
      * Metoda sumuje wszystkie wartosci w wierszu
      * dla komorek typu string sumuje dlugosci
      *
      * @param[in] numer - numer wiersza
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_w(int numer, double* wynik);

    /**
      * Metoda znajduje najmniejsza wartosc w kolumnie
      * dla komorek typu string najkrotszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_k(int numer, double* wynik);

    /**
      * Metoda znajduje najmniejsza wartosc w wierszu
      * dla komorek typu string najkrotszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_w(int numer, double* wynik);

    /**
      * Metoda znajduje najwieksza wartosc w kolumnie
      * dla komorek typu string najdluzszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_k(int numer, double* wynik);

    /**
      * Metoda znajduje najwiieksza wartosc w wierszu
      * dla komorek typu string najdluzszy lancuch
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_w(int numer, double* wynik);

    /**
      * Metoda oblicza srednia wartosc dla danej kolumny
      * dla komorek typu string srednia dlugosc lancucha
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_k(int numer, double* wynik);

    /**
      * Metoda oblicza srednia wartosc dla danego wiersza
      * dla komorek typu string srednia dlugosc lancucha
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_w(int numer, double* wynik);
};

#endif
