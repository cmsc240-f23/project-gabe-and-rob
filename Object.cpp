#include "Object.h"
#include "Storage.h"
#include "Exhibit.h"
#include <iostream>
#include <crow.h>
using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;
extern map<std::string, Storage> storagesMap;
extern map<std::string, Exhibit> exhibitsMap;

Object::Object()
{

}

Object::Object(crow::json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

crow::json::wvalue Object::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["name"] = name;
    writeJson["serialNum"] = serialNum;
    writeJson["weight"] = weight;
    writeJson["location"] = location;
    writeJson["donor"] = donor;
    writeJson["dateRetrieved"] = dateRetrieved; 

    return writeJson;
}

// Update from JSON
bool Object::updateFromJson(crow::json::rvalue readValueJson) 
{
    string original_location = location;
    string new_location = readValueJson["location"].s();
    if(new_location != location)
        try
        {
            Storage oldStorage = storagesMap.at(original_location);
            Storage newStorage = storagesMap.at(new_location);
            oldStorage.removeObject(*this);
            newStorage.addObject(*this);
            location = readValueJson["location"].s();
        }
        catch(...)
        {
            try
            {
                Exhibit oldStorage = exhibitsMap.at(original_location);
                Exhibit newStorage = exhibitsMap.at(new_location);
                oldStorage.removeObject(*this);
                newStorage.addObject(*this);
                location = readValueJson["location"].s();
            }
            catch(...)
            {
                return false;
            }
        }
    name = readValueJson["name"].s();
    serialNum = readValueJson["serialNum"].s();
    weight = readValueJson["weight"].i();
    donor = readValueJson["donor"].s();
    dateRetrieved = readValueJson["dateRetrieved"].s();
}

string Object::getLocation()
{
    return location;
}

string Object::getDonor()
{
    return donor;
}

string Object::getDateRetrieved()
{
    return dateRetrieved;
}

int Object::getWeight()
{
    return weight;
}

std::string Object::getSerialNum()
{
    return serialNum;
}

bool Object::compare(Object& object)
{
    if(object.getLocation() != this->getLocation())
    {
        return false;
    }

    if(object.getDonor() != this->getDonor())
    {
        return false;
    }

    if(object.getDateRetrieved() != this->getDateRetrieved())
    {
        return false;
    }

    if(object.getWeight() != this->getWeight())
    {
        return false;
    }

    if(object.getSerialNum() != this->getSerialNum())
    {
        return false;
    }

    return true;
    
}