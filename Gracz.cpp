#include <iostream>
#include "Gracz.h"
#include <string>

using namespace std;

Gracz::Gracz()
{
    czy_wygral = false;
}

Gracz:: ~Gracz(){}

bool Gracz::zwrocCzyWygral()
{
    return czy_wygral;
}

std::string Gracz::zwrocNazwe()
{
    return nazwa;
}

void Gracz::wyswietlPlansze()
{
    plansza.wyswietlZawartoscPlanszy();
}


