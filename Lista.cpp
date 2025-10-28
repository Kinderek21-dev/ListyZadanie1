#include "Lista.h"
#include <iostream>

using namespace std;

/**
 * @file Lista.cpp
 * @brief Implementacja klasy Lista uzywajacej `a` poczatek i `b` koniec.
 */

 /**
  * @brief Konstruktor — tworzy pusta liste.
  */
Lista::Lista() {
    a = nullptr;
    b = nullptr;
    rozmiar = 0;
}

/**
 * @brief Destruktor — czysci liste.
 */
Lista::~Lista() {
    czysc();
}

/**
 * @brief Dodaje element na poczatek listy.
 * @param wartosc wartosc do dodania
 *
 */
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

/**
 * @brief Dodaje element na koniec listy.
 * @param wartosc wartosc do dodania
 */
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

/**
 * @brief Wstawia element pod dany indeks (0 = poczatek).
 * @param wartosc wartosc do wstawienia
 * @param indeks indeks docelowy
 *
 * Jesli indeks <= 0 -> wstawia na poczatek.
 * Jesli indeks >= rozmiar -> wstawia na koniec.
 */
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

/**
 * @brief Usuwa element z poczatku listy.
 */
void Lista::usunZPoczatku() {
    if (!a) return;
    Element* temp = a;
    a = a->nast;
    if (a) a->poprz = nullptr;
    else b = nullptr;
    delete temp;
    rozmiar--;
}

/**
 * @brief Usuwa element z konca listy.
 */
void Lista::usunZKonca() {
    if (!b) return;
    Element* temp = b;
    b = b->poprz;
    if (b) b->nast = nullptr;
    else a = nullptr;
    delete temp;
    rozmiar--;
}

/**
 * @brief Usuwa element pod wskazanym indeksem.
 * @param indeks indeks do usuniecia
 */
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

/**
 * @brief Wypisuje liste od poczatku do konca.
 */
void Lista::pokaz() {
    Element* temp = a;
    cout << "Lista: ";
    while (temp) {
        cout << temp->wartosc << " ";
        temp = temp->nast;
    }
    cout << endl;
}

/**
 * @brief Wypisuje liste od konca do poczatku.
 */
void Lista::pokazOdwrotnie() {
    Element* temp = b;
    cout << "Lista od konca: ";
    while (temp) {
        cout << temp->wartosc << " ";
        temp = temp->poprz;
    }
    cout << endl;
}

/**
 * @brief Czysci liste.
 */
void Lista::czysc() {
    while (a) {
        usunZPoczatku();
    }
}

/**
 * @brief Zwraca liczbe elementow na liscie.
 */
int Lista::size() const {
    return rozmiar;
}
