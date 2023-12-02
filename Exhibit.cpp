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
    for(Object object : storedObjects)
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
        storedObjects.push_back(objectsMap.at(objectReadValueJson["exhibitName"].s()));
    }
}

string Exhibit::getExhibitName()
{
    return exhibitName;
}
  
bool Exhibit::addObject(Object& object)
{
    // if(!objectExists(object))
    // {
    //     return false;
    // }
    string serialNumber = object.getSerialNum();
    for (auto& storedObject : storedObjects)
    {
        if(serialNumber == storedObject.getSerialNum())
        {
            return false;
        } 
    }
    //add the object to the back
    storedObjects.push_back(object);
    return true;
}

bool Exhibit::removeObject(Object& object)
{
    string serialNum = object.getSerialNum();
    int i = 0;
    for (auto& storedObject : storedObjects) 
    {
        if(serialNum == storedObject.getSerialNum())
        {
            storedObjects.erase(storedObjects.begin()+i);
        }
        i++;
    }
    return true;
}