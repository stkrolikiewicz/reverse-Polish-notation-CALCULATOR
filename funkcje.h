/**
 * \file funkcje.h
 * \brief Plik nagłówkowy modułu Funkcje
 *
 * Zawiera on deklaracje najbardziej istotnych funkcji programu, służących do obliczania i edytowania wyrażenia oraz
 * tworzenia i modyfikacji zmiennych.
 */
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
/**
 * \brief Funkcja modyfikująca wyrazenie
 *
 * Deklaracja funkcji, która daje możliwość modyfikacji wyrazenia zapisanego w pliku tekstowym, które następnie jest obliczane.
 */
void modyfikujWyrazenie();
/**
 * \brief Funkcja obliczająca wyrazenie
 *
 * Deklaracja funkcji, która ma obliczać wyrażenie zapisane w pliku tekstowym.
 */
void obliczWyrazenie();
/**
 *\brief Funkcja modyfikująca zmienne
 *
 * Deklaracja funkcji, która ma dawać możliwość modyfikacji lub/i dodawania zmienncyh przez użytkownika.
 */
void modyfikujZmienne();
/**
 * \brief Zamień napis na liczbę
 *
 * Deklaracja funkcji, która ma zmieniać napis przedstawiający jakąś liczbę na zmienną typu double.
 * \param napis reprezentuje ciąg cyfr, ale jeszcze nie jest liczbą
 * \return x liczba, która jest już typu double
 */
double zamienStringNaDouble(string napis);
/**
 * \brief Funkcja odkłada liczbę na stos
 *
 * Deklaracja funkcji, która ma odkładać podaną wartość (double) na stos, tak aby w późniejszym etapie wartość została pobrana zmanipulowana przed następujący po niej operator.
 * \param x liczba odkladana na stos jako wartos nowego elementu listy argumentów
 */
void odlozNaStos(double x);
/**
 * \brief Funkcja, która interpetuje operator
 *
 * Deklaracja funkcji, która ma interpretować jaki operator matematyczny spośród '+', '-', '/', '*' lub '^' ma być użyty.
 * \param a znak, który ma zostać zinterpretowany
 * \param &zero flaga, która ma wskazywać, czy operator dzielenie ma dzielić przez zero
 * \return liczba zwracana jako wartosc wyniku dzialania z uzyciem operatora
 */
double jakiOperator(char a, bool &zero);
/**
 * \brief Funkcja sprawdza, czy zawarty w wyrażeniu ciąg znaków jest zmienną
 *
 * Deklaracja funkcji, która ma na celu, sprawdzić, czy zawarte w wyrażeniu ciągi wyrazów są zmiennymi wprowadzonymi wcześniej
 * przez użytkownika.
 * \param &f flaga, która daje informacje, czy istnieje zmienna o podanej nazwie
 * \param &t
 * \param &val
 * \param T[] tablica znakow, które połączeniu tworzą szukaną nazwę
 * \param n rozmiar tablicy
 * \param &i nr pierwszego znaku ciągu wyrazów w tablicy
 * \param &wynik zapisuje wynik, w przypadku, gdy ciąg jest sinusem lub cosinusem
 */
void czyToZmienna(bool &f, bool &t, double &val, char T[], int n, int &i, double &wynik);
/**
 * \brief Funkcja sprawdza, czy zawarty w wyrazeniu ciąg znaków jest operatorem sinus lub cosinus
 *
 * Deklaracja funkcji, która ma na celu określenie, czy dany ciąg znaków jest operatorem sinus lub cosinus.
 * \param &f flaga, która informuje, czy badany ciąg znaków w wyrażeniu jest sinusem lub cosinusem
 * \param &name zmienna, która przechowuje wartość znalezionego operatora (sin lub cos)
 * \param T[] talica, która przechowuje kolejne znaki wyrazenia
 * \param n rozmiar tablicy
 * \param i nr pierwszego wyrazu ciagu
 */
void czySinCos(bool &f, string &name, char T[], int n, int i);
/**
 * \brief Funkcja obliczająca funkcje trygonometryczną
 *
 * Deklaracja funkcji, która oblicza sinus lub cosinus wartości.
 * \param name nazwa funkcji trygonometrycznej
 */
double obliczSinCos(string name);
/**
 * \brief Funkcja dodająca zmienne
 *
 * Deklaracja funkcji, która ma umożliwiać dodawanie nowych zmiennych.
 * \param name nazwa nowej zmienej
 * \param value wartosc liczbowa nowej zmiennej
 * \param &c flaga, która informuje, czy zmienna o podanej nazwie już istnieje
 */
void dodajZmienna(string name,double value, bool &c);
/**
 * \brief Funkcja edytująca zmienne
 *
 * Deklaracja funkcji, która edytuje wybraną zmienną.
 * \param i nr zmiennej
 */
void edytujZmienna(int i);


#endif // FUNKCJE_H
