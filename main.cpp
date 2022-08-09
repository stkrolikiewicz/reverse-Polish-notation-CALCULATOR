/**
 * \mainpage
 * \par Kalkulator Odwrotnej Notacji Polskiej
 * Program obliczający wyrażenia zapisane w odrwotnej notacji polskiej.
 * \author Stanisław Królikiewicz
 * \date 2021.05.26
 * \version 1.0
 * \par Kontakt:
 * \a stanislaw.krolikiewicz.stud@pw.edu.pl
 *
 * Odwrotna notacja polska w skrócie ONP jest algorytmem stosowanym do zapisu wyrażeń arytmetycznych bez użycia nawiasów. Powstał on na podstawie notacji polskiej stworzonej przez polskiego matematyka Jana Łukasiewicza.
 */
/**
 * \file main.cpp
 * \brief Główny plik źródłowy.
 */
#include "funkcje.h"

int main()
{
    /**
     * \brief Intro
     *
     * Funkcja, która wyświetla się tylko raz na początku. Funkcja wita użytkownika w Kalkulatorze ONP.
     */
    intro();
    /**
     * \brief Menu
     *
     * Funkcja nawigująca po programie.
     */
    menu();
    return 0;
}
