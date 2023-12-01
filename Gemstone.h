#ifndef GEMSTONE_H
#define GEMSTONE_H

#include <iostream>
#include <crow.h>
using namespace std;
#include "Object.h"

class Gemstone
{
public:
    Gemstone();
    Gemstone(crow::json::rvalue readValueJson);
    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);


    string getType();
    string getDimensions();

private:
    string type;
    string dimensions;
};

#endif