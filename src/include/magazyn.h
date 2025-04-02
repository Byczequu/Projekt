#ifndef FF0402FD_DC09_4728_86BF_BFAD1A2887B9
#define FF0402FD_DC09_4728_86BF_BFAD1A2887B9

#include <iostream>
#include <vector>
#include <string>
#include "sprzet.h"
using namespace std;    

void menuMagazyn(const vector<Sprzet>& magazyn);
vector<Sprzet> wczytajBaze(const string& nazwaPliku);
void wyswietlSprzet(const vector<Sprzet>& magazyn);

#endif /* FF0402FD_DC09_4728_86BF_BFAD1A2887B9 */
