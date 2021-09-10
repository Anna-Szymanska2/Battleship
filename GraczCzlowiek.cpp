#include <iostream>
#include "GraczCzlowiek.h"
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <limits>

using namespace std;

GraczCzlowiek::GraczCzlowiek():Gracz()
{
    cout << "Podaj jak sie nazywasz" << endl;
    getline(cin,nazwa);
}
GraczCzlowiek::~GraczCzlowiek()
{
    cout << "To nie dziala " << endl;
}

void GraczCzlowiek:: ustawStatki()
{

    int wybrana_kolumna = 10;
    int wybrany_wiersz;
    int wybrany_kierunek;
    char odpowiedz = 'k';
    int odpowiedz_liczba_po_konwersji = 10;
    int odpowiedz_liczba = 100;

    for(int i = 5; i>0; i--)
    {
        while(true)
        {
           wyswietlInfoWstepnePrzyUstawianiuStatkow();

           if(i!=0)
               cout << "Teraz ustawisz swoj statek o " << i << ". masztach" << endl;
           else
               cout << "Teraz ustawisz swoj statek jednomasztowy" << endl;

           pobierzOdGraczaLitere(odpowiedz_liczba_po_konwersji,odpowiedz,wybrana_kolumna);
           //cout << wybrana_kolumna << endl;
           pobierzOdGraczaLiczbeWiersz(wybrany_wiersz,odpowiedz_liczba);
           //cout << wybrany_wiersz;
           if(i!=1)
           pobierzOdGraczaLiczbeKierunek(wybrany_kierunek,odpowiedz_liczba);
           //cout << wybrany_kierunek;
           getchar();getchar();

           try
           {
               plansza.ulozStatkiNaPlanszy(wybrany_wiersz,wybrana_kolumna,wybrany_kierunek,i,1);
               break;
           }
           catch (out_of_range e)
           {
             e.what();
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

               pobierzOdGraczaLitere(odpowiedz_liczba_po_konwersji,odpowiedz,wybrana_kolumna);
              // cout << wybrana_kolumna << endl;
               pobierzOdGraczaLiczbeWiersz(wybrany_wiersz,odpowiedz_liczba);
              // cout << wybrany_wiersz;
               if(i!=1)
               pobierzOdGraczaLiczbeKierunek(wybrany_kierunek,odpowiedz_liczba);
              // cout << wybrany_kierunek;
               getchar();getchar();

               try
               {
                   plansza.ulozStatkiNaPlanszy(wybrany_wiersz,wybrana_kolumna,wybrany_kierunek,i,2);
                   break;
               }
               catch (out_of_range e)
               {
                   e.what();
                   cout << "Bedziesz musial wybrac jego ustawienie jeszcze raz" << endl;
                   getchar();
               }
            }
        }
    }
}
void GraczCzlowiek::wyswietlInfoWstepnePrzyUstawianiuStatkow()
{
    system("cls");
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
    cout << "Poprosze Cie teraz o podanie o litery od A-J, nastepnie liczby od 1-10 i jeszcze jednej liczby z zakresu 1-4" << endl;
    cout << "Litera i pierwsza liczba okresli, pole od ktorego zaczniemy ustawiac statek" << endl;
    cout << "Litera wskaze kolumne, liczba wiersz" << endl;
    cout << "Druga podana przez Ciebie liczba wskaze kierunek, w ktorym beda ulozone pozostale pola statku" << endl;
    cout << "1 - gora, 2 - prawy bok, 3 - dol, 4 - lewy bok" << endl << endl;
}

void pobierzOdGraczaLitere(int odpowiedz_liczba_po_konwersji, char odpowiedz, int &wybrana_kolumna)
{

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

void pobierzOdGraczaLiczbeWiersz(int &wybrany_wiersz, int odpowiedz_liczba)
{
    bool czy_jest_blad = false;
    do
    {
        cout << "Podaj liczbe calkowita z zakresu 1-10";
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

void pobierzOdGraczaLiczbeKierunek(int &wybrany_kierunek, int odpowiedz_liczba)
{
    bool czy_jest_blad = false;
    do
    {
        cout << "Podaj liczbe calkowita z zakresu 1-4";
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
