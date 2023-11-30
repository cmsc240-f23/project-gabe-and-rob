#ifndef GEMSTONE_H
#define GEMSTONE_H

#include <iostream>

using namespace std;
#include "Objects.h"

class Gemstone
{
public:
    Gemstone();
    string getType();
    string getDimensions();

private:
    string type;
    string dimensions;
};

#endif