#pragma once

#include <string>
#include <iostream>
#include "Statek.h"

using namespace std;

class Plansza
{

 //zmienic pozniej
    vector<vector<Pole>> p_pola_planszy;
    vector<pair<int,int>> p_zajete_miejsca;
    Statek p_pieciomasztowiec;
    Statek p_czteromasztowiec;
    Statek p_trojmasztowiec1;
    Statek p_trojmasztowiec2;
    Statek p_dwumasztowiec1;
    Statek p_dwumasztowiec2;
    Statek p_jednomasztowiec1;
    Statek p_jednomasztowiec2;

public:
    Plansza();
    void wyswietlZawartoscPlanszy();
    void ulozStatekNaPlanszy(Statek &statek, int wiersz, int kolumna, int kierunek);
    void ulozStatkiNaPlanszy(int wiersz, int kolumna, int kierunek, int typ, int numer);
    void ustawStatek(Statek &statek,int typ, int numer);
    Statek zwrocStatek(int typ, int numer);
    void wyczyscPlanszePoUstawieniuStatkow();
    Pole* zwrocWskaznikNaPoleODanymWierszuKolumnie(int wiersz, int kolumna);
    bool czyWybranePoleByloWczesniejTrafione(int wiersz, int kolumna);
    void ustawCzyPoleZostaloTrafione (bool czy_zostalo_trafione, int wiersz, int kolumna);
    bool zwrocCzyPoleZawieraStatek(int wiersz, int kolumna);
    Statek* zwrocStatekDoKtoregoNalezyDanePole(Pole *pole);

};



