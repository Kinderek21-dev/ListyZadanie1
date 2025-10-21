#include <iostream>
#include "FabrykaListy.h"
using namespace std;

int main() {
    Lista* lista = FabrykaListy::stworzListe();

    lista->dodajNaKoniec(10);
    lista->dodajNaKoniec(20);
    lista->dodajNaKoniec(30);
    lista->pokaz();
    lista->dodajNaPoczatek(5);
    lista->pokaz();
    lista->dodajNaIndeks(15, 2);
    lista->pokaz();
    lista->usunZPoczatku();
    lista->pokaz();
    lista->usunZKonca();
    lista->pokaz();

    delete lista;
    return 0;
}