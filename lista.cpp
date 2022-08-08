#include "lista.h"

Argument *stworzStos(double x) {
    Argument *stos = new Argument;
    stos->x = x;
    stos->next = nullptr;
    return stos;
};

void dodajElement(Argument *&glowa, double liczba) {
    if (!glowa) {
        glowa = stworzStos(liczba);
//        Argument *glowa = new Argument;
//        glowa->x = liczba;
//        glowa->next = nullptr;
//        Argument *ogon = glowa;
    }
    else {
        Argument *nowy = new Argument;
        nowy->x = liczba;
        nowy->next = glowa;
        glowa = nowy;
    }
}

void usunElementZeStosu(Argument *&glowa) {
    if (!glowa)
        cout << "Stos jest pusty!" << endl;
    else {
        Argument *tmp = glowa;
        glowa = glowa->next;
        delete tmp;
    }
}

void wyczyscStos(Argument *&glowa) {
    while (glowa) {
        Argument *tmp = glowa;
        glowa = glowa->next;
        delete tmp;
    }
    cout << "Stos jest pusty!" << endl;
}

void wypiszStos(Argument *glowa) {
    if (glowa) {
        cout <<  glowa->x << endl;
        wypiszStos(glowa->next);
    }
    else
        cout << "Koniec stosu" << endl;
}
