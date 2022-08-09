/**
 * \file lista.h
 * \brief Plik nagłówkowy modułu Lista
 *
 * Zawiera on deklaracje funkcji potrzebnych do działania na listach.
 */
#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;
/**
 * \brief Element listy dynamicznej
 *
 * Definicja elementu jednokierunkowej listy argumentów, która docelowo ma służyć ajko stos.
 */
struct Argument {
    /// Wartość elementu
    double x;
    // Wskaźnik na następny element listy
    Argument *next;
};
/**
 * \brief Element listy dynamicznej
 *
 * Definicja elementu jednokierunkowej listy zmiennych.
 */
struct Zmienna {
    /// Nazwa zmiennej
    string nazwa;
    /// Wartość liczbowa przechowywana przez zmienną
    double wartosc;
    /// Wskaźnik na następny element listy
    Zmienna *next;
};

//funkcje/procedury do działania na zmiennych

/**
 * \brief Funkcja usuwająca zmienną
 *
 * Deklaracja funkcji, która ma ma usuwać wybraną zmienna.
 * \param *&w wskaźnik typu Zmienna
 * \param i nr zmiennej
 */
void usunZmienna(Zmienna *&w, int i);
/**
 * \brief Funkcja usuwająca wszystkie zmienne
 *
 * Deklaracja funkcji, która usuwa wszystkie elementy listy zmiennych.
 * \param *&w wskaźnik typu Zmienna
 */
void usunWszystkieZmienne(Zmienna *&w);
/**
 * \brief Funkcja wypisująca listę zmiennych
 *
 * Deklaracja funkcji, która wypisuje wszystkie elementy listy zmiennych.
 * \param *w wskaźnik typu Zmienna
 * \param i liczba do numeracji kolejnych elementów listy
 */
void wypiszListeZmiennych(Zmienna *w, int i);

//funkcje/procedury do działania na stosie

/**
 * \brief Funkcja, która tworzy stos
 *
 * Deklaracja funkcji, która ma zaalokować pamięć na głowę stosu.
 * \return stos wskaźnik do pierwszego elementu stosu
 */
Argument *stworzStos();
/**
 * \brief Funkcja, dodaje element do stosu
 *
 * Deklaracja funkcji, która ma dodać nowy element do stosu
 * \param *&glowa wskaźnik do głowy listy argumentów
 * \param liczba wartość liczbowa nowego elementu
 */
void dodajElement(Argument *&glowa, double liczba);
/**
 * \brief Funkcja, która czyści stos
 *
 * Deklaracja funkcji, która ma usunąć wszystkie elementy ze stosu, czyli listy dynamicznej jednokierunowej argumentów
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void wyczyscStos(Argument *&glowa);
/**
 * \brief Funkcja, która usuwa pierwszy element ze stosu
 *
 * Deklaracja funkcji, która ma usunąć pierwszy argument ze stosu, czyli głowę listy dynamicznej.
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void usunElementZeStosu(Argument *&glowa);
/**
 * \brief Funkcja wypisująca stos
 *
 * Deklaracja funkcji, która ma wypisać listę dynamiczną jednokierunkową argumentów.
 * \param *&glowa wskaźnik do głowy listy argumentów
 */
void wypiszStos(Argument *glowa);

#endif // LISTA_H
