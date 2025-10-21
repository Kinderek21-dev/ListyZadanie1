#include <iostream>
#include "FabrykaListy.h"
using namespace std;

int main() {
    cout << "======" << endl;

    Lista* lista = FabrykaListy::stworzListe();

    lista->dodajNaKoniec(10);
    lista->dodajNaKoniec(20);
    lista->dodajNaKoniec(30);
    lista->dodajNaPoczatek(5);
    lista->dodajNaIndeks(15, 2);
    lista->usunZPoczatku();
    lista->usunZKonca();

    delete lista;

    cout << "======" << endl;
    return 0;
}