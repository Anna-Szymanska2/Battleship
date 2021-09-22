#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"

using namespace std;

class GraczKomputer: public Gracz
{
//public: // zmienic po testach
    vector<tuple<int,int, Pole*>> p_mozliwe_pola_ze_statkami;
public:
    GraczKomputer();
    ~GraczKomputer();
    void ustawStatki();
    void oddajStrzal(Gracz *przeciwnik);
    void odznaczPola(Gracz *przeciwnik, Statek* zatopiony_statek);
    void wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik);
    void ustawMozliwePolaZeStatkami(Gracz *przeciwnik);

};

void wylosujLiczbyDoUlozeniaStatku(int &kolumna, int &wiersz, int &kierunek);

