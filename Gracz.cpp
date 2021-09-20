#include <iostream>
#include "Gracz.h"
#include <string>

using namespace std;


Gracz::Gracz()
{
    p_czy_wygral = false;
    p_liczba_zatopionych_statkow = 0;
}

Gracz:: ~Gracz(){}

bool Gracz::zwrocCzyWygral()
{
    return p_czy_wygral;
}

int Gracz::zwrocLiczbeZatopionychStatkow()
{
    return p_liczba_zatopionych_statkow;
}
void Gracz::ustawCzyGraczWygral(bool czy_wygral)
{
    p_czy_wygral = czy_wygral;
}

std::string Gracz::zwrocNazwe()
{
    return p_nazwa;
}

void Gracz::wyswietlPlansze()
{
    p_plansza.wyswietlZawartoscPlanszy();
}

void Gracz::wyswietlPlanszeNaKoniecGry()
{
    p_plansza.wyswietlZawartoscPlanszyPodKoniecGry();
}

void Gracz::wyczyscPlanszePoUstawieniuStatkow()
{
   p_plansza.wyczyscPlanszePoUstawieniuStatkow();
}

bool Gracz::czyWybranePoleByloWczesniejTrafione(int wiersz, int kolumna)
{
    return p_plansza.czyWybranePoleByloWczesniejTrafione(wiersz,kolumna);
}

void Gracz::ustawCzyPolePlanszyZostaloTrafione (bool czy_zostalo_trafione, int wiersz, int kolumna)
{
    p_plansza.ustawCzyPoleZostaloTrafione(czy_zostalo_trafione,wiersz,kolumna);
}

bool Gracz::zwrocCzyPolePlanszyZawieraStatek(int wiersz, int kolumna)
{
    return p_plansza.zwrocCzyPoleZawieraStatek(wiersz,kolumna);
}

Pole* Gracz::zwrocWskaznikNaPolePlanszyODanymWierszuKolumnie(int wiersz, int kolumna)
{
    return p_plansza.zwrocWskaznikNaPoleODanymWierszuKolumnie(wiersz,kolumna);
}

Statek* Gracz::zwrocStatekDoKtoregoNalezyDanePole(Pole *pole)
{
    return p_plansza.zwrocStatekDoKtoregoNalezyDanePole(pole);
}

Gracz& Gracz::operator++()
{
    p_liczba_zatopionych_statkow++;
    return *this;
}



