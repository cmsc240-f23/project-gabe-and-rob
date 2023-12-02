#include "Storage.h"
#include <iostream>
#include <crow.h>

using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;

Storage::Storage(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

Storage::Storage(){}

// Convert to JSON
json::wvalue Storage::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["serialNum"] = serialNum;
    writeJson["storageName"] = storageName;
    
    // Convert objects to json (Save only the ids)
    int index = 0;
    for (Object object : storedObjects) 
    {
        writeJson["storedObjects"][index]["serialNum"] = object.getSerialNum();
        index ++;
    }

    return writeJson;
}

// Update from JSON
void Storage::updateFromJson(json::rvalue readValueJson) 
{
    serialNum = readValueJson["serialNum"].s();
    storageName = readValueJson["storageName"].s();

    // Setting artists
    for (json::rvalue storedObjectReadValueJson: readValueJson["storedObjects"])
    {
        storedObjects.push_back(objectsMap.at(storedObjectReadValueJson["serialNum"].s()));
    }
    
}

bool Storage::objectExists(Object& object)
{
    string serialNumber = object.getSerialNum();
    for(int i = 0; i < storedObjects.size(); i++)
    {
        Object storedObject = storedObjects.at(i);
        if(serialNumber == storedObject.getSerialNum())
        {
            return true;
        }
    }
    return false;
}

//  bool Storage::objectExists();
//  {
//     //if the object does exist in the storedObjects vector
//     return true; 
//  }

bool Storage::addObject(Object& object)
{
    // if(!objectExists(object))
    // {
    //     return false;
    // }


    string serialNumber = object.getSerialNum();
    for(int i = 0; i < storedObjects.size(); i++)
    {
        //add the object to the back
        storedObjects.push_back(object);
        Object storedObject = storedObjects.at(storedObjects.size() - 1);
        if(serialNumber != storedObject.getSerialNum())
        {
            return false;
        }
        
    }
    return true;
    

}

bool Storage::removeObject(Object& object)
{
    string serialNumber = object.getSerialNum();

    for(int i = 0; i < storedObjects.size(); i++)
    {
        // if(object == storedObjects.at(i))
        // {
        //     storedObjects.erase(i);
        // }
    }
    return true;
}


