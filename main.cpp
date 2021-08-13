#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "Plansza.h"

using namespace std;

int main()
{
    Plansza plansza;
    plansza.pola_planszy[0][2].ustawCzyZostaloTrafione(1);
    plansza.pola_planszy[4][7].ustawCzyZawieraStatek(1);
    plansza.pola_planszy[4][7].ustawCzyZostaloTrafione(1);
    plansza.pola_planszy[4][7].ustawCzyJestZaznoczone(1);
    plansza.pola_planszy[4][8].ustawCzyZawieraStatek(1);
    plansza.pola_planszy[4][8].ustawCzyZostaloTrafione(1);
    plansza.pola_planszy[4][6].ustawCzyJestZaznoczone(1);
    plansza.pola_planszy[4][9].ustawCzyJestZaznoczone(1);
    plansza.pola_planszy[4][9].ustawCzyZostaloTrafione(1);
    plansza.pola_planszy[4][9].ustawCzyZawieraStatek(1);
   // plansza.wyswietlZawartoscPlanszy();

    Plansza plansza1;
    plansza1.ulozStatekNaPlanszy(plansza1.pieciomasztowiec, 0, 0, 2);
    plansza1.ulozStatekNaPlanszy(plansza1.czteromasztowiec, 6, 3, 4);
    plansza1.wyswietlZawartoscPlanszy();

    HANDLE standardowy_uchwyt_wyjscia;
    standardowy_uchwyt_wyjscia = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Hello World!" << endl;
   SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,7);
    cout << "   A B C D E F G H I J" << endl;
    cout << " 1 - - # - # - - - - -" << endl;
    cout << " 2 - - - - # - - - - -" << endl;
    cout << " 3 - - - - - - - - - -" << endl;
    cout << " 4 - - - - - - # # # #" << endl;
    cout << " 5 - - - - - - # X X #" << endl;
    cout << " 6 - - - - - - # # # #" << endl;
    cout << " 7 - - - - - - - - - -" << endl;
    cout << " 8 - - - - - - - - - -" << endl;
    cout << " 9 - - - - - - - - - -" << endl;
    cout << "10 - - - - - - - - - -" << endl;



    return 0;
}
