#include <iostream>
#include <fstream>
#include <vector>
#include "include/sprzet.h"

void menuKlienci() {
    int wybor;
    while (true) {
        cout << "MENU KLIENCI:\n";
        cout << "1. Wyswietl liste klientow\n";
        cout << "2. Dodaj nowego klienta\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
            case 2:
                cout << "Opcja jeszcze niezaimplementowana.\n";
                break;
            case 0:
                return;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                break;
        }
    }
}