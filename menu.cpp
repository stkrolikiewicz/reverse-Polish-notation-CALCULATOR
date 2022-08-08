#include "menu.h"

void menu(){
    int a;
    cout << "Wybierz obcje:" << endl
         << "1. Wprowadz/edytuj i oblicz wyrazenie." << endl
         << "2. Wprowadz lub edytuj zmienne." << endl
         << "3. Zakoncz." << endl;
    cin >> a;
    switch (a)
    {
        case 1:
            modyfikujWyrazenie();
            break;
        case 2:
            modyfikujZmienne();
            break;
        case 3:
            exit();
            break;
    }
}
