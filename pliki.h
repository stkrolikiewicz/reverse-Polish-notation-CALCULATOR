#ifndef PLIKI_H
#define PLIKI_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

string pobierzZawartosc(string nazwa_pliku);
void usunZawartosc(string nazwa_pliku);
void edytujZawartosc(string nazwa_pliku);
void usunPlik(string nazwa_pliku);

#endif // PLIKI_H
