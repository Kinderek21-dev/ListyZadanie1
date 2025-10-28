#include <iostream>
#include "FabrykaListy.h"

using namespace std;

/**
 * @file Program.cpp
 * @brief Plik z funkcja main() — testuje dzialanie listy.
 *
 * Program tworzy liste przez fabryke, wykonuje kilka operacji testowych
 * dodawanie, wstawianie, usuwanie, wyswietlanie i na koncu czysci pamiec.
 *
 */

 /**
  * @brief Funkcja glowna programu testujacego liste dwukierunkowa.
  * @return Kod zakonczenia programu.
  *
  * Przykladowe wyjscie:
  * @code
  * Lista: 10 20 30
  * Lista: 5 10 20 30
  * Lista: 5 10 15 20 30
  * Lista: 10 15 20 30
  * Lista: 10 15 20
  * Lista: 10 15 20 40 50
  * Lista: 10 20 40 50
  * Lista od konca: 50 40 20 10
  * Lista:
  * @endcode
  */
int main() {

    Lista* lista = FabrykaListy::stworzListe();

    lista->dodajNaKoniec(10);
    lista->dodajNaKoniec(20);
    lista->dodajNaKoniec(30);
    lista->pokaz();

    lista->dodajNaPoczatek(5);
    lista->pokaz();

    lista->dodajNaIndeks(15, 2); // wstaw 15 na indeks 2
    lista->pokaz();

    lista->usunZPoczatku();
    lista->pokaz();

    lista->usunZKonca();
    lista->pokaz();

    // test usuwania pod indeksem
    lista->dodajNaKoniec(40);
    lista->dodajNaKoniec(50);
    lista->pokaz();
    lista->usunZIndeksu(1); // usun element na indeksie 1
    lista->pokaz();

    // pokaz odwrotnie
    lista->pokazOdwrotnie();

    // czyszczenie
    lista->czysc();
    lista->pokaz();

    delete lista;

    return 0;
}
