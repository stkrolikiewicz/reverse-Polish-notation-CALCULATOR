#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "pliki.h"
#include "interfejs.h"
#include "lista.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "menu.h"
using namespace std;



void exit();
void modyfikujWyrazenie();
void obliczWyrazenie();
void modyfikujZmienne();
void zakoncz();
double zamienStringNaDouble(string napis);
void odlozNaStos(double x);
void pobierzZeStosu();


#endif // FUNKCJE_H
