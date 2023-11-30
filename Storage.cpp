#include "Storage.h"
#include <iostream>

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
    writeJson["storedObjects"] = storedObjects;
    return writeJson;
}

// Update from JSON
void Genre::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    genre = readValueJson["genre"].s();
    storedObjects = readValueJson["storedObjects"].v();
}