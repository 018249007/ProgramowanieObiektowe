#ifndef TABLICE_H
#define TABLICE_H
#define BAZA "Baza.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
  * Klasa przechowuje dane o tablicy
  *
  * @param tab - tablica dwywymiarowa
  * @param wiersze - liczba wierszy
  * @param kolumny - liczba kolumn
  */
class Tablica
{
private:
    int** tab;
    int wiersze;
    int kolumny;

    /**
  * Metoda alokuje pamiec dla tablicy dwuwymiarowej
  *
  * @param[in] kolumny - liczba kolumn
  * @param[in] wiersze - liczba wierszy
  *
  * @return - tablica dwywymiarowa
  */
    int** alokuj_pamiec(int kolumny, int wiersze);

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
      */
    Tablica(int kolumny = 1, int wiersze = 1)
    {
        this->kolumny = kolumny;
        this->wiersze = wiersze;
        tab = alokuj_pamiec(kolumny, wiersze);
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
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int nowa_tablica(int n_kolumny, int n_wiersze);

    /**
      * Metoda odczytuje dane tablicy z pliku
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int odczyt();

    // Metoda zapisuje dane tablicy do pliku
    void zapis();

    // Metoda wypisuje zawartosc tablicy
    void wypisz();

    /**
      * Metoda zmienia wartosc danej komorki
      *
      * @param[in] ktory_w - numer wiersza
      * @param[in] ktory_k - numer kolumny
      * @param[in] nowy - nowa wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int zmien_element(int ktory_w, int ktory_k, int nowy);

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
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_k(int numer, int* wynik);

    /**
      * Metoda sumuje wszystkie wartosci w wierszu
      *
      * @param[in] numer - numer wiersza
      * @param[in,out] wynik - obliczona suma
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int sumuj_w(int numer, int* wynik);

    /**
      * Metoda znajduje najmniejsza wartosc w kolumnie
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_k(int numer, int* wynik);

    /**
      * Metoda znajduje najmniejsza wartosc w wierszu
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int min_w(int numer, int* wynik);

    /**
      * Metoda znajduje najwieksza wartosc w kolumnie
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_k(int numer, int* wynik);

    /**
      * Metoda znajduje najwiieksza wartosc w wierszu
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - znaleziona wartosc
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int max_w(int numer, int* wynik);

    /**
      * Metoda oblicza srednia wartosc dla danej kolumny
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_k(int numer, float* wynik);

    /**
      * Metoda oblicza srednia wartosc dla danego wiersza
      *
      * @param[in] numer - numer kolumny
      * @param[in,out] wynik - obliczona wartosc srednia
      *
      * @return - kod bledu lub 0 w przypadku powodzenia
      */
    int srednia_w(int numer, float* wynik);
};

#endif
