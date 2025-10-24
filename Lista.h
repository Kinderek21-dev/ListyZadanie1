#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

class Lista {
private:
    Element* a;
    Element* b;
    int rozmiar;

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
