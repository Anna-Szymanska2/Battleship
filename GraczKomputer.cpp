#include <iostream>
#include "GraczKomputer.h"
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

GraczKomputer::GraczKomputer():Gracz()
{
    srand(time(NULL));
    int wylosowana_liczba = rand()%8;
    switch(wylosowana_liczba)
    {
    case 0:
       nazwa = "Wieslaw";
        break;
    case 1:
        nazwa = "Janusz";
        break;
    case 2:
        nazwa = "Ryszard";
        break;
    case 3:
        nazwa = "Zbigniew";
        break;
    case 4:
        nazwa = "Grazyna";
        break;
    case 5:
        nazwa = "Kunegunda";
        break;
    case 6:
        nazwa = "Marzena";
        break;
    case 7:
        nazwa = "Miroslawa";
        break;
    }

}
void wylosujLiczbyDoUlozeniaStatku(int &kolumna, int &wiersz, int &kierunek)
{
    srand(time(NULL));
    kolumna = rand()%10;
    wiersz = rand()%10;
    kierunek= rand()%4+1;
}

void GraczKomputer::ustawPojedynczyStatek(int &wylosowana_kolumna, int &wylosowany_wiersz, int &wylosowany_kierunek, int dlugosc_statku, int numer)
{
    wylosujLiczbyDoUlozeniaStatku(wylosowana_kolumna,wylosowany_wiersz,wylosowany_kierunek);
    Statek statek(dlugosc_statku);
    try
    {
        plansza.ulozStatekNaPlanszy(statek,wylosowany_wiersz,wylosowana_kolumna,wylosowany_kierunek);
        plansza.ustawStatek(statek,dlugosc_statku,numer);

    }
    catch(out_of_range)
    {
        cout << "Tutaj czasem cos odwala" << endl;
        ustawPojedynczyStatek(wylosowana_kolumna,wylosowany_wiersz,wylosowany_kierunek,dlugosc_statku,numer);

    }

}

void GraczKomputer::ustawStatki()
{
    int wylosowana_kolumna = 0;
    int wylosowany_wiersz = 0;
    int wylosowany_kierunek = 1;

    while(true)
    {
       ustawPojedynczyStatek(wylosowana_kolumna,wylosowany_wiersz,wylosowany_kierunek,5,0);
       break;
    }


}




GraczKomputer::~GraczKomputer(){}
