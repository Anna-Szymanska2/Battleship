#pragma once

#include <string>
#include <iostream>
#include "Plansza.h"

using namespace std;

class Gracz
{
protected:
    Plansza plansza;
    string nazwa;
    bool czy_wygral;

public:
    Gracz();
    ~Gracz();

    bool zwrocCzyWygral();
    string zwrocNazwe();
    void wyswietlPlansze();


};
