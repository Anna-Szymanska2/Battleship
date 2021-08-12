#include <iostream>
#include "Pole.h"
#include <string>
#include <windows.h>
#include <cstdlib>

using namespace std;

Pole::Pole()
{
    p_czy_zawiera_statek = 0;
    p_czy_zostalo_trafione = 0;
    p_czy_jest_zaznaczone = 0;
}

Pole::~Pole()
{
   // cout << "destruktor ~Pole()" << endl;
}

void Pole:: wyswietlPole()
{
    HANDLE standardowy_uchwyt_wyjscia;
    standardowy_uchwyt_wyjscia = GetStdHandle(STD_OUTPUT_HANDLE);
    if(p_czy_zostalo_trafione)
    {
        if(p_czy_zawiera_statek)
        {
            SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,12); // zamiast 12 zmienna mozna dac?
            cout << "X";
        }
        else
            cout << "#";
        SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,7);
        return;

    }
    if(p_czy_jest_zaznaczone)
    {
        SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,14);
        cout << "#";
        SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,7);
    }
    else
        cout << "-";

}

void Pole::ustawCzyZawieraStatek(bool czy_zawiera_statek)
{
    p_czy_zawiera_statek = czy_zawiera_statek;
}

void Pole::ustawCzyZostaloTrafione (bool czy_zostalo_trafione)
{
    p_czy_zostalo_trafione = czy_zostalo_trafione;
}

void Pole::ustawCzyJestZaznoczone(bool czy_jest_zaznaczone)
{
    p_czy_jest_zaznaczone = czy_jest_zaznaczone;
}
