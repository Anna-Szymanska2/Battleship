#pragma once

#include <string>
#include <iostream>

using namespace std;

class Pole
{
//    struct nazwa_pola
//    {
//        char litera;
//        int liczba;
//    } p_nazwa;
    bool p_czy_zawiera_statek;
    bool p_czy_zostalo_trafione;
   // char p_fragment_interfejsu;
    bool p_czy_jest_zaznaczone;
    bool p_czy_jest_w_otoczeniu_statku;

public:
    Pole();
   // Pole(nazwa_pola nazwa); // (char litera, int liczba)
    ~Pole();
    void ustawCzyZawieraStatek(bool czy_zawiera_statek);
    void ustawCzyZostaloTrafione (bool czy_zostalo_trafione);
    void ustawCzyJestWOtoczeniuStatku(bool czy_jest_w_otoczeniu_statku);
   // void ustawFragmentInterfejsu( char fragment_interfejsu);
    void ustawCzyJestZaznaczone(bool czy_jest_zaznaczone);
    bool zwrocCzyPoleJestWOtoczeniuStatku();
    bool zwrocCzyPoleZawieraStatek();
    bool zwrocCzyPoleJestTrafione();
    void wyswietlPole();

};

