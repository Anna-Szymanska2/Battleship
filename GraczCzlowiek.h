#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"

using namespace std;

class GraczCzlowiek: public Gracz
{
public:
    GraczCzlowiek(string nazwa_gracza);
    ~GraczCzlowiek();
    void ustawStatki();
    void wyswietlInfoWstepnePrzyUstawianiuStatkow();
    void wyswietlInfoKoncowePoUstawieniuStatkow();
    void oddajStrzal(Gracz *przeciwnik);
    void odznaczPola(Gracz *przeciwnik);
    void wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik);


};
void spytajUzytkownikaCzyChceOdznaczycPole(char &odp, int &odp_po_konwersji_na_liczbe);
void pobierzOdGraczaLitere(int &wybrana_kolumna);
void pobierzOdGraczaLiczbeWiersz(int &wybrany_wiersz);
void pobierzOdGraczaLiczbeKierunek(int &wybrany_kierunek);

