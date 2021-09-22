#include <iostream>
#include "GraczCzlowiek.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <limits>
#include <exception>


using namespace std;

GraczCzlowiek::GraczCzlowiek(string nazwa_gracza):Gracz()
{
    p_nazwa = nazwa_gracza;
}
GraczCzlowiek::~GraczCzlowiek()
{
    //cout << "To nie dziala " << endl;
}

void GraczCzlowiek:: ustawStatki()
{

    int wybrana_kolumna = 10;
    int wybrany_wiersz;
    int wybrany_kierunek;

    for(int i = 5; i>0; i--)
    {
        while(true)
        {
           wyswietlInfoWstepnePrzyUstawianiuStatkow();

           if(i!=1)
               cout << "Teraz ustawisz swoj statek o " << i << ". masztach" << endl;
           else
               cout << "Teraz ustawisz swoj statek jednomasztowy" << endl;

           pobierzOdGraczaLitere(wybrana_kolumna);
           pobierzOdGraczaLiczbeWiersz(wybrany_wiersz);

           if(i!=1)
               pobierzOdGraczaLiczbeKierunek(wybrany_kierunek);

           getchar();

           try
           {
               p_plansza.ulozStatkiNaPlanszy(wybrany_wiersz,wybrana_kolumna,wybrany_kierunek,i,1);
               break;
           }
           catch (out_of_range e)
           {
             cout << e.what() << endl;
             cout << "Bedziesz musial wybrac jego ustawienie jeszcze raz" << endl;
             getchar();
           }
        }

        if(i!=5 && i!=4)
        {
            while(true)
            {
               wyswietlInfoWstepnePrzyUstawianiuStatkow();

               if(i!=1)
                   cout << "Teraz ustawisz swoj drugi statek o " << i << ". masztach" << endl;
               else
                   cout << "Teraz ustawisz swoj drugi statek jednomasztowy" << endl;

               pobierzOdGraczaLitere(wybrana_kolumna);
               pobierzOdGraczaLiczbeWiersz(wybrany_wiersz);

               if(i!=1)
                   pobierzOdGraczaLiczbeKierunek(wybrany_kierunek);

               getchar();

               try
               {
                   p_plansza.ulozStatkiNaPlanszy(wybrany_wiersz,wybrana_kolumna,wybrany_kierunek,i,2);
                   break;
               }
               catch (out_of_range e)
               {
                   cout << e.what() << endl;
                   cout << "Bedziesz musial wybrac jego ustawienie jeszcze raz" << endl;
                   getchar();
               }
            }
        }
    }
    wyswietlInfoKoncowePoUstawieniuStatkow();
    wyczyscPlanszePoUstawieniuStatkow();
}
void GraczCzlowiek::wyswietlInfoWstepnePrzyUstawianiuStatkow()
{
    system("cls");
    cout << "Czesc " << zwrocNazwe() << "!" << endl;
    cout << "Twoim zadaniem jest ustawienie statkow" << endl;
    cout << "Tak wyglada obecnie Twoja plansza: " << endl << endl;
    wyswietlPlansze();
    cout << endl;
    cout<< "Pamietaj:" << endl;
    cout << "-Biale myslniki oznaczaja puste pola" << endl;
    cout << "-Czerwone krzyze miejsca zajete przez statki" << endl;
    cout << "-Zolte hasztagi okolice statkow, w ktorych nie moga znajdowac sie inne statki" << endl << endl;
    cout << "Twoja flota bedzie skladac sie z pojedynczego pieciomasztowca i czteromasztowca" << endl;
    cout << "oraz podwojnych trojmasztowcow, dwumasztowcow i jednomasztowcow" << endl;
    cout << endl;
    cout << "Poprosze Cie teraz o podanie litery od A-J, nastepnie liczby od 1-10 i jeszcze jednej liczby z zakresu 1-4" << endl;
    cout << "Litera i pierwsza liczba okresli, pole od ktorego zaczniemy ustawiac statek" << endl;
    cout << "Litera wskaze kolumne, liczba wiersz" << endl;
    cout << "Druga podana przez Ciebie liczba wskaze kierunek, w ktorym beda ulozone pozostale pola statku" << endl;
    cout << "1 - gora, 2 - prawy bok, 3 - dol, 4 - lewy bok" << endl << endl;
}

