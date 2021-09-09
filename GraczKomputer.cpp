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


void GraczKomputer::ustawStatki()
{
    int wylosowana_kolumna = 0;
    int wylosowany_wiersz = 0;
    int wylosowany_kierunek = 1;

    for(int i = 5; i>0; i--)
    {
        while(true)
        {
           wylosujLiczbyDoUlozeniaStatku(wylosowana_kolumna,wylosowany_wiersz,wylosowany_kierunek);
           try
           {
               plansza.ulozStatkiNaPlanszy(wylosowany_wiersz,wylosowana_kolumna,wylosowany_kierunek,i,1);
               break;
           }
           catch (out_of_range)
           {

           }
        }

        if(i!=5 && i!=4)
        {
            while(true)
            {
               wylosujLiczbyDoUlozeniaStatku(wylosowana_kolumna,wylosowany_wiersz,wylosowany_kierunek);
               try
               {
                   plansza.ulozStatkiNaPlanszy(wylosowany_wiersz,wylosowana_kolumna,wylosowany_kierunek,i,2);
                   break;
               }
               catch (out_of_range)
               {

               }
            }
        }

    }

}




GraczKomputer::~GraczKomputer(){}
