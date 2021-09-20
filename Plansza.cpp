#include <iostream>
#include "Plansza.h"
#include <string>
#include <exception>


using namespace std;

Plansza::Plansza()
{
    for (int i = 0; i < 10; i++)
    {
        p_pola_planszy.push_back(vector<Pole>());

        for(int j = 0; j < 10; j++)
        {
            p_pola_planszy[i].push_back(Pole());
        }

    }

    p_pieciomasztowiec.ustawDlugoscStatku(5);
    p_czteromasztowiec.ustawDlugoscStatku(4);
    p_trojmasztowiec1.ustawDlugoscStatku(3);
    p_trojmasztowiec2.ustawDlugoscStatku(3);
    p_dwumasztowiec1.ustawDlugoscStatku(2);
    p_dwumasztowiec2.ustawDlugoscStatku(2);
    p_jednomasztowiec1.ustawDlugoscStatku(1);
    p_jednomasztowiec2.ustawDlugoscStatku(1);

}
// z tego raczej nie bede korzystac (moze byc tu cos powodujace tajemniczy blad)
void Plansza::ustawStatek(Statek &statek, int typ, int numer)
{
    switch(typ)
    {
    case 1:
    {
        if(numer==1)
            p_jednomasztowiec1 = statek;
        else
            p_jednomasztowiec2 = statek;
        break;
    }
    case 2:
    {
        if(numer==1)
            p_dwumasztowiec1 = statek;
        else
            p_dwumasztowiec2 = statek;
        break;
    }
    case 3:
    {
        if(numer==1)
            p_trojmasztowiec1 = statek;
        else
            p_trojmasztowiec2 = statek;
        break;
    }
    case 4:
    {
        p_czteromasztowiec = statek;
        break;
    }
    case 5:
    {
        p_pieciomasztowiec = statek;
        break;
    }
    }
}

void Plansza::ulozStatkiNaPlanszy(int wiersz, int kolumna, int kierunek, int typ, int numer)
{
    switch(typ)
    {
    case 1:
    {
        if(numer==1)
            ulozStatekNaPlanszy(p_jednomasztowiec1,wiersz,kolumna,kierunek);
        else
            ulozStatekNaPlanszy(p_jednomasztowiec2,wiersz,kolumna,kierunek);
        break;
    }
    case 2:
    {
        if(numer==1)
            ulozStatekNaPlanszy(p_dwumasztowiec1,wiersz,kolumna,kierunek);
        else
            ulozStatekNaPlanszy(p_dwumasztowiec2,wiersz,kolumna,kierunek);
        break;
    }
    case 3:
    {
        if(numer==1)
            ulozStatekNaPlanszy(p_trojmasztowiec1,wiersz,kolumna,kierunek);
        else
            ulozStatekNaPlanszy(p_trojmasztowiec2,wiersz,kolumna,kierunek);
        break;
    }
    case 4:
    {
        ulozStatekNaPlanszy(p_czteromasztowiec,wiersz,kolumna,kierunek);
        break;
    }
    case 5:
    {
        ulozStatekNaPlanszy(p_pieciomasztowiec,wiersz,kolumna,kierunek);
        break;
    }
    }


}


// chyba jednak niepotrzebne wiec nieprzetestowane
Statek Plansza::zwrocStatek(int typ, int numer)
{
    switch(typ)
    {
    case 1:
    {
        if(numer==1)
            return p_jednomasztowiec1;
        else
            return p_jednomasztowiec2;
        break;
    }
    case 2:
    {
        if(numer==1)
            return p_dwumasztowiec1;
        else
            return p_dwumasztowiec2;
        break;
    }
    case 3:
    {
        if(numer==1)
            return p_trojmasztowiec1;
        else
            return p_trojmasztowiec2;
        break;
    }
    case 4:
    {
        return p_czteromasztowiec;
        break;
    }
    case 5:
    {
        return p_pieciomasztowiec;
        break;
    }
    }
}

void Plansza::wyswietlZawartoscPlanszy()
{
    Pole *wsk_pole;
    Statek *wsk_statek;
    int kolor = 0;
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(i == 9)
            cout << i + 1 << " ";
        else
            cout << " " << i + 1 << " ";

        for(int j = 0; j < 10; j++)
        {
            wsk_pole = &p_pola_planszy[i][j];

            if(wsk_pole->zwrocCzyPoleZawieraStatek())
            {
            wsk_statek = zwrocStatekDoKtoregoNalezyDanePole(wsk_pole);

            if(wsk_statek)
                kolor = 12;
            else
                kolor = 9;
            }

            p_pola_planszy[i][j].wyswietlPole(kolor);
            cout << " ";
        }
        cout << endl;

    }

}