void GraczCzlowiek::wyswietlInfoKoncowePoUstawieniuStatkow()
{
    system("cls");
    cout << zwrocNazwe() << " ustawiles juz cala swoja flote!" << endl;
    cout << "Tak wyglada Twoja plansza: " << endl << endl;
    wyswietlPlansze();
    cout << endl;
}

void GraczCzlowiek::oddajStrzal(Gracz *przeciwnik)
{
    int wybrany_wiersz, wybrana_kolumna;
    bool czy_tura_trwa = true;

    while(czy_tura_trwa)
    {
        wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
        cout << "Poprosze Cie teraz o podanie litery od A-J, a nastepnie liczby od 1-10" << endl;
        cout << "Litera wskaze kolumne, liczba wiersz pola, w ktore strzelisz" << endl << endl;
        pobierzOdGraczaLitere(wybrana_kolumna);
        pobierzOdGraczaLiczbeWiersz(wybrany_wiersz);

        if(przeciwnik->czyWybranePoleByloWczesniejTrafione(wybrany_wiersz,wybrana_kolumna))
        {
            cout << "Strzelales juz w to miejsce, bedziesz musial wybrac inne pole" << endl;
            getchar(); getchar();
        }
        else
        {
            przeciwnik->ustawCzyPolePlanszyZostaloTrafione(true,wybrany_wiersz, wybrana_kolumna);
            czy_tura_trwa = przeciwnik->zwrocCzyPolePlanszyZawieraStatek(wybrany_wiersz, wybrana_kolumna);

            if(czy_tura_trwa)
            {
                wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
                cout << "Trafiles statek!" << endl;
                //cout << "Bedziesz mogl oddac kolejny strzal w tej turze" << endl;
                Pole *pole_trafione = przeciwnik->zwrocWskaznikNaPolePlanszyODanymWierszuKolumnie(wybrany_wiersz, wybrana_kolumna);
                Statek *statek_trafiony = przeciwnik->zwrocStatekDoKtoregoNalezyDanePole(pole_trafione);
                ++(*statek_trafiony);

                if(statek_trafiony->zwrocIleRazyTrafionoStatek() == 1)
                    statek_trafiony->ustawCzyJestTrafiony(true);

                if(statek_trafiony->zwrocIleRazyTrafionoStatek() == statek_trafiony->zwrocDlugoscStatku())
                {
                    statek_trafiony->ustawCzyJestZatopiony(true);
                    ++(*przeciwnik);
                    cout << "Statek, ktory trafiles zostal zatopiony!" << endl;

                    if(przeciwnik->zwrocLiczbeZatopionychStatkow() == 8)
                    {
                        cout << "Gracz " << zwrocNazwe() << " wygral!" << endl;
                        ustawCzyGraczWygral(true);                       
                        getchar(); getchar();
                        break;
                    }
                    else
                    {
                        cout << "Bedziesz mogl oddac kolejny strzal w tej turze" << endl;
                        odznaczPola(przeciwnik,statek_trafiony);
                        continue;

                    }

                }
                cout << "Bedziesz mogl oddac kolejny strzal w tej turze" << endl;
                getchar();
                getchar();
            }

        }

    }
    if(!zwrocCzyWygral())
    {
    wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
    cout << "Chybiles! Teraz bedzie wykonywal ruch Twoj przeciwnik -  ";
    cout << przeciwnik->zwrocNazwe() << endl;
    getchar(); getchar();
    }


}

void GraczCzlowiek::odznaczPola(Gracz *przeciwnik, Statek *zatopiony_statek)
{
    char odp;
    int odp_po_konwersji_na_liczbe;

    cout << "Czy chcesz zaznaczyc pola, w ktorych wg zasad nie moze byc statku?" << endl;
    spytajUzytkownikaCzyChceOdznaczycPole(odp,odp_po_konwersji_na_liczbe);

    if(odp_po_konwersji_na_liczbe == 84 || odp_po_konwersji_na_liczbe == 116)
       {
           zatopiony_statek->zaznaczOkoliceStatku();
           wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
       }
}

