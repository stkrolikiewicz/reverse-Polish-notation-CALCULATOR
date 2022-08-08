#include "pliki.h"


string pobierzZawartosc(string nazwa_pliku) {
    string zawartosc;
    ifstream plik_odczyt(nazwa_pliku.c_str());
    getline(plik_odczyt, zawartosc);
    plik_odczyt.close();
    return zawartosc;
}

void usunZawartosc(string nazwa_pliku) {
    ofstream plik_zapis(nazwa_pliku.c_str());
    plik_zapis << "";
    plik_zapis.close();
}

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
