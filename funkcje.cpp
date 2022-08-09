/**
 * \file funkcje.cpp
 * \brief Plik implementacji modułu Funkcje
 *
 * Zawiera on definicje najbardziej istotnych funkcji programu, służących do obliczania i edytowania wyrażenia oraz
 * tworzenia i modyfikacji zmiennych.
 */

#include "funkcje.h"
/// ustalanie sciezki do pliku przechowującego wyrazenie
const string nazwa_pliku = "wyrazenie.txt";
/// inicjowanie stosu
Argument *stos = nullptr;
/// inicjowanie listy dynamicznej jednokierunkowej zmiennych
Zmienna *listaZmiennych = nullptr;
/**
 * \brief Funkcja modyfikująca wyrazenie
 *
 * Definicja funkcji, która daje możliwość modyfikacji wyrazenia zapisanego w pliku tekstowym, które następnie jest obliczane.
 */
void modyfikujWyrazenie() {
    system("cls");
    string wyrazenie = pobierzZawartosc(nazwa_pliku.c_str());
    if (wyrazenie == "") {
        cout << "Wprowadz wyrazenie: " << endl;
        edytujZawartosc(nazwa_pliku);
    }
    else {
        char a;
        do {
            cout << "Czy chcesz edytowac wyrazenie: '" << wyrazenie << "' (Y/N) ";
            cin >> a;
        }
        while (!(a == 'Y' || a == 'N' || a == 'n' || a == 'y'));

        if (a == 'N' || a == 'n');
        else {
            cout << "Edytuj wyrazenie: "<< wyrazenie << endl << setw(18) << "| ";
            edytujZawartosc(nazwa_pliku);
        }
    }
    obliczWyrazenie();
    wrocDoMenu();
}
/**
 * \brief Funkcja obliczająca wyrazenie
 *
 * Definicja funkcji, która oblicza wyrażenie zapisane w pliku tekstowym.
 */
