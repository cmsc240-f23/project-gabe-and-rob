#ifndef GEMSTONE_H
#define GEMSTONE_H

#include <iostream>
#include <crow.h>
using namespace std;
#include "Object.h"

class Gemstone : public Object
{
public:
    Gemstone();
    Gemstone(crow::json::rvalue readValueJson);
    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);


    string getType();
    void setType(string newType){type = newType;}
    string getDimensions();
    void setDimensions(string newDimensions){dimensions = newDimensions;}

private:
    string type;
    string dimensions;
};

#endif