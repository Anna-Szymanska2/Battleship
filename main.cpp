#include <iostream>
#include <windows.h>
#include <cstdlib>
//#include "Plansza.h"
#include "GraczKomputer.h"
#include "GraczCzlowiek.h"

using namespace std;

int main()
{

//    Plansza plansza;
//    plansza.pola_planszy[0][2].ustawCzyZostaloTrafione(1);
//    plansza.pola_planszy[4][7].ustawCzyZawieraStatek(1);
//    plansza.pola_planszy[4][7].ustawCzyZostaloTrafione(1);
//    plansza.pola_planszy[4][7].ustawCzyJestZaznaczone(1);
//    plansza.pola_planszy[4][8].ustawCzyZawieraStatek(1);
//    plansza.pola_planszy[4][8].ustawCzyZostaloTrafione(1);
//    plansza.pola_planszy[4][6].ustawCzyJestZaznaczone(1);
//    plansza.pola_planszy[4][9].ustawCzyJestZaznaczone(1);
//    plansza.pola_planszy[4][9].ustawCzyZostaloTrafione(1);
//    plansza.pola_planszy[4][9].ustawCzyZawieraStatek(1);
//    plansza.wyswietlZawartoscPlanszy();

//    Plansza plansza1;
//    plansza1.ulozStatekNaPlanszy(plansza1.pieciomasztowiec, 5, 1, 2);
//    plansza1.ulozStatekNaPlanszy(plansza1.czteromasztowiec, 5, 1, 2);


//    plansza1.wyswietlZawartoscPlanszy();
    GraczKomputer mpk1;
    cout << mpk1.zwrocNazwe() << endl;
    mpk1.ustawStatki();
    mpk1.wyswietlPlansze();
    mpk1.wyczyscPlanszePoUstawieniuStatkow();
    Gracz *przeciwnik = &mpk1;
    GraczCzlowiek cz1;
    while(!cz1.zwrocCzyWygral())
    {
        cz1.oddajStrzal(przeciwnik);
    }



    //cz1.ustawStatki();


////    cout << cz1.zwrocNazwe() << endl;
//    mpk1.zwrocNazwe();

    HANDLE standardowy_uchwyt_wyjscia;
    standardowy_uchwyt_wyjscia = GetStdHandle(STD_OUTPUT_HANDLE);
//    cout << "Hello World!" << endl;
//   SetConsoleTextAttribute(standardowy_uchwyt_wyjscia,7);
//    cout << "   A B C D E F G H I J" << endl;
//    cout << " 1 - - # - # - - - - -" << endl;
//    cout << " 2 - - - - # - - - - -" << endl;
//    cout << " 3 - - - - - - - - - -" << endl;
//    cout << " 4 - - - - - - # # # #" << endl;
//    cout << " 5 - - - - - - # X X #" << endl;
//    cout << " 6 - - - - - - # # # #" << endl;
//    cout << " 7 - - - - - - - - - -" << endl;
//    cout << " 8 - - - - - - - - - -" << endl;
//    cout << " 9 - - - - - - - - - -" << endl;
//    cout << "10 - - - - - - - - - -" << endl;

//   // system("cls");
//    cout << "Ekran wyczyszony" << endl;



    return 0;
}
