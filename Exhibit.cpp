#include "Exhibit.h"
#include <iostream>
#include <vector>
#include <crow.h>
using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;
extern map<std::string, Artwork> artworksMap;
extern map<std::string, Gemstone> gemstonesMap;

Exhibit::Exhibit() {}

Exhibit::Exhibit(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}

crow::json::wvalue Exhibit::convertToJson()
{
    json::wvalue writeJson;
    writeJson["exhibitName"] = exhibitName;
    writeJson["serialNum"] = serialNum;

    //convert objects to json by the exhibit names
    int index = 0;
    for(Object object : storedObjects)
    {
        writeJson["storedObjects"][index]["serialNum"] = object.getSerialNum();
    }
    index = 0;
    for (Object artwork : storedArtworks) 
    {
        writeJson["storedArtworks"][index]["serialNum"] = artwork.getSerialNum();
        index ++;
    }
    index = 0;
    for (Object gemstone : storedGemstones) 
    {
        writeJson["storedGemstones"][index]["serialNum"] = gemstone.getSerialNum();
        index ++;
    }


    return writeJson;
}

bool Exhibit::updateFromJson(crow::json::rvalue readValueJson)
{
    exhibitName = readValueJson["exhibitName"].s();
    serialNum = readValueJson["serialNum"].s();

    for(crow::json::rvalue objectReadValueJson: readValueJson["storedObjects"])
    {
        storedObjects.push_back(objectsMap.at(objectReadValueJson["serialNum"].s()));
    }
    for (json::rvalue storedArtworksReadValueJson: readValueJson["storedArtworks"])
    {
        storedArtworks.push_back(artworksMap.at(storedArtworksReadValueJson["serialNum"].s()));
    }
    for (json::rvalue storedGemstonesReadValueJson: readValueJson["storedGemstones"])
    {
        storedGemstones.push_back(gemstonesMap.at(storedGemstonesReadValueJson["serialNum"].s()));
    }
    return true;
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