void obliczWyrazenie() {
    bool correct = true, zero = false, isVar = false, isTri = false; // zmienna, sprawdzająca poprawność zapisu wyrażenia
    cout << "Obliczam..." << endl;
    string wyrazenie = pobierzZawartosc(nazwa_pliku); // zmienna przechwująca wyrażenie wprowadzone przez użytkownika
    string liczba = "", trigName = "", ostatnie3litery = ""; // zmienna pomocnicza do zapisywania kolejnych wyrazów wyrażenia
    int n = wyrazenie.length(), lVar = 0; // długość wyrażenia
    char T[n];
    double x = 0.0, wynik = 0.0, varVal;
    // wypełniamy tablicę znakami wyrazenia
    for (int i = 0; i < n; i++) {
        T[i] = wyrazenie[i];
    }
    for (int i = n-3; i < n; i++)
        ostatnie3litery += T[i];

    if (ostatnie3litery == "sin" || ostatnie3litery == "sin" || ((ostatnie3litery[2] == '+' || ostatnie3litery[2] == '-' || ostatnie3litery[2] == '*' || ostatnie3litery[2] == '/' || ostatnie3litery[2] == '^') && ostatnie3litery[1] == ' ')) {
        for (int i = 0; i < n; i++) { // pętla powtarza się tyle razy ile jest znaków w wyrażeniu
            if (T[i] >= 48 && T[i] <= 57) // jeżeli znak jest liczbą, to zmienna liczba dodaje znak do obecnego napisu
                liczba = liczba + T[i];

            if (T[i] == 46 || T[i] == 44) { // jeżeli aktualny znak jest przecinkiem lub kropką
                    if ((i > 0 && T[i-1] == 32  ) || i == 0)    // ale nie ma liczby przed przecinkiem
                        liczba = liczba + '0';                  // dodajemy do liczby '0' ponieważ np ".0001 = 0.0001"
                    if(i>0 && (T[i-1] == 46 || T[i-1] == 44)) { // w przypadku, gdy ponownie pojawia się przecinek lub kropka, wyskakuje błąd
                        cout << "Blad!!! Niepoprawny zapis!";
                        correct = false;                        // status poprawności: false
                        break;                                  // wychodzimy z pętli for
                    }
                    liczba = liczba + T[i];
            }

            if (T[i] == '-' && T[i+1] >= 48 && T[i+1] <= 57 && i < n-1) { //liczba ujemna
                liczba = T[i] + liczba;
            }

            if (((T[i] >= 65 && T[i] <= 90) || (T[i] >= 97 && T[i] <= 122)) && ((i>0 && T[i-1] == 32) || i == 0)) {
                czyToZmienna(isVar, isTri, varVal, T, n, i, wynik);
                if (isVar) {
                    dodajElement(stos, varVal);
                }
                else if (isTri) {
                }
                else {
                    cout << "Blad! Niepoprawny zapis zmiennej/funkcji!";
                    correct = false;
                    break;
                }
            }
            if (T[i] == 32) {
                if (T[i-1] >= 48 && T[i-1] <= 57 || T[i-1] == 46 || T[i-1] == 44) { //jeżeli znak jest spacją i przed spacją będzie liczba lub przecinek
                    if (i > 0 &&  i != n-1 && T[i-1] == 32) { // jeżeli mamy dwie spacje po sobie pojawia się błąd, wychodzimy z pętli
                        cout << "Blad!!! Niepoprawny zapis!";
                        correct = false;                        // status poprawności:false
                        break;
                    }
                    if (!isVar) {
                        x = zamienStringNaDouble(liczba); // zamiana obecnej liczby, która jest napisem na liczbę zmniennoprzecinkową x
                        odlozNaStos(x); // odkładamy na stos liczbę
                    }

                    liczba = ""; // zerujemy liczbę jako napis
                    // jeżeli aktualny znak nie jest ani liczbą ani spacją ani przecinkiem ani kropką
                }
            }
            isVar = false;
            isTri = false;
            if (i>0 && T[i-1] == 32)
                if ((i<n-1 && T[i+1] == 32) || i == n-1)
                    wynik = jakiOperator(T[i], zero);
                else if (!((T[i] >= 48 && T[i] <= 57) || T[i] == 46 || T[i] == 44 || T[i] == '-')) {
                    cout << "Blad!" <<endl;
                    correct = false;
                    break;
                }

            if (zero) {
                correct = false;
                break;
            }
        }
        if (stos->next) {
            cout << endl << "Niepoprawny zapis wyrazenia. Kazdy operator dziala na dwoch poprzedzajacych wartosciach. Funkcje sin i cos daja wartosc z jednego poprzedzajacego argumentu argumentu. To oznacza, ze skladnia jest niepoprawna i/lub j"
                    "est za duzo wartosic jak na ilosc operatorow i/ lub funkcji." << endl << endl;
            correct = false;
        }
        if (correct) cout << wyrazenie << " = " << wynik << endl << endl;
        wyczyscStos(stos);

    }
    else
        cout << "Blad! Na koncu wyrazenia musi byc operator lub funkcja sin lub cos." << endl;
    char a;
    do {
        cout << "Jesli chcesz wrocic do menu wcisnij 'T' i  ENTER" << endl;
        cin >> a;
    } while (!(a == 'T' || a == 't'));
    correct = true;
    zero = false;
}
/**
 *\brief Funkcja modyfikująca zmienne
 *
 * Definicja funkcji, daje możliwość modyfikacji lub/i dodawania zmienncyh przez użytkownika.
 */
