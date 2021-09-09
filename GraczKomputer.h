#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"

using namespace std;

class GraczKomputer: public Gracz
{
public:
    GraczKomputer();
    ~GraczKomputer();
    void ustawStatki();
    void ustawPojedynczyStatek(int &wylosowana_kolumna, int &wylosowany_wiersz, int &wylosowany_kierunek, int dlugosc_statku, int numer);


};

void wylosujLiczbyDoUlozeniaStatku(int &kolumna, int &wiersz, int &kierunek);
