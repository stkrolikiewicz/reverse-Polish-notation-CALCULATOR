#include "interfejs.h"
#include "funkcje.h"
#include "lista.h"
#include <iostream>

using namespace std;

void intro() {
    cout << "Witamy w kalkulatorze obliczajacym wyrazenia zapisane w Odwrotnej Notacji Polskiej!" << endl;
}

void wrocDoMenu() {
    system("cls");
    menu();
}

void exit() {
    system("cls");
    char a;
    do {
        cout << "Czy na pewno chcesz zakonczyc dzialanie programu? (Y/N) ";
        cin >> a;
    }
    while (!(a == 'Y' || a == 'N' || a == 'n' || a == 'y'));

    if (a == 'N' || a == 'n')
        wrocDoMenu();

}