void modyfikujZmienne() {
    int a, i = 0, n = 0, counter = 0, counter2 = 0;
    char k;
    double x;
    string liczba = "", b;
    bool ok = false, correct = true;
    string nazwa = "";
    do {
        cout << "Wybierz opcje:" << endl
             << "1. Dodaj zmienna." << endl
             << "2. Edytuj zmienna." << endl
             << "3. Usun zmienna." << endl
             << "4. Usun wszystkie zmienne." << endl
             << "5. Wypisz liste zmiennych." << endl
             << "6. Powrot do menu." << endl;
        if (a != '1' && a != '2' && a !='3' && a != '4' && a != '5' && a !='6' && counter2 > 0)
            cout << "Wpisana wartosc jest niepoprawna. ";
        cout << "Prosze wpisac wartosc od 1 do 6." << endl;
        cin >> b;
        a = b[0];
        counter2++;
        system("cls");
    } while (a != '1' && a != '2' && a !='3' && a != '4' && a != '5' && a !='6');
    counter2 = 0;
    switch (a)
    {
        case '1':
            while (!((nazwa[0] >= 65 && nazwa[0] <= 90) || (nazwa[0] >= 97 && nazwa[0] <= 122)) || nazwa == "cos" || nazwa == "sin" || correct == false) {
                correct = true;
                cout << "Wprowadz nazwe zmiennej (musi zaczynac sie litera): ";
                cin >> nazwa;
                if (nazwa == "sin") {
                    cout << "Blad! Nazwa 'sin' jest zarezerwowana dla funkcji sinus." << endl;
                }

                if (nazwa == "cos") {
                    cout << "Blad! Nazwa 'cos' jest zarezerwowana dla funkcji cosinus." << endl;
                }
                if(!((nazwa[0] >= 65 && nazwa[0] <= 90) || (nazwa[0] >= 97 && nazwa[0] <= 122)))
                    cout << "Blad! Zmienna musi sie zaczynac litera." << endl;
                for (int i = 0; i < nazwa.length(); i++){
                    if(!((nazwa[i] >= 48 && nazwa[i] <= 57) || (nazwa[i] >= 65 && nazwa[i] <= 90) || (nazwa[i] >= 97 && nazwa[i] <= 122) || nazwa[i] == '_')) {
                        cout << "Blad! Prosze nie uzywac znakow specjalnych do tworzenia nazw zmiennych. Jedyny dopuszczalny znak poza literami i liczbami to: '_'." << endl;
                        correct = false;
                        break;
                    }
                }
            }
            while (!ok) {
                cout << "Wprowadz wartosc zmiennej (to musi byc liczba): ";
                cin >> liczba;
                n = liczba.length();
                for (int j = 0; j < n; j++) {
                    if(!(liczba[j] >= 48 && liczba[j] <= 57)) {
                        if(liczba[j] == 46 || liczba[j] == 44) {
                            counter++;
                            if (counter > 1) {
                                cout << "Bledny zapis! Za duzo przecinkow lub/i kropek." << endl;
                                ok = 0;
                                counter = 0;
                                break;
                            }
                        }
                        else if (liczba[j] == '-') {
                            if (j > 0) {
                                cout << "Blad! Minus moze byc tylko na poczatku liczby." << endl;
                                ok = 0;
                                break;
                            }
                        }
                        else {
                            cout << "Blad! Podane wyrazenie nie jest liczba." << endl;
                                    ok = 0;
                                    break;
                        }
                    }
                    else
                        ok = 1;
                }
            }
            if (ok) {
                x = zamienStringNaDouble(liczba);
            }
            dodajZmienna(nazwa, x, ok);
            if (ok) {

                cout << "Dodano zmienna: " << nazwa << " = " << x << endl;
                do {
                    cout << "Wcisnij 'T' i  ENTER, aby wrocic do menu" << endl;
                    cin >> k;
                } while (!(k == 'T' || k == 't'));
            }
            wrocDoModyfikacji();
            break;
        case '2':
            cout << "Ktory element chcesz edytowac? Podaj nr:";
            cin >> i;
            edytujZmienna(i);
            modyfikujZmienne();
            break;
        case '3':
            cout << "Ktory element chcesz usunac? Podaj nr:";
            cin >> i;
            usunZmienna(listaZmiennych, i);
            wrocDoModyfikacji();
            break;
        case '4':
            usunWszystkieZmienne(listaZmiennych);
            cout << "Kliknij dowolny klawisz i nastepnie ENTER aby wrocic do poprzedniego menu.";
            cin >> k;
            wrocDoModyfikacji();
            break;
        case '5':
            if (listaZmiennych)
                cout << "Lista zmiennych:" << endl;
            else
                cout << "Nie ma zadnych zmiennych." << endl;
            wypiszListeZmiennych(listaZmiennych, 0);
            cout << endl;
            cout << "Kliknij dowolny klawisz i nastepnie ENTER aby wrocic do poprzedniego menu.";
            cin >> k;
            wrocDoModyfikacji();
            break;
        case '6':
            wrocDoMenu();
            break;
    }
}
/**
 * \brief Zamień napis na liczbę
 *
 * Definicja funkcji, która zamienia napis przedstawiający jakąś liczbę na zmienną typu double.
 * \param napis reprezentuje ciąg cyfr, ale jeszcze nie jest liczbą
 * \return x liczba, która jest już typu double
 */