void Plansza::wyswietlZawartoscPlanszyPodKoniecGry()
{

    Pole *wsk_pole;
    Statek *wsk_statek;
    int kolor = 0;
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < 10; i++)
    {
        if(i == 9)
            cout << i + 1 << " ";
        else
            cout << " " << i + 1 << " ";

        for(int j = 0; j < 10; j++)
        {
            wsk_pole = &p_pola_planszy[i][j];

            if(wsk_pole->zwrocCzyPoleZawieraStatek())
            {
            wsk_statek = zwrocStatekDoKtoregoNalezyDanePole(wsk_pole);

            if(!wsk_pole->zwrocCzyPoleJestTrafione())
            {
                kolor = 10;
                wsk_pole->ustawCzyZostaloTrafione(true);
            }
            else if(wsk_statek)
                kolor = 12;
            else
                kolor = 9;
            }

            p_pola_planszy[i][j].wyswietlPole(kolor);
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
                if(p_pola_planszy[wiersz-i][kolumna].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
                if(p_pola_planszy[wiersz-i][kolumna].zwrocCzyPoleZawieraStatek())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)

            {
                statek.dodajPoleStatku(&(p_pola_planszy[wiersz-i][kolumna]));

                if(kolumna-1 >= 0)
                {
                    p_pola_planszy[wiersz-i][kolumna-1].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    p_pola_planszy[wiersz-i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna+1 <= 9)
                {
                    p_pola_planszy[wiersz-i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }

            }

            wiersz_konczacy_statek = wiersz - dlugosc_statku + 1;

            for(int i = 0; i < 3; i++)
            {
                if(wiersz+1 <= 9 && kolumna-1+i >= 0 && kolumna-1+i <= 9)
                {
                    p_pola_planszy[wiersz+1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz+1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz_konczacy_statek-1 >= 0 && kolumna-1+i >= 0 && kolumna-1+i <=9)
                {
                    p_pola_planszy[wiersz_konczacy_statek-1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz_konczacy_statek-1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
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
                if(p_pola_planszy[wiersz][kolumna+i].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
                if(p_pola_planszy[wiersz][kolumna+i].zwrocCzyPoleZawieraStatek())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(p_pola_planszy[wiersz][kolumna+i]));

                if(wiersz-1 >= 0)
                {
                    p_pola_planszy[wiersz-1][kolumna+i].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    p_pola_planszy[wiersz-1][kolumna+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz+1 <= 9)
                {
                    p_pola_planszy[wiersz+1][kolumna+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz+1][kolumna+i].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            kolumna_konczaca_statek = kolumna + dlugosc_statku -1;

            for(int i = 0; i < 3; i++)
            {
                if(kolumna-1 >= 0 && wiersz-1+i >= 0 && wiersz-1+i <= 9)
                {
                    p_pola_planszy[wiersz-1+i][kolumna-1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-1+i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna_konczaca_statek+1 <= 9 && wiersz-1+i >= 0 && wiersz-1+i <=9)
                {
                    p_pola_planszy[wiersz-1+i][kolumna_konczaca_statek+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-1+i][kolumna_konczaca_statek+1].ustawCzyJestWOtoczeniuStatku(true);
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
                if(p_pola_planszy[wiersz+i][kolumna].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
                if(p_pola_planszy[wiersz+i][kolumna].zwrocCzyPoleZawieraStatek())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(p_pola_planszy[wiersz+i][kolumna]));

                if(kolumna-1 >= 0)
                {
                    p_pola_planszy[wiersz+i][kolumna-1].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    p_pola_planszy[wiersz+i][kolumna-1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna+1 <= 9)
                {
                    p_pola_planszy[wiersz+i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz+i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            wiersz_konczacy_statek = wiersz + dlugosc_statku - 1;

            for(int i = 0; i < 3; i++)
            {
                if(wiersz-1 >= 0 && kolumna-1+i >= 0 && kolumna-1+i <= 9)
                {
                    p_pola_planszy[wiersz-1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz_konczacy_statek+1 <= 9 && kolumna-1+i >= 0 && kolumna-1+i <=9)
                {
                    p_pola_planszy[wiersz_konczacy_statek+1][kolumna-1+i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz_konczacy_statek+1][kolumna-1+i].ustawCzyJestWOtoczeniuStatku(true);
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
                if(p_pola_planszy[wiersz][kolumna-i].zwrocCzyPoleJestWOtoczeniuStatku())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
                if(p_pola_planszy[wiersz][kolumna-i].zwrocCzyPoleZawieraStatek())
                    throw out_of_range("Statek nie moze byc ustawiony tak blisko drugiego");
            }

            for(int i = 0; i < dlugosc_statku; i++)
            {
                statek.dodajPoleStatku(&(p_pola_planszy[wiersz][kolumna-i]));

                if(wiersz-1 >= 0)
                {
                    p_pola_planszy[wiersz-1][kolumna-i].ustawCzyJestZaznaczone(true);//tylko dla testu;
                    p_pola_planszy[wiersz-1][kolumna-i].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(wiersz+1 <= 9)
                {
                    p_pola_planszy[wiersz+1][kolumna-i].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz+1][kolumna-i].ustawCzyJestWOtoczeniuStatku(true);
                }
            }
            kolumna_konczaca_statek = kolumna - dlugosc_statku + 1;

            for(int i = 0; i < 3; i++)
            {
                if(kolumna+1 <= 9 && wiersz-1+i >= 0 && wiersz-1+i <= 9)
                {
                    p_pola_planszy[wiersz-1+i][kolumna+1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-1+i][kolumna+1].ustawCzyJestWOtoczeniuStatku(true);
                }

                if(kolumna_konczaca_statek-1 >= 0 && wiersz-1+i >= 0 && wiersz-1+i <=9)
                {
                    p_pola_planszy[wiersz-1+i][kolumna_konczaca_statek-1].ustawCzyJestZaznaczone(true); //tylko dla testu
                    p_pola_planszy[wiersz-1+i][kolumna_konczaca_statek-1].ustawCzyJestWOtoczeniuStatku(true);
                }

            }
        }
        else
            throw out_of_range ("Dany statek nie miesci sie na planszy");
        break;


    }

}

void Plansza::wyczyscPlanszePoUstawieniuStatkow()
{
    for(int i = 0; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            p_pola_planszy[i][j].ustawCzyZostaloTrafione(false);
            p_pola_planszy[i][j].ustawCzyJestZaznaczone(false);
        }
    }
}

Pole* Plansza::zwrocWskaznikNaPoleODanymWierszuKolumnie(int wiersz, int kolumna)
{
    return &p_pola_planszy[wiersz][kolumna];
}

bool Plansza::czyWybranePoleByloWczesniejTrafione(int wiersz, int kolumna)
{
    return p_pola_planszy[wiersz][kolumna].zwrocCzyPoleJestTrafione();
}

void Plansza::ustawCzyPoleZostaloTrafione (bool czy_zostalo_trafione, int wiersz, int kolumna)
{
    p_pola_planszy[wiersz][kolumna].ustawCzyZostaloTrafione(czy_zostalo_trafione);
}

bool Plansza::zwrocCzyPoleZawieraStatek(int wiersz, int kolumna)
{
    return p_pola_planszy[wiersz][kolumna].zwrocCzyPoleZawieraStatek();
}

//zwaca null jesli pole nalezy do statku zatopionego lub nie nalezy do statku, i wsk na statek jesli nalezy do statku niezatopionego (trafionego lub nie)
Statek* Plansza::zwrocStatekDoKtoregoNalezyDanePole(Pole *pole)
{
    if(!(p_pieciomasztowiec.zwrocCzyStatekJestZatopiony()))
    {
        if(p_pieciomasztowiec.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_pieciomasztowiec;
        }
    }

    if(!(p_czteromasztowiec.zwrocCzyStatekJestZatopiony()))
    {
        if(p_czteromasztowiec.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_czteromasztowiec;
        }
    }

    if(!(p_trojmasztowiec1.zwrocCzyStatekJestZatopiony()))
    {
        if(p_trojmasztowiec1.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_trojmasztowiec1;
        }
    }

    if(!(p_trojmasztowiec2.zwrocCzyStatekJestZatopiony()))
    {
        if(p_trojmasztowiec2.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_trojmasztowiec2;
        }
    }

    if(!(p_dwumasztowiec1.zwrocCzyStatekJestZatopiony()))
    {
        if(p_dwumasztowiec1.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_dwumasztowiec1;
        }
    }

    if(!(p_dwumasztowiec2.zwrocCzyStatekJestZatopiony()))
    {
        if(p_dwumasztowiec2.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_dwumasztowiec2;
        }
    }

    if(!(p_jednomasztowiec1.zwrocCzyStatekJestZatopiony()))
    {
        if(p_jednomasztowiec1.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_jednomasztowiec1;
        }
    }

    if(!(p_jednomasztowiec2.zwrocCzyStatekJestZatopiony()))
    {
        if(p_jednomasztowiec2.sprawdzCzyDanePoleJestCzesciaStatku(pole))
        {
            //pieciomasztowiec.ustawCzyJestTrafiony(true);
            return &p_jednomasztowiec2;
        }
    }

    return NULL;

}


