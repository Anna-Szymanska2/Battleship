#pragma once

#include <string>
#include <iostream>
#include "Statek.h"

using namespace std;

class Plansza
{

public: //zmienic pozniej
    vector<vector<Pole>> pola_planszy;
    vector<pair<int,int>> zajete_miejsca;
    Statek pieciomasztowiec;
    Statek czteromasztowiec;
    Statek trojmasztowiec1;
    Statek trojmasztowiec2;
    Statek dwumasztowiec1;
    Statek dwumasztowiec2;
    Statek jednomasztowiec1;
    Statek jednomasztowiec2;


    Plansza();
    void wyswietlZawartoscPlanszy();
    void ulozStatekNaPlanszy(Statek &statek, int wiersz, int kolumna, int kierunek);
    void ulozStatkiNaPlanszy(int wiersz, int kolumna, int kierunek, int typ, int numer);
    void ustawStatek(Statek &statek,int typ, int numer);
    Statek zwrocStatek(int typ, int numer);
};



