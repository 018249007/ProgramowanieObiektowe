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
  * @param tab  tablica dwywymiarowa
  * @param wiersze  liczba wierszy tab
  * @param kolumny  liczba kolumn tab
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
  * @param nowa  wskaznik na zmienna strukturalna przechowujaca informacje o tablicy
  * @param kolumny  liczba kolumn tworzonej tablicy
  * @oaram wiersze  liczba wierszy tworzonej tablicy
  */
void nowa_tablica(Tablica* nowa, int kolumny, int wiersze);

/**
  * Funkcja odczytuje dane o nowej tablicy z pliku
  *
  * @param tablica  wskaznik na zmienna strukturalna przechowujaca informacje o tablicy
  * w przypadku pustego pliku liczba kolumn i wierszy zostaje ustawiona na 1
  */
void odczyt(Tablica* tablica);

/**
  * Funkcja zapisuje dane o tablicy do pliku
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void zapis(Tablica tablica);

/**
  * Funkcja wypisuje zawartosc przekazanej tablicy
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void wypisz(Tablica tablica);

/**
  * Funkcja zmienia wartosc danej komorki
  *
  * @param tablica  wskaznik na zmienna strukturalna przechowujaca informacje o tablicy
  * @param ktory_w  numer wiersza, w ktorym znajduje sie szukana komorka
  * @param ktory_k  numer kolumny, w ktorej znajduje sie szukana komorka
  * @param nowy  wartosc, ktora ma zostac wpisana do danej komorki
  */
void zmien_element(Tablica* tablica, int ktory_w, int ktory_k, int nowy);

/**
  * Funkcja zmienia rozmiar podanej tablicy
  *
  * @param tab  wskaznik na zmienna strukturalna przechowujaca informacje o tablicy
  * @param n_kolumny  liczba kolumn nowej tablicy
  * @param n_wiersze  liczba wierszy nowej tablicy
  */
void zmien_rozmiar(Tablica* tablica, int n_kolumny, int n_wiersze);

/**
  * Funkcja sumuje wszystkie kolumny zawarte w tablicy i wypisuje wartosci
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void sumuj_k(Tablica tablica);

/**
  * Funkcja sumuje wszystkie wiersze zawarte w tablicy i wypisuje wartosci
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void sumuj_w(Tablica tablica);

/**
  * Funkcja wypisuje najmniejsze i najwieksze wartosci dla kazdej kolumny w tablicy
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void naj_k(Tablica tablica);

/**
  * Funkcja wypisuje najmniejsze i najwieksze wartosci dla kazdego wiersza w tablicy
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void naj_w(Tablica tablica);

/**
  * Funkcja oblicza srednia wartosc dla kazdej kolumny w tablicy oraz wypisuje ja
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void srednia_k(Tablica tablica);

/**
  * Funkcja oblicza srednia wartosc dla kazdego wiersza w tablicy i wypisuje ja
  *
  * @param tablica  zmienna strukturalna przechowujaca informacje o tablicy
  */
void srednia_w(Tablica tablica);

#endif
