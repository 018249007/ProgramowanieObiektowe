#ifndef TABLICE_H
#define TABLICE_H

/**
  * Funkcja tworzy nowa tablice o zadanym rozmiarze
  *
  * @oaram rozmiar  okresla rozmiar nowej tablicy
  *
  * @return adres nowej tablicy
  */
int* nowa_tablica(int rozmiar);

/**
  * Funkcja wypisuje zawartosc tablicy
  *
  * @param tab  tablica, ktorej wartosci maja zostac wypisane
  * @param rozmiar  rozmiar tej tablicy
  */
void wypisz(int* tab, int rozmiar);

/**
  * Funckja wpisuje nowa wartosc do danej komorki tablicy
  *
  * @param tab  tablica, ktorej element ma zostac zmieniony
  * @param ktory  numer komorki, ktora ma zostac zmieniona
  * @param rozmiar  rozmiar przekazanej tablicy
  * @param nowy  wartosc elementu ktory ma zostac wpisany do danej komorki
  *
  * @return  adres tablicy ze zmieninym elementem
  */
void zmien_element(int* tab, int ktory, int rozmiar, int nowy);

/**
  * Funkcja zmienia rozmiar tablicy
  *
  * @param tab  tablica, ktorej rozmiar ma zostac zmieniony
  * @param rozmiar  stary rozmiar tablicy
  * @param n_rozmiar  rozmiar nowej tablicy
  *
  * @return adres tablicy o nowym rozmiarze
  */
int* zmien_rozmiar(int* tab, int* rozmiar, int n_rozmiar);

#endif
