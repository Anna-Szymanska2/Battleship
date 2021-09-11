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
    p_polozenie.push_back(pole);
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
        if(pole == p_polozenie[i])
            return true;
    }
    return false;
}
Statek& Statek:: operator++()
{
    p_ile_razy_zostal_trafiony++;
    return *this;
}

