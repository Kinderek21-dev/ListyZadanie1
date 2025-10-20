#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista() {
    glowa = nullptr;
    ogon = nullptr;
    rozmiar = 0;
}

Lista::~Lista() {
    czysc();
}

void Lista::dodajNaPoczatek(int wartosc) {
    Element* nowy = new Element(wartosc);
    if (!glowa) {
        glowa = ogon = nowy;
    }
    else {
        nowy->nast = glowa;
        glowa->poprz = nowy;
        glowa = nowy;
    }
    rozmiar++;
}

void Lista::dodajNaKoniec(int wartosc) {
    Element* nowy = new Element(wartosc);
    if (!ogon) {
        glowa = ogon = nowy;
    }
    else {
        ogon->nast = nowy;
        nowy->poprz = ogon;
        ogon = nowy;
    }
    rozmiar++;
}

void Lista::dodajNaIndeks(int wartosc, int indeks) {
    if (indeks <= 0) { dodajNaPoczatek(wartosc); return; }
    if (indeks >= rozmiar) { dodajNaKoniec(wartosc); return; }

    Element* temp = glowa;
    for (int i = 0; i < indeks - 1; i++)
        temp = temp->nast;

    Element* nowy = new Element(wartosc);
    nowy->nast = temp->nast;
    nowy->poprz = temp;
    temp->nast->poprz = nowy;
    temp->nast = nowy;
    rozmiar++;
}