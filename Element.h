#pragma once

/**
 * @file Element.h
 * @brief Definicja struktury Element uzywanej w liscie dwukierunkowej.
 *
 * Plik zawiera prosta strukture reprezentujaca wezel listy dwukierunkowej.
 * Kazdy wezel przechowuje wartosc int oraz wskazniki na element poprzedni i nastepny.
 *
 */

using namespace std;

/**
 * @struct Element
 * @brief Reprezentuje pojedynczy wezel listy dwukierunkowej.
 *
 * Struktura zawiera prosta wartosc typu calkowitego oraz dwa wskazniki:
 * nast  — wskaznik na nastepny element w liscie,
 * poprz — wskaznik na poprzedni element w liscie.
 *
 * Wezel alokowany jest dynamicznie w metodach klasy Lista.
 * Po usunieciu elementu pamiec musi zostac zwolniona przez operator delete.
 *
 */
struct Element {
    int wartosc;     ///< Wartosc przechowywana w elemencie
    Element* nast;   ///< Wskaznik na nastepny element (nullptr jesli brak)
    Element* poprz;  ///< Wskaznik na poprzedni element (nullptr jesli brak)

    /**
     * @brief Konstruktor inicjalizujacy wartosc i ustawia wskazniki na null.
     * @param w Wartosc, ktora ma byc przechowana w elemencie.
     *
     * Konstruktor upraszcza tworzenie nowego wezla ustawia pola wskaznikowe
     * na nullptr, dzieki czemu nowy element jest gotowy do wstawienia do listy.
     */
    Element(int w) : wartosc(w), nast(nullptr), poprz(nullptr) {}
};
