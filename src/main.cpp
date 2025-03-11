#include "include/sprzet.h"
#include <iostream>
using namespace std;

int main() {
    

    vector<Sprzet> magazyn = wczytajBaze("magazyn.txt");
    
    size_t indeks;
    cout << "Podaj numer sprzętu do wyświetlenia: ";
    cin >> indeks;
    
    wyswietlSprzet(magazyn, indeks - 1);
}