#include <iostream>
#include <fstream>
#include <vector>
#include "include/magazyn.h"
#include "include/menu.h"
#include "include/klienci.h"

void menuOpcje() {
    int wybor;
    while (true) {
        cout << "OPCJE:\n";
        cout << "1. Zapisz\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                break;
            case 0:
                return;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                break;
        }
    }
}

void menuStart(const vector<Sprzet>& magazyn) {
    int wybor;
    while (true) {
        cout << "START:\n";
        cout << "1. Klienci\n";
        cout << "2. Magazyn\n";
        cout << "3. Opcje\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                menuKlienci();
                break;
            case 2:
                menuMagazyn(magazyn);
                break;
            case 3:
                menuOpcje();
                break;
            case 0:
                return;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                break;
        }
    }
}