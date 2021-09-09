#include <iostream>
#include "Statek.h"
#include <string>


using namespace std;

Statek::Statek()
{
    p_czy_jest_trafiony = false;
    p_czy_jest_zatopiony = false;
}

Statek::Statek(int dlugosc_statku)
{
    p_czy_jest_trafiony = false;
    p_czy_jest_zatopiony = false;
    p_dlugosc_statku = dlugosc_statku;
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
