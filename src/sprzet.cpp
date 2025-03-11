#include "include/sprzet.h"
#include <iostream>
#include <fstream>

vector<Sprzet> wczytajBaze(const string& nazwaPliku) {
    vector<Sprzet> magazyn;
    ifstream plik(nazwaPliku);
    if (!plik) {
        cerr << "Nie można otworzyć pliku!" << endl;
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

void wyswietlSprzet(const vector<Sprzet>& magazyn, size_t indeks) {
    if (indeks < magazyn.size()) {
        cout << "Sprzęt nr " << indeks + 1 << ":\n";
        for (const string& linia : magazyn[indeks].dane) {
            cout << linia << endl;
        }
    } else {
        cout << "Nie ma takiego sprzętu w bazie!" << endl;
    }
}