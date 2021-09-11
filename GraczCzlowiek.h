#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"

using namespace std;

class GraczCzlowiek: public Gracz
{
public:
    GraczCzlowiek();
    ~GraczCzlowiek();
    void ustawStatki();
    void wyswietlInfoWstepnePrzyUstawianiuStatkow();
    void wyswietlInfoKoncowePoUstawieniuStatkow();
    void oddajStrzal(Gracz *przeciwnik);

};

void pobierzOdGraczaLitere(int &wybrana_kolumna);
void pobierzOdGraczaLiczbeWiersz(int &wybrany_wiersz);
void pobierzOdGraczaLiczbeKierunek(int &wybrany_kierunek);
void wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik);
