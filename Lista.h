#pragma once
#include "Element.h"
#include <iostream>

using namespace std;

/**
 * @file Lista.h
 * @brief Deklaracja klasy Lista (lista dwukierunkowa).
 *
 */

 /**
  * @class Lista
  * @brief Prosta implementacja listy dwukierunkowej.
  *
  * `a` wskazuje na pierwszy element listy,
  * `b` wskazuje na ostatni element listy.
  */
class Lista {
private:
    Element* a;   ///< Wskaznik na pierwszy element 
    Element* b;   ///< Wskaznik na ostatni element 
    int rozmiar;  ///< Liczba elementow w liscie

public:
    Lista();
    ~Lista();

    void dodajNaPoczatek(int wartosc);
    void dodajNaKoniec(int wartosc);
    void dodajNaIndeks(int wartosc, int indeks);

    void usunZPoczatku();
    void usunZKonca();
    void usunZIndeksu(int indeks);

    void pokaz();
    void pokazOdwrotnie();
    void czysc();

    int size() const;
};
