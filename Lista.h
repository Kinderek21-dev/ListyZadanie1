#pragma once
#include "Element.h"
using namespace std;

class Lista {
private:
    Element* glowa;
    Element* ogon;
    int rozmiar;

public:
    Lista();
    ~Lista();

    void dodajNaPoczatek(int wartosc);
    void dodajNaKoniec(int wartosc);
    void dodajNaIndeks(int wartosc, int indeks);

    void usunZPoczatku();
    void usunZKonca();
    void pokaz();
};