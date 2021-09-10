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

};

void pobierzOdGraczaLitere(int odpowiedz_liczba_po_konwersji, char odpowiedz, int &wybrana_kolumna);
void pobierzOdGraczaLiczbeWiersz(int &wybrany_wiersz, int odpowiedz_liczba);
void pobierzOdGraczaLiczbeKierunek(int &wybrany_kierunek, int odpowiedz_liczba);
