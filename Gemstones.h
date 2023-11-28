#ifndef GEMSTONES_H
#define GEMSTONES_H

#include <iostream>

using namespace std;
#include "Objects.h"

class Gemstones
{
public:
    Gemstones();
    string getType();
    string getDimensions();

private:
    string type;
    string dimensions;
};

#endif