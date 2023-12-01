#include "Gemstone.h"
#include <iostream>

using namespace std;

Gemstone::Gemstone() {}

Gemstone::Gemstone(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

crow::json::wvalue Gemstone::convertToJson()
{
    json::wvalue writeJson;
    writeJson["type"] = type;
    writeJson["dimensions"] = dimensions;
    return writeJson;
}

void Gemstone::updateFromJson(crow::json::rvalue readValueJson)
{
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