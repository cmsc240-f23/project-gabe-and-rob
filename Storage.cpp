#include "Storage.h"
#include <iostream>
#include <crow.h>

using namespace std;
using namespace crow;

Storage::Storage(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Storage::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = id;
    writeJson["storageName"] = storageName;
    writeJson["storedObjects"] = storedObject;
    return writeJson;
}

// Update from JSON
void Storage::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    storageName = readValueJson["storageName"].s();
    storedObject = readValueJson["storedObjects"].v();
}

string Storage::getStorageName() const
{
    return storageName;
}

bool Storage::objectExists(vector<Object> object)
{
    for(int i = 0; i < object; i++)
    {
        
    }
}