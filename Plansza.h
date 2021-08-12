#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "Pole.h"

using namespace std;

class Plansza
{

public: //zmienic pozniej
    vector<vector<Pole>> pola_planszy;

    Plansza();
    void wyswietlZawartoscPlanszy();
};


