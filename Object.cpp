#include "Object.h"
#include <iostream>
using namespace std;

Object::Object()
{

}

string Object::moveObjects(string loc)
{
    

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

int Object::getSerialNumber()
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

    if(object.getSerialNumber() != this->getSerialNumber())
    {
        return false;
    }
    return true;
    


}