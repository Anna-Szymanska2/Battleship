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


};

void wylosujLiczbyDoUlozeniaStatku(int &kolumna, int &wiersz, int &kierunek);
