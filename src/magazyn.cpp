#include <iostream>
#include <fstream>
#include <vector>
#include "include/magazyn.h"
#include "include/menu.h"
#include "include/klienci.h"
#include "include/sprzet.h"

using namespace std;

vector<Sprzet> wczytajBaze(const string& Baza_danych) {
    vector<Sprzet> magazyn;
    ifstream plik(Baza_danych);
    if (!plik) {
        cout << "Nie mozna otworzyc pliku!" << endl;
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

    return magazyn;
}

void wyswietlSprzet(const vector<Sprzet>& magazyn) {
    if (magazyn.empty()) {
        cout << "Magazyn jest pusty!" << endl;
        return;
    }

    for (int i = 0; i < magazyn.size(); i++) {
        cout << "Sprzet nr " << i + 1 << "\n";
        for (int j = 0; j < magazyn[i].dane.size(); j++) {
            cout << magazyn[i].dane[j] << endl;
        }    
        cout << "-------------------" << endl;
    }
}

void menuMagazyn(const vector<Sprzet>& magazyn) {
    int wybor;
    while (true) {
        cout << "MAGAZYN:\n";
        cout << "1. Wyswietl zawartosc magazynu\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                wyswietlSprzet(magazyn);
                break;
            case 0:
                return;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                break;
        }
    }
