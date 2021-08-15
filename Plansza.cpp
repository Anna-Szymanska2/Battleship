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

// w funkjci ktora ja bedzie wywyolywac trzeba sprawdzic czy argumenty miesza sie w przedzia;e 0-9

void Plansza::ulozStatekNaPlanszy(Statek &statek, int wiersz, int kolumna, int kierunek)
{
    int dlugosc_statku = statek.zwrocDlugoscStatku();
    int wiersz_konczacy_statek;
    int kolumna_konczaca_statek;

    switch(kierunek)
    {
    case 1:
        if(wiersz + 1 >= dlugosc_statku)
        {
            for(int i = 0; i < dlugosc_statku; i++)
            {
                if(pola_planszy[wiersz-i][kolumna].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)

            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz-i][kolumna]));

                if(kolumna-1 >= 0)
                {
                    pola_planszy[wiersz-i][kolumna-1].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    pola_planszy[wiersz-i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna+1 <= 9)
                {
                    pola_planszy[wiersz-i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }

            }

            wiersz_konczacy_statek = wiersz - dlugosc_statku + 1;

            for(int i = 0; i < 3; i++)
            {
                if(wiersz+1 <= 9 && kolumna-1+i >= 0 && kolumna-1+i <= 9)
                {
                    pola_planszy[wiersz+1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz+1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz_konczacy_statek-1 >= 0 && kolumna-1+i >= 0 && kolumna-1+i <=9)
                {
                    pola_planszy[wiersz_konczacy_statek-1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz_konczacy_statek-1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

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
                if(pola_planszy[wiersz][kolumna+i].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz][kolumna+i]));

                if(wiersz-1 >= 0)
                {
                    pola_planszy[wiersz-1][kolumna+i].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    pola_planszy[wiersz-1][kolumna+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz+1 <= 9)
                {
                    pola_planszy[wiersz+1][kolumna+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz+1][kolumna+i].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            kolumna_konczaca_statek = kolumna + dlugosc_statku -1;

            for(int i = 0; i < 3; i++)
            {
                if(kolumna-1 >= 0 && wiersz-1+i >= 0 && wiersz-1+i <= 9)
                {
                    pola_planszy[wiersz-1+i][kolumna-1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-1+i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna_konczaca_statek+1 <= 9 && wiersz-1+i >= 0 && wiersz-1+i <=9)
                {
                    pola_planszy[wiersz-1+i][kolumna_konczaca_statek+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-1+i][kolumna_konczaca_statek+1].ustawCzyJestWOtoczeniuStatku(true);
                }

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
                if(pola_planszy[wiersz+i][kolumna].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz+i][kolumna]));

                if(kolumna-1 >= 0)
                {
                    pola_planszy[wiersz+i][kolumna-1].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    pola_planszy[wiersz+i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna+1 <= 9)
                {
                    pola_planszy[wiersz+i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz+i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            wiersz_konczacy_statek = wiersz + dlugosc_statku - 1;

            for(int i = 0; i < 3; i++)
            {
                if(wiersz-1 >= 0 && kolumna-1+i >= 0 && kolumna-1+i <= 9)
                {
                    pola_planszy[wiersz-1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz_konczacy_statek+1 <= 9 && kolumna-1+i >= 0 && kolumna-1+i <=9)
                {
                    pola_planszy[wiersz_konczacy_statek+1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz_konczacy_statek+1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

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
                if(pola_planszy[wiersz][kolumna-i].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(pola_planszy[wiersz][kolumna-i]));

                if(wiersz-1 >= 0)
                {
                    pola_planszy[wiersz-1][kolumna-i].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    pola_planszy[wiersz-1][kolumna-i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz+1 <= 9)
                {
                    pola_planszy[wiersz+1][kolumna-i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz+1][kolumna-i].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            kolumna_konczaca_statek = kolumna - dlugosc_statku + 1;

            for(int i = 0; i < 3; i++)
            {
                if(kolumna+1 <= 9 && wiersz-1+i >= 0 && wiersz-1+i <= 9)
                {
                    pola_planszy[wiersz-1+i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-1+i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna_konczaca_statek-1 >= 0 && wiersz-1+i >= 0 && wiersz-1+i <=9)
                {
                    pola_planszy[wiersz-1+i][kolumna_konczaca_statek-1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    pola_planszy[wiersz-1+i][kolumna_konczaca_statek-1].ustawCzyJestWOtoczeniuStatku(true);
                }

            }
        }
        else
            throw out_of_range("Dany statek nie miesci sie na planszy");
        break;


    }


}