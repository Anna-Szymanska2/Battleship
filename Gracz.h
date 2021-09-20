#pragma once

#include <string>
#include <iostream>
#include "Plansza.h"

using namespace std;

class Gracz
{
protected:
    Plansza p_plansza;
    string p_nazwa;
    bool p_czy_wygral;
    int p_liczba_zatopionych_statkow;


 public:
    Gracz();
    virtual ~Gracz();

    bool zwrocCzyWygral();
    void ustawCzyGraczWygral(bool czy_wygral);
    int zwrocLiczbeZatopionychStatkow();
    virtual void ustawStatki() = 0;
    string zwrocNazwe();
    void wyswietlPlansze();
    void wyswietlPlanszeNaKoniecGry();
    void wyczyscPlanszePoUstawieniuStatkow();
    bool czyWybranePoleByloWczesniejTrafione(int wiersz, int kolumna);
    void ustawCzyPolePlanszyZostaloTrafione (bool czy_zostalo_trafione, int wiersz, int kolumna);
    bool zwrocCzyPolePlanszyZawieraStatek(int wiersz, int kolumna);
    Pole* zwrocWskaznikNaPolePlanszyODanymWierszuKolumnie(int wiersz, int kolumna);
    Statek* zwrocStatekDoKtoregoNalezyDanePole(Pole *pole);
    Gracz& operator++();

};
