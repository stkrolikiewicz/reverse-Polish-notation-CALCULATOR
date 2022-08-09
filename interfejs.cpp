/**
 * \file interfejs.cpp
 * \brief Plik implementacji modułu Interfejs
 *
 * Zawiera on definicje podstawowych funkcji interfejsu, zawartych w pliku nagłowkowym,
 * które mają na celu usprawnienie poruszania się użytkownika po aplikacji
 */
#include "interfejs.h"
#include "funkcje.h"
#include "lista.h"
#include <iostream>

using namespace std;

/**
 * \brief Intro
 *
 * Funkcja, która wita użytkownika w Kalkulatorze ONP.
 */
void intro() {
    cout << "Witamy w kalkulatorze obliczajacym wyrazenia zapisane w Odwrotnej Notacji Polskiej!" << endl;
}
/**
 * \brief Powrót do Menu
 *
 * Funkcja, która cofa użytkownika do menu głównego.
 */
void wrocDoMenu() {
    system("cls");
    menu();
}
/**
 * \brief Powrót do wyboru opcji modyfikacji zmiennych
 *
 * Funkcja, która cofa użytkownika do menu, które przedstawia opcje modyfikowania zmiennych.
 * Funkcja realizuje się poprzez wyczyszczenie ekranu wiersza poleceń oraz wywołanie
 * funkcji \b modyfikujZmienne().
 */
void wrocDoModyfikacji() {
    /// Czyszczenie ekranu.
    system("cls");
    /// Wywołaniewywołanie funkcji \b modyfikujZmienne().
    modyfikujZmienne();
}
/**
 * \brief Exit
 *
 * Funkcja, która kończy działanie programu.
 */
void exit() {
    /// Czyszczenie ekranu.
    system("cls");
    /// Zmienna \b a\c, która przechowuje znak wpisany przez użytkownika.
    char a;
    /// Pętla, która ma powtarza się dopóki użytkownik nie zdeycduje się, czy chce zakończyc działanie programu, czy nie.
    do {
        cout << "Czy na pewno chcesz zakonczyc dzialanie programu? (Y/N) ";
        cin >> a;
    }
    while (!(a == 'Y' || a == 'N' || a == 'n' || a == 'y'));

    if (a == 'N' || a == 'n')
        wrocDoMenu();

}
