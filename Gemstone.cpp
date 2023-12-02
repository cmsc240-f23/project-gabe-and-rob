#include "Gemstone.h"
#include <iostream>
#include <crow.h>

using namespace std;
using namespace crow;

Gemstone::Gemstone() {}

Gemstone::Gemstone(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

crow::json::wvalue Gemstone::convertToJson()
{
    json::wvalue writeJson = Object::convertToJson();
    writeJson["type"] = type;
    writeJson["dimensions"] = dimensions;
    return writeJson;
}

void Gemstone::updateFromJson(crow::json::rvalue readValueJson)
{
    Object::updateFromJson(readValueJson);
    type = readValueJson["type"].s();
    dimensions = readValueJson["dimensions"].s();
}

string Gemstone::getType()
{
    return type;
}

string Gemstone::getDimensions()
{
    return dimensions;
}