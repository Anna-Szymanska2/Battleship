#include <iostream>
#include "GraczKomputer.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <tuple>
#include <algorithm>

using namespace std;

GraczKomputer::GraczKomputer():Gracz()
{
    srand(time(NULL));
    int wylosowana_liczba = rand()%8;
    switch(wylosowana_liczba)
    {
    case 0:
       p_nazwa = "Wieslaw";
        break;
    case 1:
        p_nazwa = "Janusz";
        break;
    case 2:
        p_nazwa = "Ryszard";
        break;
    case 3:
        p_nazwa = "Zbigniew";
        break;
    case 4:
        p_nazwa = "Grazyna";
        break;
    case 5:
        p_nazwa = "Kunegunda";
        break;
    case 6:
        p_nazwa = "Marzena";
        break;
    case 7:
        p_nazwa = "Miroslawa";
        break;
    }


}

void GraczKomputer::ustawMozliwePolaZeStatkami(Gracz *przeciwnik)
{
    tuple<int, int, Pole*> mozliwe_pole_ze_statkiem(0,0,0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            get<0>(mozliwe_pole_ze_statkiem) = i;
            get<1>(mozliwe_pole_ze_statkiem) = j;
            get<2>(mozliwe_pole_ze_statkiem) = przeciwnik->zwrocWskaznikNaPolePlanszyODanymWierszuKolumnie(i,j);
            p_mozliwe_pola_ze_statkami.push_back(mozliwe_pole_ze_statkiem);
        }
    }

}

void GraczKomputer::dodajPoleZatapianegoStatku(int wiersz, int kolumna, Pole *pole)
{
    tuple<int, int,Pole*> t;
    get<0>(t) = wiersz;
    get<1>(t) = kolumna;
    get<2>(t) = pole;
    p_pola_zatapianego_statku.push_back(t);
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
               p_plansza.ulozStatkiNaPlanszy(wylosowany_wiersz,wylosowana_kolumna,wylosowany_kierunek,i,1);
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
                   p_plansza.ulozStatkiNaPlanszy(wylosowany_wiersz,wylosowana_kolumna,wylosowany_kierunek,i,2);
                   break;
               }
               catch (out_of_range)
               {

               }
            }
        }

    }
    //wyczyscPlanszePoUstawieniuStatkow(); po testach trzeba odkomentowac

}

void GraczKomputer::oddajStrzal(Gracz *przeciwnik)
{
    pair<int,int> wybrane_miejsce;
    int wylosowana_liczba;
    bool czy_tura_trwa = true;

    while(czy_tura_trwa)
    {
        wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);

        if(p_pola_zatapianego_statku.size() == 0)
        {           
            srand(time(NULL));
            wylosowana_liczba = rand()% p_mozliwe_pola_ze_statkami.size();
            wybrane_miejsce.first = get<0>(p_mozliwe_pola_ze_statkami[wylosowana_liczba]);
            wybrane_miejsce.second = get<1>(p_mozliwe_pola_ze_statkami[wylosowana_liczba]);
            p_mozliwe_pola_ze_statkami.erase(p_mozliwe_pola_ze_statkami.begin() + wylosowana_liczba);


        }
        else
        {
            if(p_pola_zatapianego_statku.size() == 1)
            {
                while(true)
                {
                    wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0])-1;
                    wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0]);
                    auto it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                      [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                    if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                    {
                        p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                        break;
                    }

                    wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0]);
                    wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0])+1;
                    it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                      [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                    if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                    {
                        p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                        break;
                    }

                    wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0])+1;
                    wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0]);
                    it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                      [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                    if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                    {
                        p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                        break;
                    }

                    wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0]);
                    wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0])-1;
                    it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                      [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                    if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                    {
                        p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                        break;
                    }
                }
            }
            else
            {
                int indeks_na_ostatni_element = p_pola_zatapianego_statku.size() - 1;
                //sprawdza czy statek jest poziomo
                if(get<0>(p_pola_zatapianego_statku[0]) == get<0>(p_pola_zatapianego_statku[1]))
                {
                    while(true)
                    {
                        wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[indeks_na_ostatni_element]);
                        wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[indeks_na_ostatni_element])+1;
                        auto it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                          [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                        if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                        {
                            p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                            break;
                        }

                        wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0]);
                        wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0])-1;
                        it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                          [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                        if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                        {
                            p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                            break;
                        }
                    }
                }
                else
                {
                    while(true)
                    {
                        wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[0])-1;
                        wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[0]);
                        auto it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                          [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                        if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                        {
                            p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                            break;
                        }

                        wybrane_miejsce.first = get<0>(p_pola_zatapianego_statku[indeks_na_ostatni_element])+1;
                        wybrane_miejsce.second = get<1>(p_pola_zatapianego_statku[indeks_na_ostatni_element]);
                        it_szukany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                                          [wybrane_miejsce](tuple <int,int,Pole*> &t){return (get<0>(t) == wybrane_miejsce.first) && (get<1>(t) == wybrane_miejsce.second);});

                        if(it_szukany_element != p_mozliwe_pola_ze_statkami.end())
                        {
                            p_mozliwe_pola_ze_statkami.erase(it_szukany_element);
                            break;
                        }


                    }
                }
            }

        }

        przeciwnik->ustawCzyPolePlanszyZostaloTrafione(true,wybrane_miejsce.first, wybrane_miejsce.second);
        czy_tura_trwa = przeciwnik->zwrocCzyPolePlanszyZawieraStatek(wybrane_miejsce.first, wybrane_miejsce.second);
        cout << zwrocNazwe() << " strzela w pole " << char(wybrane_miejsce.second+65) << wybrane_miejsce.first+1 << "!" << endl;
        getchar();

        //cout << "Poprosze Cie teraz o podanie litery od A-J, a nastepnie liczby od 1-10" << endl;
        //cout << "Litera wskaze kolumne, liczba wiersz pola, w ktore strzelisz" << endl << endl;
       // pobierzOdGraczaLitere(wybrana_kolumna);
       // pobierzOdGraczaLiczbeWiersz(wybrany_wiersz);

