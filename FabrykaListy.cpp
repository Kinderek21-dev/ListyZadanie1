#include "FabrykaListy.h"

/**
 * @file FabrykaListy.cpp
 * @brief Implementacja metody fabrycznej stworzListe().
 */

 /**
  * @brief Tworzy nowa liste przy uzyciu operatora new i zwraca wskaznik.
  *
  */
Lista* FabrykaListy::stworzListe() {
    return new Lista();
}
