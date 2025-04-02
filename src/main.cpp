#include <iostream>
#include <fstream>
#include <vector>
#include "include/magazyn.h"
#include "include/menu.h"
#include "include/klienci.h"
#include "include/sprzet.h"

using namespace std;

int main() {
    vector<Sprzet> magazyn = wczytajBaze("magazyn.txt");
    menuStart(magazyn);
    return 0;
}