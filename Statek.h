#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Pole.h"

using namespace std;

class Statek
{
    int p_dlugosc_statku;
    vector<Pole*> p_polozenie;
    bool p_czy_jest_trafiony;
    bool p_czy_jest_zatopiony;
    int p_ile_razy_zostal_trafiony;

public:
    Statek();
    Statek(int dlugosc_statku);
  //  ~Statek();
    void ustawCzyJestTrafiony(bool czy_jest_trafiony);
    void ustawCzyJestZatopiony(bool czy_jest_zatopiony);
    void ustawDlugoscStatku(int dlugosc_statku);
    int zwrocDlugoscStatku();
    bool zwrocCzyStatekJestZatopiony();
    int zwrocIleRazyTrafionoStatek();
    void dodajPoleStatku(Pole* pole);
    bool sprawdzCzyDanePoleJestCzesciaStatku(Pole *pole);
    Statek& operator++();

};
