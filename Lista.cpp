#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista() {
    a = nullptr;
    b = nullptr;
    rozmiar = 0;
}

Lista::~Lista() {
    czysc();
}

void Lista::dodajNaPoczatek(int wartosc) {
    Element* nowy = new Element(wartosc);
    if (!a) {
        a = b = nowy;
    }
    else {
        nowy->nast = a;
        a->poprz = nowy;
        a = nowy;
    }
    rozmiar++;
}

void Lista::dodajNaKoniec(int wartosc) {
    Element* nowy = new Element(wartosc);
    if (!b) {
        a = b = nowy;
    }
    else {
        b->nast = nowy;
        nowy->poprz = b;
        b = nowy;
    }
    rozmiar++;
}

void Lista::dodajNaIndeks(int wartosc, int indeks) {
    if (indeks <= 0) { dodajNaPoczatek(wartosc); return; }
    if (indeks >= rozmiar) { dodajNaKoniec(wartosc); return; }

    Element* temp = a;
    for (int i = 0; i < indeks - 1; i++)
        temp = temp->nast;

    Element* nowy = new Element(wartosc);
    nowy->nast = temp->nast;
    nowy->poprz = temp;
    temp->nast->poprz = nowy;
    temp->nast = nowy;
    rozmiar++;
}

void Lista::usunZPoczatku() {
    if (!a) return;
    Element* temp = a;
    a = a->nast;
    if (a) a->poprz = nullptr;
    else b = nullptr;
    delete temp;
    rozmiar--;
}

void Lista::usunZKonca() {
    if (!b) return;
    Element* temp = b;
    b = b->poprz;
    if (b) b->nast = nullptr;
    else a = nullptr;
    delete temp;
    rozmiar--;
}

void Lista::usunZIndeksu(int indeks) {
    if (indeks < 0 || indeks >= rozmiar) return;
    if (indeks == 0) { usunZPoczatku(); return; }
    if (indeks == rozmiar - 1) { usunZKonca(); return; }

    Element* temp = a;
    for (int i = 0; i < indeks; i++)
        temp = temp->nast;

    temp->poprz->nast = temp->nast;
    temp->nast->poprz = temp->poprz;
    delete temp;
    rozmiar--;
}

void Lista::pokaz() {
    Element* temp = a;
    cout << "Lista: ";
    while (temp) {
        cout << temp->wartosc << " ";
        temp = temp->nast;
    }
    cout << endl;
}

void Lista::pokazOdwrotnie() {
    Element* temp = b;
    cout << "Lista od konca: ";
    while (temp) {
        cout << temp->wartosc << " ";
        temp = temp->poprz;
    }
    cout << endl;
}

void Lista::czysc() {
    while (a) {
        usunZPoczatku();
    }
}

int Lista::size() const {
    return rozmiar;
}
