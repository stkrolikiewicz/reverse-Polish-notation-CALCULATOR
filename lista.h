#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

struct Argument {
    double x;
    Argument *next;
};

struct Zmienna {
    string nazwa;
    double wartosc;
    Zmienna *next;
};

//funkcje/procedury do działania na zmiennych
void dodajZmienna();
void usunZmienna(Zmienna *&w);
void usunWszystkieZmienne(Zmienna *&w);
void wypiszListeZmiennych(Zmienna *w);

//funkcje/procedury do działania na stosie
Argument *stworzStos();
void dodajElement(Argument *&glowa, double liczba);
void wyczyscStos(Argument *&glowa);
void usunElementZeStosu(Argument *&glowa);
void wypiszStos(Argument *glowa);



#endif // LISTA_H
