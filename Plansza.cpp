#include <iostream>
#include "Plansza.h"
#include <string>
#include <exception>


using namespace std;

Plansza::Plansza()
{
    for (int i = 0; i < 10; i++)
    {
        pola_planszy.push_back(vector<Pole>());

        for(int j = 0; j < 10; j++)
        {
            pola_planszy[i].push_back(Pole());
        }

    }

    pieciomasztowiec.ustawDlugoscStatku(5);
    czteromasztowiec.ustawDlugoscStatku(4);
    trojmasztowiec1.ustawDlugoscStatku(3);
    trojmasztowiec2.ustawDlugoscStatku(3);
    dwumasztowiec1.ustawDlugoscStatku(2);
    dwumasztowiec2.ustawDlugoscStatku(2);
    jednomasztowiec1.ustawDlugoscStatku(1);
    jednomasztowiec2.ustawDlugoscStatku(1);

}

void Plansza::wyswietlZawartoscPlanszy()
{
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(i == 9)
            cout << i + 1 << " ";
        else
            cout << " " << i + 1 << " ";

        for(int j = 0; j < 10; j++)
        {
            pola_planszy[i][j].wyswietlPole();
            cout << " ";
        }
        cout << endl;

    }

}

void Plansza::ulozStatekNaPlanszy(Statek &statek, int wiersz, int kolumna, int kierunek)
{
    int dlugosc_statku = statek.zwrocDlugoscStatku();
    switch(kierunek)
    {
    case 1:
        if(wiersz + 1 >= dlugosc_statku)
        {
            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz-i][kolumna]));
            }

        }
        else
            throw out_of_range("Dany statek nie miesci sie na planszy");
        break;

    case 2:
        if(9-kolumna+1 >= dlugosc_statku)
        {
            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz][kolumna+i]));
//                pair<int, int> zajete_miejsce;
//                zajete_miejsce.first = wiersz;
//                zajete_miejsce.second = kolumna+i;
//                zajete_miejsca.push_back(zajete_miejsce);
            }
        }
        else
            throw out_of_range("Dany statek nie miesci sie na planszy");
        break;

    case 3:
        if(9-wiersz+1 >= dlugosc_statku)
        {
            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz+i][kolumna]));
            }
        }
        else
            throw out_of_range("Dany statek nie miesci sie na planszy");
        break;

    case 4:
        if(kolumna + 1 >= dlugosc_statku)
        {
            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz][kolumna-i]));
            }
        }
        else
            throw out_of_range("Dany statek nie miesci sie na planszy");
        break;


    }


}
