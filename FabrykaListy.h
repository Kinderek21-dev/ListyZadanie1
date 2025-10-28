#pragma once
#include "Lista.h"
using namespace std;

/**
 * @file FabrykaListy.h
 * @brief Deklaracja prostego wzorca Fabryka dla klasy Lista.
 *
 */

 /**
  * @class FabrykaListy
  * @brief Klasa zawierajaca statyczna metode tworzaca obiekt Lista.
  *
  *  metoda stworzListe zwraca nowy obiekt utworzony przy pomocy
  * operatora new. W dokumentacji Doxygen zobaczysz opis fabryki i powiazania.
  */
class FabrykaListy {
public:
    /**
     * @brief Tworzy i zwraca nowa instancje klasy Lista.
     * @return Wskaznik na nowo utworzona liste.
     * @note Funkcja zwraca surowy wskaznik (Lista*).
     */
    static Lista* stworzListe();
};
