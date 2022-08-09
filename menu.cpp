/**
 * \file menu.cpp
 * \brief Plik impementacji modułu Menu.
 */

#include "menu.h"

/**
 * \brief Menu
 *
 * Funkcja, która nawiguje po programie. Daje do wyboru 3 opcje:
 * \li 1. Wprowadź lub edytuj i następnie oblicz wyrazenie.
 * \li 2. Wprowadź lub edytuj zmienne.
 * \li 3. Zakończ działanie programu.
 */
void menu(){
    /// Zmienna b, która będzie przechowywała napis wprowadzany przez użytkownika
    string b;
    /// Zmienna a, która pobiera pierwszy znak z napisu b
    char a;
    /**
     * Zmienna counter ma na celu zliczanie powtórzeń pętli \b do \b {...} \b while \b (...)
     * tak aby pomóc użytkownikowi wpisanie oczekiwanej wartości zmiennej b
     */
    int counter = 0;
    /**
     * Pętla \b do \b {...} \b while \b (...) która ma celu doprowadzenie użytkownika do wyboru jedej z trzech opcji.
     * Pętla powtarza się do momentu wpisania napisu, którego pierwszy znak będzie równy 1, 2 lub 3.
     */
    do {
        cout << "Wybierz opcje:" << endl
             << "1. Wprowadz/edytuj i oblicz wyrazenie." << endl
             << "2. Wprowadz lub edytuj zmienne." << endl
             << "3. Zakoncz." << endl;
        /// W przypadku, gdy pierwszy znak wpisanego napisu po kolejny nie jest jedną z opcji, wyświetla sie komunikat, ze wpisywana wartość jest nepoprawna.
        if (a != '1' && a != '2' && a != '3' && counter > 0)
            cout << "Wpisana wartosc jest niepoprawna. ";
        cout << "Prosze wpisac wartosc od 1 do 3." << endl;

        cin >> b;
        a = b[0];
        counter++;
        system("cls");
    } while (a != '1' && a != '2' && a !='3');
    /// Po poprawnym wybraniu opcji licznik powtórzeń się zeruje.
    counter = 0;
    /// Instrukcja \b switch \b ... \b case która zależy od zmiennej a
    switch (a)
    {
        case '1':
            modyfikujWyrazenie();
            break;
        case '2':
            modyfikujZmienne();
            break;
        case '3':
            exit();
            break;
    }
}
