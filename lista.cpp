/**
 * \file lista.cpp
 * \brief Plik implementacji modułu Lista
 *
 * Zawiera on definicje funkcji potrzebnych do działania na listach.
 */
#include "lista.h"
#include "funkcje.h"
/**
 * \brief Funkcja, która tworzy stos
 *
 * Definicja funkcji, która alokuje pamięć na głowę stosu.
 * \return stos wskaźnik do pierwszego elementu stosu
 */
Argument *stworzStos(double x) {
    Argument *stos = new Argument;
    stos->x = x;
    stos->next = nullptr;
    return stos;
};
/**
 * \brief Funkcja, dodaje element do stosu
 *
 * Definicja funkcji, która dodaje nowy element do stosu
 * \param *&glowa wskaźnik do głowy listy argumentów
 * \param liczba wartość liczbowa nowego elementu
 */
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
/**
 * \brief Funkcja, która usuwa pierwszy element ze stosu
 *
 * Definicja funkcji, która usuwa pierwszy argument ze stosu, czyli głowę listy dynamicznej.
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void usunElementZeStosu(Argument *&glowa) {
    if (!glowa)
        cout << "Stos jest pusty!" << endl;
    else {
        Argument *tmp = glowa;
        glowa = glowa->next;
        delete tmp;
    }
}
/**
 * \brief Funkcja, która czyści stos
 *
 * Definicja funkcji, która usuwa wszystkie elementy ze stosu, czyli listy dynamicznej jednokierunowej argumentów
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void wyczyscStos(Argument *&glowa) {
    while (glowa) {
        Argument *tmp = glowa;
        glowa = glowa->next;
        delete tmp;
    }
}
/**
 * \brief Funkcja wypisująca stos
 *
 * Definicja funkcji, która wypisuje listę dynamiczną jednokierunkową argumentów.
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void wypiszStos(Argument *glowa) {
    if (glowa) {
        cout <<  glowa->x << endl;
        wypiszStos(glowa->next);
    }
    else
        cout << "Koniec stosu" << endl;
}
/**
 * \brief Funkcja, która tworzy głowę listy zmiennych
 *
 * Definicja funkcji, która alokuje pamięć na pierwszą zmienną.
 * \param x wartość liczbowa pierwszej zmiennej
 * \return glowa wskaźnik do pierwszego elementu listy
 */
Zmienna *listaZmiennych(double x) {
    Zmienna *glowa = new Zmienna;
    glowa->nazwa = "pierwszaZmienna";
    glowa->wartosc = x;
    glowa->next = nullptr;
    return glowa;
}
/**
 * \brief Funkcja usuwająca zmienną
 *
 * Definicja funkcji, która usuwa wybraną zmienna.
 * \param *&w wskaźnik typu Zmienna
 * \param i nr zmiennej
 */
void usunZmienna(Zmienna *&glowa, int i) {
    Zmienna *tmp = nullptr;
    Zmienna *za = nullptr;
    if (!glowa)
        cout << "Brak zmiennych!" << endl;
    else {
        if (i == 1) {
           tmp = glowa;
           glowa = glowa->next;
           delete tmp;
        } else {
            za = glowa;
            for (int j = 1; j < i-1; j++) {
                if (za->next)
                    za = za->next;
                else {
                    cout << "Nie ma tylu zmiennych!" << endl;
                    break;
                }
            }
            if (za->next) {
                tmp = za->next;
                if (tmp->next) {
                    za->next = tmp->next;
                    delete tmp;
                }
            }
        }
    }
}
/**
 * \brief Funkcja usuwająca wszystkie zmienne
 *
 * Definicja funkcji, która usuwa wszystkie elementy listy zmiennych.
 * \param *&w wskaźnik typu Zmienna
 */
void usunWszystkieZmienne(Zmienna *&w) {

    while (w) {
        Zmienna *tmp = w;
        w = w->next;
        delete tmp;
    }
    cout << "Zmienne zostaly usuniete." << endl << endl;
}
/**
 * \brief Funkcja wypisująca listę zmiennych
 *
 * Definicja funkcji, która wypisuje wszystkie elementy listy zmiennych.
 * \param *w wskaźnik typu Zmienna
 * \param i liczba do numeracji kolejnych elementów listy
 */
void wypiszListeZmiennych(Zmienna *w, int i) {
    int j;
    if (w) {
        j = i + 1;
        cout << j << ". " << w->nazwa << " = "<< w->wartosc << endl;
        wypiszListeZmiennych(w->next, j);
    }
}
