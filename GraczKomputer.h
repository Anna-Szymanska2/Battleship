#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"
#include <vector>

using namespace std;

class GraczKomputer: public Gracz
{
//public: // zmienic po testach
    vector<tuple<int,int, Pole*>> p_mozliwe_pola_ze_statkami;
    vector<tuple<int,int, Pole*>> p_pola_zatapianego_statku;
public:
    GraczKomputer();
    ~GraczKomputer();
    void ustawStatki();
    void oddajStrzal(Gracz *przeciwnik);
    void odznaczPola(Gracz *przeciwnik, Statek* zatopiony_statek);
    void wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik);
    void ustawMozliwePolaZeStatkami(Gracz *przeciwnik);
    void dodajPoleZatapianegoStatku(int wiersz, int kolumna, Pole *pole);


};

void wylosujLiczbyDoUlozeniaStatku(int &kolumna, int &wiersz, int &kierunek);
bool predykatSortujacyPolaZatapianegoStatku(tuple<int,int,Pole*> t1,tuple<int,int,Pole*> t2);


