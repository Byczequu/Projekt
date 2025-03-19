#ifndef B52A049F_66FC_46FB_8D9F_9FEA665BBC28
#define B52A049F_66FC_46FB_8D9F_9FEA665BBC28

#include <vector>
#include <string>
using namespace std;


class Sprzet {
public:
    vector<string> dane; 
};

void menuStart();
void menuKlienci();
void menuMagazyn();

vector<Sprzet> wczytajBaze(const string& nazwaPliku);
void wyswietlSprzet(const vector<Sprzet>& magazyn, size_t indeks);

#endif /* B52A049F_66FC_46FB_8D9F_9FEA665BBC28 */