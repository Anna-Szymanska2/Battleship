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

public:
    Statek();
    Statek(int dlugosc_statku);
  //  ~Statek();
    void ustawCzyJestTrafiony(bool czy_jest_trafiony);
    void ustawCzyJestZatopiony(bool czy_jest_zatopiony);
    void ustawDlugoscStatku(int dlugosc_statku);
    int zwrocDlugoscStatku();
    void dodajPoleStatku(Pole* pole);

};
