/**
 * \file pliki.cpp
 * \brief Plik implementacji modułu Pliki
 *
 * Zawiera on definicje funkcji potrzebnych do działania na plikach tekstowych.
 */
#include "pliki.h"

/**
 * \brief Funkcja, która pobiera zawartość pliku
 *
 * Definicja funkcji, która pobiera i zwraca zawartość pliku w postaci napisu.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 * \return zawartosc napis przechwujący zawartość pliku tekstowego
 */
string pobierzZawartosc(string nazwa_pliku) {
    string zawartosc;
    ifstream plik_odczyt(nazwa_pliku.c_str());
    getline(plik_odczyt, zawartosc);
    plik_odczyt.close();
    return zawartosc;
}
/**
 * \brief Funkcja, która usuwa zawartość pliku
 *
 * Definicja funkcji, która usuwa zawartość pliku.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 */
void usunZawartosc(string nazwa_pliku) {
    ofstream plik_zapis(nazwa_pliku.c_str());
    plik_zapis << "";
    plik_zapis.close();
}
/**
 * \brief Funkcja, która edytuje zawartość pliku
 *
 * Definicja funkcji, która ma edytuje zawartość pliku.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 */
void edytujZawartosc(string nazwa_pliku) {
//    string zawartosc = pobierzZawartosc(nazwa_pliku);
    ofstream plik_zapis(nazwa_pliku.c_str());

//    cout << "Zawartosc: " << zawartosc << endl;
//    cout << "Edytuj zawartosc: ";
    string napis;
    //cin.sync();
    cin.ignore();
    //cin >> napis;
    getline(cin, napis);
    plik_zapis << napis;
    plik_zapis.close();
}
