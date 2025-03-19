#include "include/sprzet.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

vector<Sprzet> wczytajBaze(const string& nazwaPliku) {
    vector<Sprzet> magazyn;
    ifstream plik(nazwaPliku);
    if (!plik) {
        cerr << "Nie mozna otworzyc pliku!" << endl;
        return magazyn;
    }

    string linia;
    Sprzet aktualny;
    while (getline(plik, linia)) {
        if (linia == "*") {
            magazyn.push_back(aktualny);
            aktualny.dane.clear();
        } else {
            aktualny.dane.push_back(linia);
        }
    }
    if (!aktualny.dane.empty()) {
        magazyn.push_back(aktualny);
    }

    plik.close(); // Jawne zamknięcie pliku
    return magazyn;
}

void wyswietlSprzet(const vector<Sprzet>& magazyn) {
    if (magazyn.empty()) {
        cout << "Magazyn jest pusty!" << endl;
        return;
    }

    for (size_t i = 0; i < magazyn.size(); ++i) {
        cout << "Sprzet nr " << i + 1 << ":\n";
        for (const string& linia : magazyn[i].dane) {
            cout << linia << endl;
        }
        cout << "-------------------" << endl;
    }
}

void menuKlienci() {
    int wybor;
    do {
        cout << "MENU KLIENCI:\n";
        cout << "1. Wyswietl liste klientow\n";
        cout << "2. Dodaj nowego klienta\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        while (!(cin >> wybor)) {
            cin.clear(); // Czyszczenie błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie nieprawidłowego wejścia
            cout << "Nieprawidlowy wybor. Sprobuj ponownie: ";
        }

        switch (wybor) {
            case 1:
                cout << "Lista klientow nie jest jeszcze zaimplementowana.\n";
                break;
            case 2:
                cout << "Dodawanie klienta nie jest jeszcze zaimplementowane.\n";
                break;
            case 0:
                cout << "Powrot do menu START.\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
        }
    } while (wybor != 0);
}

void menuMagazyn() {
    int wybor;
    do {
        cout << "MAGAZYN:\n";
        cout << "1. Wyswietl zawartosc magazynu\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        while (!(cin >> wybor)) {
            cin.clear(); // Czyszczenie błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie nieprawidłowego wejścia
            cout << "Nieprawidlowy wybor. Sprobuj ponownie: ";
        }

        switch (wybor) {
            case 1: {
                vector<Sprzet> magazyn = wczytajBaze("magazyn.txt");
                wyswietlSprzet(magazyn);
                break;
            }
            case 0:
                cout << "Powrot do menu START.\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
        }
    } while (wybor != 0);
}

void menuStart() {
    int wybor;
    do {
        cout << "START:\n";
        cout << "1. Klienci\n";
        cout << "2. Magazyn\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        while (!(cin >> wybor)) {
            cin.clear(); // Czyszczenie błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie nieprawidłowego wejścia
            cout << "Nieprawidlowy wybor. Sprobuj ponownie: ";
        }

        switch (wybor) {
            case 1:
                menuKlienci();
                break;
            case 2:
                menuMagazyn();
                break;
            case 0:
                cout << "Powrot do menu glownego.\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
        }
    } while (wybor != 0);
}