double zamienStringNaDouble(string napis) {

    int p = 0;


    double x = 0.0;
    if (napis[0] == '-') {
        p = 1;
    }
    int n = napis.length()-p;
    char T[n];
    int counter = 0, commaIndex = n, exponent = 0;
    for (int i = 0; i < n; i++)
        T[i] = napis[i+p];

    for (int i = 0; i < n; i++) {
        if (T[i] == 46 || T[i] == 44) {
            counter++;
            commaIndex = i;
        }
        if (counter >= 2)
            break;
    }
    if (counter == 0) {
        for (int i = n-1; i >= 0; i--) {
            x += (double(T[i] - 48))*pow(10, exponent);
            exponent++;
        }
        exponent = 0;
    }
    else if (counter == 1) {
        for (int i = commaIndex-1; i >= 0; i--) {
            x += (double(T[i] - 48))*pow(10, exponent);
            exponent++;
        }
        exponent = 0;
        for (int i = commaIndex+1; i < n; i++) {
            exponent--;
            x += (double(T[i] - 48))*pow(10, exponent);
        }
    }
    else {
      cout << "Blad!: Bledny zapis liczby -> za duzo kropek lub/i przecinkow!" << endl
           << "counter = " << counter << endl;
      x = 0.0;
    }
    if (napis[0] == '-') {
        x = x *(-1);
    }

    return x;
}
/**
 * \brief Funkcja odkłada liczbę na stos
 *
 * Definicja funkcji, która odkłada podaną wartość (double) na stos, tak aby w późniejszym etapie wartość została pobrana zmanipulowana przed następujący po niej operator.
 * \param x liczba odkladana na stos jako wartos nowego elementu listy argumentów
 */
void odlozNaStos(double x) {
    dodajElement(stos, x);
}
/**
 * \brief Funkcja, która interpetuje operator
 *
 * Definicja funkcji, która interpretuje jaki opersator matematyczny spośród '+', '-', '/', '*' lub '^' ma być użyty.
 * \param a znak, który ma zostać zinterpretowany
 * \param &zero flaga, która ma wskazywać, czy operator dzielenie ma dzielić przez zero
 * \return liczba zwracana jako wartosc wyniku dzialania z uzyciem operatora
 */
double jakiOperator(char a, bool &zero) {
    double p;
    if (stos && stos->next) {
        p = stos->x;
        usunElementZeStosu(stos);

        if (a == '*') {
            p = stos->x * p;
            usunElementZeStosu(stos);
        }
        if (a == '/') {
            if (p == 0.0) {
                cout << "Bledny zapis. Nie mozna dzielic przez zero";
                zero = true;
            }
            else {
                p = stos->x / p;
                usunElementZeStosu(stos);
            }
        }

        if (a == '+') {
                p = stos->x + p;
                usunElementZeStosu(stos);
        }
        if (a == '-') {
                p = stos->x - p;
                usunElementZeStosu(stos);
        }
        if (a == '^') {
            p = pow(stos->x, p);
            usunElementZeStosu(stos);
        }
        odlozNaStos(p);
        cout << endl;
    }
    return p;
}
/**
 * \brief Funkcja sprawdza, czy zawarty w wyrażeniu ciąg znaków jest zmienną
 *
 * Definicja funkcji, która sprawdzaa czy zawarte w wyrażeniu ciągi wyrazów są zmiennymi wprowadzonymi wcześniej
 * przez użytkownika.
 * \param &f flaga, która daje informacje, czy istnieje zmienna o podanej nazwie
 * \param &t
 * \param &val
 * \param T[] tablica znakow, które połączeniu tworzą szukaną nazwę
 * \param n rozmiar tablicy
 * \param &i nr pierwszego znaku ciągu wyrazów w tablicy
 * \param &wynik zapisuje wynik, w przypadku, gdy ciąg jest sinusem lub cosinusem
 */
