/**
 * \file interfejs.h
 * \brief Plik nagłówkowy modułu Interfejs
 *
 * Zawiera on deklaracje podstawowych funkcji interfejsu, które mają na celu
 * usprawnienie poruszania się użytkownika po aplikacji
 */
#ifndef INTERFEJS_H
#define INTERFEJS_H
/// \brief Deklaracja funkcji intro.
void intro();
/// \brief Deklaracja funkcji, która wraca do menu głównego.
void wrocDoMenu();
/// \brief Deklaracja funkcji, która wraca do wyboru opcji modyfikowania zmiennych.
void wrocDoModyfikacji();
/// \brief Deklaracja funkcji, która kończy działanie programu.
void exit();

#endif // INTERFEJS_H
