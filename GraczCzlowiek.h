#pragma once

#include <string>
#include <iostream>
#include "Gracz.h"

using namespace std;

class GraczCzlowiek: public Gracz
{
public:
    GraczCzlowiek();
    ~GraczCzlowiek();
    void ustawStatki();

};
