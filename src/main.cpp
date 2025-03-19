#include <iostream>
#include "include/sprzet.h"

using namespace std;

int main() {
    int wybor;
    do {
        cout << "MENU:\n";
        cout << "1. Start\n";
        cout << "2. Opcje\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                menuStart();
                break;
            case 2:
                cout << "Opcje niezaimplementowane.\n";
                break;
            case 0:
                cout << "zly przycisk, wylaczenie programu.\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
        }
    } while (wybor != 0);

    return 0;
}