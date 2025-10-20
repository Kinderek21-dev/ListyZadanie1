#pragma once
using namespace std;

struct Element {
    int wartosc;
    Element* nast;
    Element* poprz;


    Element(int w) : wartosc(w), nast(nullptr), poprz(nullptr) {}

};