//        if(przeciwnik->czyWybranePoleByloWczesniejTrafione(wybrany_wiersz,wybrana_kolumna))
//        {
//            cout << "Strzelales juz w to miejsce, bedziesz musial wybrac inne pole" << endl;
//            getchar(); getchar();
//        }
//        else
//        {


            if(czy_tura_trwa)
            {
                wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
                cout << zwrocNazwe() << " trafia statek!" << endl;
                //cout << "Bedziesz mogl oddac kolejny strzal w tej turze" << endl;
                Pole *pole_trafione = przeciwnik->zwrocWskaznikNaPolePlanszyODanymWierszuKolumnie(wybrane_miejsce.first, wybrane_miejsce.second);
                Statek *statek_trafiony = przeciwnik->zwrocStatekDoKtoregoNalezyDanePole(pole_trafione);
                ++(*statek_trafiony);
                dodajPoleZatapianegoStatku(wybrane_miejsce.first, wybrane_miejsce.second,pole_trafione);
                sort(p_pola_zatapianego_statku.begin(),p_pola_zatapianego_statku.end(),predykatSortujacyPolaZatapianegoStatku);

                if(statek_trafiony->zwrocIleRazyTrafionoStatek() == 1)
                {
                    statek_trafiony->ustawCzyJestTrafiony(true);
                }

                if(statek_trafiony->zwrocIleRazyTrafionoStatek() == statek_trafiony->zwrocDlugoscStatku())
                {
                    statek_trafiony->ustawCzyJestZatopiony(true);
                    ++(*przeciwnik);
                    cout << "Statek, ktory trafil " << zwrocNazwe() << " zostal zatopiony!" << endl;
                    p_pola_zatapianego_statku.erase(p_pola_zatapianego_statku.begin(),p_pola_zatapianego_statku.end());

                    if(przeciwnik->zwrocLiczbeZatopionychStatkow() == 8)
                    {
                        cout << "Gracz " << zwrocNazwe() << " wygral!" << endl;
                        ustawCzyGraczWygral(true);
                        getchar(); getchar();
                        break;
                    }
                    else
                    {
                        cout << "Gracz " << zwrocNazwe() << " bedzie mogl oddac kolejny strzal w tej turze" << endl;
                        odznaczPola(przeciwnik,statek_trafiony);
                        continue;

                    }

                 }
                cout << "Gracz " << zwrocNazwe() << " bedzie mogl oddac kolejny strzal w tej turze" << endl;
               // getchar();
                getchar();
            }

       // }

    }
    if(!zwrocCzyWygral())
    {
    wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);
    cout << "Komputer " << zwrocNazwe() << " chybia! Teraz bedzie Twoj ruch, ";
    cout << przeciwnik->zwrocNazwe() << endl;
    getchar();// getchar();
    }


}

void GraczKomputer:: odznaczPola(Gracz *przeciwnik, Statek *zatopiony_statek)
{
    vector<Pole*> okolice_statku = zatopiony_statek->zwrocWektorOkolicStatku();

    cout << "Teraz "<< zwrocNazwe() << " zaznaczy pola, gdzie nie moze byc statku" << endl;
    getchar();
    zatopiony_statek->zaznaczOkoliceStatku();
    wyswietlInfoWstepnePrzyOddaniuStrzalu(przeciwnik);

    for(unsigned int i = 0; i < okolice_statku.size(); i++)
    {
        auto it_usuwany_element = find_if(p_mozliwe_pola_ze_statkami.begin(),p_mozliwe_pola_ze_statkami.end(),
                          [okolice_statku,i](tuple <int,int,Pole*> &t){return get<2>(t) == okolice_statku[i];});
        p_mozliwe_pola_ze_statkami.erase(it_usuwany_element);
    }
}

void GraczKomputer::wyswietlInfoWstepnePrzyOddaniuStrzalu(Gracz *przeciwnik)
{
    system("cls");
    cout << "Gracz " << zwrocNazwe() << " bedzie teraz oddawal strzal do Twojej planszy, ktora z jego perspektywy wyglada tak:" << endl << endl;
    przeciwnik->wyswietlPlansze();
    cout << endl;
    cout<< "Pamietaj:" << endl;
    cout << "-Biale myslniki oznaczaja pola, ktore nie zostaly jeszcze trafione ani zaznaczone" << endl;
    cout << "-Czerwone krzyze to pola statkow w trakcie zatapiania" << endl;
    cout << "-Niebieskie krzyze to pola statkow, ktore zostaly juz zatopione" << endl;
    cout << "-Biale hasztagi oznaczaja pola, do ktorych komputer strzelil, a nie zawieraly statku" << endl;
    cout << "-Zolte hasztagi to pola, ktore zostaly przez niego zaznaczone" << endl << endl;

}

bool predykatSortujacyPolaZatapianegoStatku(tuple<int,int,Pole*> t1,tuple<int,int,Pole*> t2)
{
    return (get<0>(t1)<get<0>(t2) || get<1>(t1)<get<1>(t2));
}


GraczKomputer::~GraczKomputer(){}
