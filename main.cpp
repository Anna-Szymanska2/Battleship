#include <iostream>
#include <windows.h>
#include <cstdlib>
//#include "Plansza.h"
#include "GraczKomputer.h"
#include "GraczCzlowiek.h"
#include <limits>

using namespace std;

void testowy();
void testowy2();
void interfejsGry(bool &czy_program_trwa);
void zagrajZGraczem();
void zagrajZKomputerem();

int main()
{
    testowy2();
    bool czy_program_trwa = true;

    while(czy_program_trwa)
    {
        interfejsGry(czy_program_trwa);
    }

    return 0;
}

void testowy()
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
        GraczCzlowiek cz1("Ania");
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

}

void interfejsGry(bool &czy_program_trwa)
{
        system("cls");
        cout << "Czesc! Za chwile bedziesz mogl zagrac w gre statki - taka jak na papierze tylko w  wersji komputerowej" << endl;
        cout << "Wybierz tryb gry (nacisnij wybrany klawisz i potwierdz enterem): " << endl;
        cout << "1. Gracz vs Gracz" << endl;
        cout << "2. Gracz vs Komputer" << endl;
        cout << "Inny klawisz - zakoncz" << endl;

        char odp_tryb_gry;
        cin >> odp_tryb_gry;

        switch(odp_tryb_gry)
        {
         case '1':
            zagrajZGraczem();
            break;
         case '2':
            zagrajZKomputerem();
            break;
         default:
            cout << "Dziekuje za uzycie" << endl;
            czy_program_trwa = false;
            getchar();
            break;

        }

}

void zagrajZGraczem()
{
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    string nazwa_gracza1;
    string nazwa_gracza2;
    cout << "Poprosze teraz o podanie jak sie nazywaja obydwaj gracze" << endl;
    cout << "Pierwszy graczu, podaj jak sie nazywasz: " << endl;
    getline(cin,nazwa_gracza1);
    GraczCzlowiek gracz_cz1(nazwa_gracza1);

    do
    {
        cout << "Drugi graczu, podaj jak sie nazywasz: " << endl;
        getline(cin,nazwa_gracza2);

        if(nazwa_gracza2 == nazwa_gracza1)
        {
            cout << "Drugi graczu, nie mozesz sie nazywac tak samo jako pierwszy!" << endl;
            cout << "Dlatego poprosze Cie o podanie swojej nazwy jeszcze raz" << endl;
        }

    }while(nazwa_gracza2 == nazwa_gracza1);

    GraczCzlowiek gracz_cz2(nazwa_gracza2);
    cout << "Teraz bede prosic o ustawienie statkow gracza " << gracz_cz1.zwrocNazwe() << endl;
    cout << "Dlatego gracza " << gracz_cz2.zwrocNazwe() << " prosze o niepatrzenie na ekran podczas trwania tego ustawiania" << endl;
    getchar();
    gracz_cz1.ustawStatki();
    getchar();
    cout << "A teraz bede prosic o ustawienie statkow gracza " << gracz_cz2.zwrocNazwe() << endl;
    cout << "Dlatego gracza " << gracz_cz1.zwrocNazwe() << " prosze o niepatrzenie na ekran podczas trwania tego ustawiania" << endl;
    getchar();
    gracz_cz2.ustawStatki();
    getchar();
    system("cls");
  //  getchar();
    cout << "Statki zostaly ustawione! Mozemy zaczac strzelanie" << endl;
    getchar();
    Gracz *wsk_gracz_cz1 = &gracz_cz1;
    Gracz *wsk_gracz_cz2 = &gracz_cz2;

    while(!gracz_cz1.zwrocCzyWygral() && !gracz_cz2.zwrocCzyWygral())
    {

        gracz_cz1.oddajStrzal(wsk_gracz_cz2);

        if(gracz_cz1.zwrocCzyWygral())
            continue;

        gracz_cz2.oddajStrzal(wsk_gracz_cz1);
    }
    system("cls");
    cout << "A teraz wyswietle plansza wygranego gracza, na ktorej na zielono beda oznaczone pola statkow, ktore nie zostaly jeszcze trafione" << endl;

    if(gracz_cz1.zwrocCzyWygral())
        gracz_cz1.wyswietlPlanszeNaKoniecGry();
    else
        gracz_cz2.wyswietlPlanszeNaKoniecGry();

    getchar();
}

void zagrajZKomputerem()
{

}

void testowy2()
{
    GraczKomputer mpk2;
    GraczKomputer mpk3;
    cout << mpk2.zwrocNazwe() << endl;
    mpk2.ustawStatki();
    mpk2.wyswietlPlansze();
    getchar();
    mpk2.wyczyscPlanszePoUstawieniuStatkow();
    mpk3.ustawMozliwePolaZeStatkami(&mpk2);
    while(mpk2.zwrocLiczbeZatopionychStatkow() != 8)
    {
        mpk3.oddajStrzal(&mpk2);
    }
    getchar();
    getchar();
}