void czyToZmienna(bool &f, bool &t, double &val, char T[], int n, int &i, double &wynik) {

    string napis = "";
    Zmienna *w = listaZmiennych;

    while (T[i] != ' ' && i < n) {
        napis += T[i];
        i++;
    }

    while (w) {
        if(w->nazwa == napis) {
            f = true;
            val = w->wartosc;
            w = nullptr;
            break;
        }
        w = w->next;
    }
    if (napis == "sin" || napis == "cos") {
        wynik = obliczSinCos(napis);
        f = false;
        t = true;
    }
    if (!f) {
        if (napis == "sin" || napis == "cos") {
        }
        else
            cout << "Zmienna " << napis << " nie istnieje!" << endl;
    }
    else
        cout << "Zmienna " << napis << " istnieje!" << endl;

}
/**
 * \brief Funkcja sprawdza, czy zawarty w wyrazeniu ciąg znaków jest operatorem sinus lub cosinus
 *
 * Definicja funkcji, która określa, czy dany ciąg znaków jest operatorem sinus lub cosinus.
 * \param &f flaga, która informuje, czy badany ciąg znaków w wyrażeniu jest sinusem lub cosinusem
 * \param &name zmienna, która przechowuje wartość znalezionego operatora (sin lub cos)
 * \param T[] talica, która przechowuje kolejne znaki wyrazenia
 * \param n rozmiar tablicy
 * \param i nr pierwszego wyrazu ciagu
 */
void czySinCos(bool &f, string &name, char T[], int n, int i) {
    string napis = "";
    while (T[i] >= 97 && T[i] <= 122 && i < n) {
        napis += T[i];
        i++;
    }
    if (napis == "sin" || napis == "cos") {
        name = napis;
        f = true;
    }
    else
        f = false;
}
/**
 * \brief Funkcja obliczająca funkcje trygonometryczną
 *
 * Definicja funkcji, która oblicza sinus lub cosinus wartości.
 * \param name nazwa funkcji trygonometrycznej
 */
double obliczSinCos(string name) {
    double p;
    if (name == "sin") {

        if (stos) {
            p = sin(stos->x);
            usunElementZeStosu(stos);
            dodajElement(stos, p);
        }
    }
    else if (name == "cos") {
        if (stos) {
            p = cos(stos->x);
            usunElementZeStosu(stos);
            dodajElement(stos, p);
        }
    }
    return p;
}
/**
 * \brief Funkcja dodająca zmienne
 *
 * Definicja funkcji, która umożliwia dodawanie nowych zmiennych.
 * \param name nazwa nowej zmienej
 * \param value wartosc liczbowa nowej zmiennej
 * \param &c flaga, która informuje, czy zmienna o podanej nazwie już istnieje
 */
void dodajZmienna(string name,double value, bool &c) {
    string k;
    bool b = false;
    Zmienna *w = nullptr;
    Zmienna *nowa = nullptr;
    if (!listaZmiennych) {
        listaZmiennych = new Zmienna;
        listaZmiennych->nazwa = name;
        listaZmiennych->wartosc = value;
        listaZmiennych->next = nullptr;
    }
    else {
        w = listaZmiennych;
        while (w) {
            if (w->nazwa == name) {
                b = true;
                w = nullptr;
                cout << "Blad! Zmienna o takiej nazwie juz istnieje." << endl;
                c = 0;
                cout << "Kliknij dowolny klawisz i nastepnie ENTER aby wrocic do poprzedniego menu.";
                cin >> k;

                break;
            }
            w = w->next;
        }

        if (!b) {
            nowa = new Zmienna;
            nowa->nazwa = name;
            nowa->wartosc = value;
            nowa->next = listaZmiennych;
            listaZmiennych = nowa;
        }
    }
}
/**
 * \brief Funkcja edytująca zmienne
 *
 * Definicja funkcji, która edytuje wybraną zmienną.
 * \param i nr zmiennej
 */
