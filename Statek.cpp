#include <iostream>
#include "Statek.h"
#include <string>


using namespace std;

Statek::Statek()
{
    p_czy_jest_trafiony = false;
    p_czy_jest_zatopiony = false;
    p_ile_razy_zostal_trafiony = 0;
}

Statek::Statek(int dlugosc_statku)
{
    p_czy_jest_trafiony = false;
    p_czy_jest_zatopiony = false;
    p_dlugosc_statku = dlugosc_statku;
    p_ile_razy_zostal_trafiony = 0;
}

void Statek::ustawCzyJestTrafiony(bool czy_jest_trafiony)
{
    p_czy_jest_trafiony = czy_jest_trafiony;
}

void Statek::ustawCzyJestZatopiony(bool czy_jest_zatopiony)
{
    p_czy_jest_zatopiony = czy_jest_zatopiony;
}

void Statek::ustawDlugoscStatku(int dlugosc_statku)
{
    p_dlugosc_statku = dlugosc_statku;
}

void Statek::dodajPoleStatku(Pole* pole)
{
    pole->ustawCzyZawieraStatek(1);
    pole->ustawCzyZostaloTrafione(1); //zmienic jak bede miec funkcje strzelajaca
    p_polozenie_statku.push_back(pole);
}

void Statek::zaznaczOkoliceStatku()
{
    for(unsigned int i = 0; i < p_okolice_statku.size(); i++)
    {
        p_okolice_statku[i]->ustawCzyJestZaznaczone(1);
    }
}

unsigned int Statek::zwrocDlugoscWektoraOkoliceStatku()
{
    return p_okolice_statku.size();
}

void Statek::dodajPoleOkolicyStatku(Pole *pole)
{
    pole->ustawCzyJestWOtoczeniuStatku(1);
    pole->ustawCzyJestZaznaczone(1);
    p_okolice_statku.push_back(pole);
}

int Statek::zwrocDlugoscStatku()
{
    return p_dlugosc_statku;
}

bool Statek::zwrocCzyStatekJestZatopiony()
{
    return p_czy_jest_zatopiony;
}

int Statek::zwrocIleRazyTrafionoStatek()
{
    return p_ile_razy_zostal_trafiony;
}
bool Statek::sprawdzCzyDanePoleJestCzesciaStatku(Pole *pole)
{
    for(int i = 0; i< p_dlugosc_statku; i++)
    {
        if(pole == p_polozenie_statku[i])
            return true;
    }
    return false;
}
vector<Pole*> Statek::zwrocWektorOkolicStatku()
{
    return p_okolice_statku;
}
Statek& Statek:: operator++()
{
    p_ile_razy_zostal_trafiony++;
    return *this;
}

Pole* Statek::operator[](unsigned int i)
{
    if(i >= p_okolice_statku.size())
        throw out_of_range("Wektor nie ma elementu o takim indeksie");

    return p_okolice_statku[i];
}

