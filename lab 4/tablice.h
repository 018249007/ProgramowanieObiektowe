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
  * @param tab  tablica dwywymiarowa
  * @param wiersze  liczba wierszy tab
  * @param kolumny  liczba kolumn tab
  */
class Tablica
{
private:
    int** tab;
    int wiersze;
    int kolumny;
public:
    /**
      * Konstruktor domyslny
      *
      * w przypadku braku argumentow ustawia wartosci kolumn i wierszy na 1
      *
      * @param kolumny  liczba kolumn nowej tablicy
      * @param wiersze  liczba wierszy nowej tablicy
      */
    Tablica(int kolumny = 1, int wiersze = 1)
    {
        this->kolumny = kolumny;
        this->wiersze = wiersze;
        nowa_tablica();
    }
    // Zwraca liczbe kolumn
    int ile_k();

    // Zwraca liczbe wierszy
    int ile_w();

    // Metoda tworzy nowa tablice
    void nowa_tablica();

    // Metoda zwalnia pamiec tablicy
    void zwolnij_pamiec();

    // Metoda odczytuje dane tablicy z pliku
    void odczyt();

    // Metoda zapisuje dane tablicy do pliku
    void zapis();

    // Metoda wypisuje zawartosc tablicy
    void wypisz();

    /**
      * Metoda zmienia wartosc danej komorki
      *
      * @param ktory_w  numer wiersza, w ktorym znajduje sie szukana komorka
      * @param ktory_k  numer kolumny, w ktorej znajduje sie szukana komorka
      * @param nowy  wartosc, ktora ma zostac wpisana do danej komorki
      */
    void zmien_element(int ktory_w, int ktory_k, int nowy);

    /**
      * Metoda zmienia rozmiar podanej tablicy
      *
      * @param n_kolumny  liczba kolumn nowej tablicy
      * @param n_wiersze  liczba wierszy nowej tablicy
      */
    void zmien_rozmiar(int n_kolumny, int n_wiersze);

    // Metoda sumuje wszystkie kolumny zawarte w tablicy i wypisuje wartosci
    void sumuj_k();

    // Metoda sumuje wszystkie wiersze zawarte w tablicy i wypisuje wartosci
    void sumuj_w();

    // Metoda wypisuje najmniejsze i najwieksze wartosci dla kazdej kolumny w tablicy
    void naj_k();

    // Metoda wypisuje najmniejsze i najwieksze wartosci dla kazdego wiersza w tablicy
    void naj_w();

    // Metoda oblicza srednia wartosc dla kazdej kolumny w tablicy oraz wypisuje ja
    void srednia_k();

    // Metoda oblicza srednia wartosc dla kazdego wiersza w tablicy i wypisuje ja
    void srednia_w();
};

#endif
