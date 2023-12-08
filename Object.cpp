#include "Object.h"
#include "Artwork.h"
#include "Gemstone.h"
#include "Storage.h"
#include "Exhibit.h"
#include <iostream>
#include <crow.h>
using namespace std;
using namespace crow;

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
    bool value;
    //Edit to make 'Unsorted' the default
    if((storagesMap.find(new_location) != storagesMap.end())){
        if((storagesMap.find(original_location) != storagesMap.end()))
        {
            Storage old_storage = storagesMap.at(original_location);
            old_storage.removeFromStorage(serialNum);
        }
        if((exhibitsMap.find(original_location) != exhibitsMap.end())){
            Exhibit old_storage = exhibitsMap.at(original_location);
            old_storage.removeFromExhibit(serialNum);
        }
        Storage new_storage = storagesMap.at(new_location);
        new_storage.addToStorage(serialNum);
        location = readValueJson["location"].s();
        value = true;
    }
    else if((exhibitsMap.find(new_location) != exhibitsMap.end())){
        if((storagesMap.find(original_location) != storagesMap.end()))
        {
            Storage old_storage = storagesMap.at(original_location);
            old_storage.removeFromStorage(serialNum);
        }
        if((exhibitsMap.find(original_location) != exhibitsMap.end())){
            Exhibit old_storage = exhibitsMap.at(original_location);
            old_storage.removeFromExhibit(serialNum);
        }
        Exhibit new_storage = exhibitsMap.at(new_location);
        new_storage.addToExhibit(serialNum);
        location = readValueJson["location"].s();
        value = true;
    }
    else{
        value = false;
    }
    name = readValueJson["name"].s();
    serialNum = readValueJson["serialNum"].s();
    weight = readValueJson["weight"].s();
    donor = readValueJson["donor"].s();
    dateRetrieved = readValueJson["dateRetrieved"].s();
    return true;
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

string Object::getWeight()
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