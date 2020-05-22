#ifndef TABLICE_H
#define TABLICE_H
#define BAZA "Baza.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
  * Struktura przechowuje dane o tablicy
  *
  * @param tab - tablica dwywymiarowa
  * @param wiersze - liczba wierszy
  * @param kolumny - liczba kolumn
  */
struct Tablica
{
    int** tab;
    int wiersze;
    int kolumny;
};

/**
  * Funkcja tworzy tablice o podanej ilosci kolumn i wierszy
  *
  * @param[in,out] nowa - zmienna typu Tablica*
  * @param[in] kolumny - liczba kolumn
  * @oaram[in] wiersze - liczba wierszy
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int nowa_tablica(Tablica* nowa, int kolumny, int wiersze);

/**
  * Funkcja zwalnia zaalokowana pamiec
  *
  * @param[in,out] tab - zmienna typu Tablica*
  */
void zwolnij_pamiec(Tablica* tab);

/**
  * Funkcja odczytuje dane o nowej tablicy z pliku
  *
  * @param[in,out] tablica - zmienna typu Tablica*
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int odczyt(Tablica* tablica);

/**
  * Funkcja zapisuje dane o tablicy do pliku
  *
  * @param[in] tablica - zmienna typu Tablica
  */
void zapis(Tablica tablica);

/**
  * Funkcja wypisuje zawartosc przekazanej tablicy
  *
  * @param[in] tablica - zmienna typu Tablica
  */
void wypisz(Tablica tablica);

/**
  * Funkcja zmienia wartosc danej komorki
  *
  * @param[in,out] tablica - zmienna typu Tablica*
  * @param[in] ktory_w - numer wiersza
  * @param[in] ktory_k - numer kolumny
  * @param[in] nowy - nowa wartosc
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int zmien_element(Tablica* tablica, int ktory_w, int ktory_k, int nowy);

/**
  * Funkcja zmienia rozmiar podanej tablicy
  *
  * @param[in,out] tab - zmienna typu Tablica*
  * @param[in] n_kolumny - nowa liczba kolumn
  * @param[in] n_wiersze - nowa liczba wierszy
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int zmien_rozmiar(Tablica* tablica, int n_kolumny, int n_wiersze);

/**
  * Funkcja sumuje wszystkie komorki danej kolumny
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - obliczona suma
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int sumuj_k(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja sumuje wszystkie komorki danego wiersza
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer wiersza
  * @param[in,out] wynik - obliczona suma
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int sumuj_w(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja znajduje najwieksza wartosc w danej kolumnie
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - znaleziona wartosc
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int max_k(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja znajduje najwieksza wartosc w danym wierszu
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - znaleziona wartosc
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int max_w(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja znajduje najmniejsza wartosc w danej kolumnie
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - znaleziona wartosc
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int min_k(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja znajduje najmniejsza wartosc w danym wierszu
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - znaleziona wartosc
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int min_w(Tablica tablica, int numer, int* wynik);

/**
  * Funkcja oblicza srednia wartosc dla danej kolumny
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - obliczona srednia
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int srednia_k(Tablica tablica, int numer, float* wynik);

/**
  * Funkcja oblicza srednia wartosc dla danego wiersza
  *
  * @param[in] tablica - zmienna typu Tablica
  * @param[in] numer - numer kolumny
  * @param[in,out] wynik - obliczona srednia
  *
  * @return kod bledu lub 0 w przypadku powodzenia
  */
int srednia_w(Tablica tablica, int numer, float* wynik);

#endif
