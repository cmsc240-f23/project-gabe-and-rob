#include "Object.h"
#include <iostream>
#include <crow.h>
using namespace std;
using namespace crow;

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
    writeJson["serialNum"] = serialNum;
    writeJson["weight"] = weight;
    writeJson["location"] = location;
    writeJson["donor"] = donor;
    writeJson["dateRetrieved"] = dateRetrieved; 

    return writeJson;
}

// Update from JSON
void Object::updateFromJson(crow::json::rvalue readValueJson) 
{
    serialNum = readValueJson["serialNum"].s();
    weight = readValueJson["weight"].i();
    location = readValueJson["location"].s();
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