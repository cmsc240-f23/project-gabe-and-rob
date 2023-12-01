#include "Exhibit.h"
#include <iostream>
#include <vector>
#include <crow.h>
using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;

Exhibit::Exhibit() {}

Exhibit::Exhibit(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

crow::json::wvalue Exhibit::convertToJson()
{
    json::wvalue writeJson;
    writeJson["exhibitName"] = exhibitName;
    writeJson["idNum"] = idNum;

    //convert objects to json by the exhibit names
    int index = 0;
    for(Object object : exhibits)
    {
        writeJson["exhibits"][index]["exhibitName"] = object.getLocation();
    }

    return writeJson;
}

void Exhibit::updateFromJson(crow::json::rvalue readValueJson)
{
    exhibitName = readValueJson["exhibitName"].s();
    idNum = readValueJson["idNum"].i();

    for(crow::json::rvalue objectReadValueJson: readValueJson["exhibits"])
    {
        exhibits.push_back(objectsMap.at(objectReadValueJson["exhibitName"].s()));
    }
}

string Exhibit::getExhibitName()
{
    return exhibitName;
}

bool Exhibit::addObject(vector<Object> stored)
{
    return true; 

}