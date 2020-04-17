#ifndef TABLICE_H
#define TABLICE_H
#define BAZA "Baza.txt"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
  * Funkcja tworzy tablice o podanej ilosci kolumn i wierszy
  *
  * @param kolumny  liczba kolumn tworzonej tablicy
  * @oaram wiersze  liczba wierszy tworzonej tablicy
  *
  * @return utworzona tablica
  */
int** nowa_tablica(int kolumny, int wiersze);

/**
  * Funckja odczytuje dane o nowej tablicy z pliku
  *
  * @param kolumny  aktualna liczba kolumn, wartosc zostanie wpisana z pliku
  * @param wiersze  aktualna liczba wierszy, wartosc zostanie wpisana z pliku
  * w przypadku pustego pliku wartosci te zostaja ustawione na 1
  *
  * @return tablica utwrzona z danych odczytanych z pliku
  */
int** odczyt(int* kolumny, int* wiersze);

/**
  * Funckja zapisuje dane o tablicy do pliku
  *
  * @param tab  tablica, ktora ma zostac zapisana
  * @param kolumny  liczba kolumn tej tablicy
  * @param wiersze  liczba wierszy tej tablicy
  */
void zapis(int** tab, int* kolumny, int* wiersze);

/**
  * Funckja wypisuje zawartosc przekazanej tablicy
  *
  * @param tab  tablica, ktorej dane maja zostac wypisane
  * @param kolumny  liczba kolumn tej tablicy
  * @param wiersze  liczba wierzy tej tablicy
  */
void wypisz(int** tab, int kolumny, int wiersze);

/**
  * Funkcja zmienia wartosc danej komorki
  *
  * @param tab  tablica, ktora ma zostac zmieniona
  * @param ktory_w  numer wiersza, w ktorym znajduje sie szukana komorka
  * @param ktory_k  numer kolumny, w ktorej znajduje sie szukana komorka
  * @param kolumny  liczba kolumny w podanej tablicy
  * @param wiersze  liczba wierszy w podanej tablicy
  * @param nowy  wartosc, ktora ma zostac wpisana do danej komorki
  */
void zmien_element(int** tab, int ktory_w, int ktory_k, int kolumny, int wiersze, int nowy);

/**
  * Funkcja zmienia rozmiar podanej tablicy
  *
  * @param tab  tablica, ktorej rozmiar ma zostac zmieniony
  * @param kolumny  liczba kolumn przekazanej tablicy
  * @param wiersze  liczba wierszy przekazanej tablicy
  * @param n_kolumny  liczba kolumn nowej tablicy
  * @param n_wiersze  liczba wierszy nowej tablicy
  *
  * @return tablica o nowym rozmiarze
  */
int** zmien_rozmiar(int** tab, int* kolumny, int* wiersze, int n_kolumny, int n_wiersze);

#endif