void GraczCzlowiek::wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik)
{
    system("cls");
    cout << zwrocNazwe() << " twoim zadaniem jest oddanie strzalu, wygrasz gre jesli zatopisz cala flote przeciwnika" << endl;
    cout << "Obecnie plansza Twojego przeciwnika wyglada tak: " << endl << endl;
    przeciwnik->wyswietlPlansze();
    cout << endl;
    cout<< "Pamietaj:" << endl;
    cout << "-Biale myslniki oznaczaja pola, ktore nie zostaly jeszcze trafione ani odznaczone" << endl;
    cout << "-Czerwone krzyze to pola statkow w trakcie zatapiania" << endl;
    cout << "-Niebieskie krzyze to pola statkow, ktore zostaly juz zatopione" << endl;
    cout << "-Biale hasztagi oznaczaja pola, do ktorych strzeliles, a nie zawieraly statku" << endl;
    cout << "-Zolte hasztagi to pola, ktore zostaly przez Ciebie zaznaczone" << endl << endl;

}


void spytajUzytkownikaCzyChceOdznaczycPole(char &odp, int &odp_po_konwersji_na_liczbe)
{
    cout << "Jesli tak wpisz 't', jesli nie 'n' " << endl;
    cin >> odp;
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    odp_po_konwersji_na_liczbe = (int)odp;

    while(odp_po_konwersji_na_liczbe != 84 && odp_po_konwersji_na_liczbe != 116 && odp_po_konwersji_na_liczbe != 78 && odp_po_konwersji_na_liczbe != 110)
    {
        cout << "Podales niepoprawny znak musze poprosic cie o ponowne jego podanie" << endl;
        cin >> odp;
        cin.ignore(numeric_limits < streamsize >::max(), '\n');
        odp_po_konwersji_na_liczbe = (int)odp;
    }
}
void pobierzOdGraczaLitere(int &wybrana_kolumna)
{
    char odpowiedz;
    int odpowiedz_liczba_po_konwersji;

    while(true)
    {
        cout << "Podaj litere z zakresu A-J: ";
        cin >> odpowiedz;
        cin.ignore(numeric_limits < streamsize >::max(), '\n');
        odpowiedz_liczba_po_konwersji = (int)odpowiedz;

        if(((65<= odpowiedz_liczba_po_konwersji) && (odpowiedz_liczba_po_konwersji<= 74)) || ((97<= odpowiedz_liczba_po_konwersji) && (odpowiedz_liczba_po_konwersji<= 106)))
        {
            if((65<= odpowiedz_liczba_po_konwersji) && (odpowiedz_liczba_po_konwersji<= 74))
                wybrana_kolumna = odpowiedz_liczba_po_konwersji-65;

            if((97<= odpowiedz_liczba_po_konwersji) && (odpowiedz_liczba_po_konwersji<= 106))
                wybrana_kolumna = odpowiedz_liczba_po_konwersji-97;

            break;
        }
        else
            cout << "Podales zly znak, poprosze Cie o ponowne podanie" << endl;

    }
}

void pobierzOdGraczaLiczbeWiersz(int &wybrany_wiersz)
{
    bool czy_jest_blad = false;
    int odpowiedz_liczba;
    do
    {
        cout << "Podaj liczbe calkowita z zakresu 1-10: ";
        cin >> odpowiedz_liczba;
        czy_jest_blad = cin.fail();

        if(czy_jest_blad)
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
        }

        if(czy_jest_blad || odpowiedz_liczba > 10 || odpowiedz_liczba < 1)
            cout << "Podales niepoprawne dane. Sprobuj jeszcze raz" << endl;
        else
            wybrany_wiersz = odpowiedz_liczba-1;

    }while(czy_jest_blad || odpowiedz_liczba > 10 || odpowiedz_liczba < 1);

}

void pobierzOdGraczaLiczbeKierunek(int &wybrany_kierunek)
{
    int odpowiedz_liczba;
    bool czy_jest_blad = false;
    do
    {
        cout << "Podaj liczbe calkowita z zakresu 1-4: ";
        cin >> odpowiedz_liczba;
        czy_jest_blad = cin.fail();

        if(czy_jest_blad)
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
        }

        if(czy_jest_blad || odpowiedz_liczba > 4 || odpowiedz_liczba < 1)
            cout << "Podales niepoprawne dane. Sprobuj jeszcze raz" << endl;
        else
            wybrany_kierunek = odpowiedz_liczba;

    }while(czy_jest_blad || odpowiedz_liczba > 4 || odpowiedz_liczba < 1);

}