void edytujZmienna(int j) {
    Zmienna *w = nullptr;
    Zmienna *tmp = listaZmiennych;
    string y, nowaNazwa, staraNazwa;
    char a, k;
    int counter = 0, n = 0;
    bool correct = true, ok = false;
    double x;
    string liczba = "";
    system("cls");
    for (int i = 0; i < j-1; i++) {
        if (!tmp)
            break;
        tmp = tmp->next;
    }
    if (!tmp) {
        cout << "Zmienna o podanym numerze nie istnieje." << endl;
    }
    else {
        staraNazwa = tmp->nazwa;
        do {
            cout << "Co chcesz edytowac:" << endl
                 << "1. Nazwe"<< endl
                 << "2. Wartosc" << endl
                 << "3. Nic" << endl;
            if (a != '1' && a != '2' && a != '3' && counter > 0)
                cout << "Wprowadzona wartosc jest niepoprawna. ";
            cout << "Prosze wprowadzic liczbe od 1 do 3." << endl;
            cin >> y;
            a = y[0];
            counter++;
            system("cls");
        } while (a != '1' && a != '2' && a != '3');
        counter = 0;
        switch (a) {
        case '1':
            cout << "Aktualna nazwa: " << tmp->nazwa << endl;
            cout << "Wprowadz nowa nazwe: ";
            cin >> nowaNazwa;
            do {

                w = listaZmiennych;
                do {
                    while (!((nowaNazwa[0] >= 65 && nowaNazwa[0] <= 90) || (nowaNazwa[0] >= 97 && nowaNazwa[0] <= 122)) || nowaNazwa == "cos" || nowaNazwa == "sin" || correct == false) {
                        correct = true;
                        cout << "Wprowadz nazwe zmiennej (musi zaczynac sie litera): ";
                        cin >> nowaNazwa;
                        if (nowaNazwa == "sin") {
                            cout << "Blad! Nazwa 'sin' jest zarezerwowana dla funkcji sinus." << endl;
                            correct = false;
                            break;
                        }

                        if (nowaNazwa == "cos") {
                            cout << "Blad! Nazwa 'cos' jest zarezerwowana dla funkcji cosinus." << endl;
                            correct = false;
                            break;
                        }
                        if(!((nowaNazwa[0] >= 65 && nowaNazwa[0] <= 90) || (nowaNazwa[0] >= 97 && nowaNazwa[0] <= 122)))
                            cout << "Blad! Zmienna musi sie zaczynac litera." << endl;
                        for (int i = 0; i < nowaNazwa.length(); i++){
                            if(!((nowaNazwa[i] >= 48 && nowaNazwa[i] <= 57) || (nowaNazwa[i] >= 65 && nowaNazwa[i] <= 90) || (nowaNazwa[i] >= 97 && nowaNazwa[i] <= 122) || nowaNazwa[i] == '_')) {
                                cout << "Blad! Prosze nie uzywac znakow specjalnych do tworzenia nazw zmiennych. Jedyny dopuszczalny znak poza literami i liczbami to: '_'." << endl;
                                correct = false;
                                break;
                            }
                        }
                    }
                } while (!correct);

                while (w) {
                    if (w->nazwa == nowaNazwa) {
                        //b = true;
                        w = nullptr;
                        cout << "Blad! Zmienna o takiej nazwie juz istnieje." << endl;
                        //c = 0;
                        correct = false;
                        break;
                    }
                    w = w->next;
                }
            } while (!correct);
            tmp->nazwa = nowaNazwa;
            cout << "Zmienna " << staraNazwa << " ma nowa nazwe: " << nowaNazwa << " | " << nowaNazwa << " = " <<  tmp->wartosc << endl;
            tmp = nullptr;
            w = nullptr;
            do {
                cout << "Wcisnij 'T' i  ENTER, aby wrocic do menu" << endl;
                cin >> k;
            } while (!(k == 'T' || k == 't'));
            break;
        case '2':
            while (!ok) {
                cout << "Wprowadz wartosc zmiennej (to musi byc liczba): ";
                cin >> liczba;
                n = liczba.length();
                for (int j = 0; j < n; j++) {
                    if(!(liczba[j] >= 48 && liczba[j] <= 57)) {
                        if(liczba[j] == 46 || liczba[j] == 44) {
                            counter++;
                            if (counter > 1) {
                                cout << "Bledny zapis! Za duzo przecinkow lub/i kropek." << endl;
                                ok = 0;
                                counter = 0;
                                break;
                            }
                        }
                        else if (liczba[j] == '-') {
                            if (j > 0) {
                                cout << "Blad! Minus moze byc tylko na poczatku liczby." << endl;
                                ok = 0;
                                break;
                            }
                        }
                        else {
                            cout << "Blad! Podane wyrazenie nie jest liczba." << endl;
                                    ok = 0;
                                    break;
                        }
                    }
                    else
                        ok = 1;
                }
            }
            if (ok) {
                x = zamienStringNaDouble(liczba);
                tmp->wartosc = x;
                cout << "Zmienna: " << tmp->nazwa << " = " << x << endl;
            }

            tmp = nullptr;
            do {
                cout << "Wcisnij 'T' i  ENTER, aby wrocic do menu" << endl;
                cin >> k;
            } while (!(k == 'T' || k == 't'));
            break;
        case '3':
            break;
        }
    }
}
