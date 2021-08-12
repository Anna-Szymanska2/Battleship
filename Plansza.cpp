#include <iostream>
#include "Plansza.h"
#include <string>


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
