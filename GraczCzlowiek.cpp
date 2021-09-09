#include <iostream>
#include "GraczCzlowiek.h"
#include <string>

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
