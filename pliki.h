/**
 * \file pliki.h
 * \brief Plik nagłówkowy modułu Pliki
 *
 * Zawiera on deklaracje funkcji potrzebnych do działania na plikach tekstowych.
 */
#ifndef PLIKI_H
#define PLIKI_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
/**
 * \brief Funkcja, która pobiera zawartość pliku
 *
 * Deklaracja funkcji, która ma pobrać i zwrócić zawartość pliku w postaci napisu.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 * \return zawartosc napis przechwujący zawartość pliku tekstowego
 */
string pobierzZawartosc(string nazwa_pliku);
/**
 * \brief Funkcja, która usuwa zawartość pliku
 *
 * Deklaracja funkcji, która ma usunąć zawartość pliku.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 */
void usunZawartosc(string nazwa_pliku);
/**
 * \brief Funkcja, która edytuje zawartość pliku
 *
 * Deklaracja funkcji, która ma edytować zawartość pliku.
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 */
void edytujZawartosc(string nazwa_pliku);
/**
 * \brief Funkcja, która usuwa plik tekstowy
 *
 * Deklaracja funkcji, która ma usunąć podany plik tekstowy
 * \param nazwa_pliku ścieżka docelowego pliku tekstowego
 */
void usunPlik(string nazwa_pliku);

#endif // PLIKI_H
