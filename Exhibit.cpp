#include "Exhibit.h"
#include "GenericAPI.h"
#include "persistence.h"
#include <iostream>
#include <vector>
#include <crow.h>
using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;
extern map<std::string, Artwork> artworksMap;
extern map<std::string, Gemstone> gemstonesMap;
extern map<std::string, Exhibit> exhibitsMap;

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

bool Exhibit::addToExhibit(string serialNum){
    cout << "Got to Function" << endl;
    if(objectsMap.find(serialNum) != objectsMap.end()){
        cout << "got to object in vector" << endl;
        Object object = objectsMap.at(serialNum);
        bool funct_complete = this->addObject(object);
        return funct_complete;
    }
    else if(artworksMap.find(serialNum) != artworksMap.end()){
        Artwork artwork = artworksMap.at(serialNum);
        bool funct_complete = this->addArtwork(artwork);
        return funct_complete;
    }
    else if(gemstonesMap.find(serialNum) != gemstonesMap.end()){
        Gemstone gemstone = gemstonesMap.at(serialNum);
        bool funct_complete = this->addGemstone(gemstone);
        return funct_complete;
    }
    else{
        return false;
    }
}

bool Exhibit::removeFromExhibit(string serialNum){
    if(objectsMap.find(serialNum) != objectsMap.end()){
        Object object = objectsMap.at(serialNum);
        bool funct_complete = this->removeObject(object);
        return funct_complete;
    }
    else if(artworksMap.find(serialNum) != artworksMap.end()){
        Artwork artwork = artworksMap.at(serialNum);
        bool funct_complete = this->removeArtwork(artwork);
        return funct_complete;
    }
    else if(gemstonesMap.find(serialNum) != gemstonesMap.end()){
        Gemstone gemstone = gemstonesMap.at(serialNum);
        bool funct_complete = this->removeGemstone(gemstone);
        return funct_complete;
    }
    else{
        return false;
    }
}
  
bool Exhibit::addObject(Object& object)
{
    // if(!objectExists(object))
    // {
    //     return false;
    // }
     cout << "called addObject" << endl;
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
    cout << "added Object" << endl;
    for (auto& storedObject : storedObjects) {
                cout<< "Object here" << endl;
            }
    exhibitsMap[this->getSerialNum()] = *this;
    GenericAPI<Exhibit>::resourceMap = exhibitsMap;
    saveToFile<Exhibit>(GenericAPI<Exhibit>::resourceMap, "exhibits.json");
    return true;
}

bool Exhibit::removeObject(Object& object)
{
    string serialNumber = object.getSerialNum();
    int i = 0;
    for (auto& storedObject : storedObjects) {
        if(serialNumber == storedObject.getSerialNum())
        {
            storedObjects.erase(storedObjects.begin()+i);
        }
        i++;
        }
    return true;
}

bool Exhibit::addArtwork(Artwork& object)
{
    if(!objectExists(object))
    {
        return false;
    }
    string serialNumber = object.getSerialNum();
    for (auto& storedArtwork : storedArtworks)
    {
        if(serialNumber == storedArtwork.getSerialNum())
        {
            return false;
        } 
    }
    //add the object to the back
    storedArtworks.push_back(object);
    return true;
    

}

bool Exhibit::removeArtwork(Artwork& object)
{
    string serialNumber = object.getSerialNum();
    int i = 0;
    for (auto& storedArtwork : storedArtworks) {
        if(serialNumber == storedArtwork.getSerialNum())
        {
            storedArtworks.erase(storedArtworks.begin()+i);
        }
        i++;
        }
    return true;
}

bool Exhibit::addGemstone(Gemstone& object)
{
    if(!objectExists(object))
    {
        return false;
    }
    string serialNumber = object.getSerialNum();
    for (auto& storedGemstone : storedGemstones)
    {
        if(serialNumber == storedGemstone.getSerialNum())
        {
            return false;
        } 
    }
    //add the object to the back
    storedGemstones.push_back(object);
    return true;
    

}

bool Exhibit::removeGemstone(Gemstone& object)
{
    string serialNumber = object.getSerialNum();
    int i = 0;
    for (auto& storedGemstone : storedGemstones) {
        if(serialNumber == storedGemstone.getSerialNum())
        {
            storedGemstones.erase(storedGemstones.begin()+i);
        }
        i++;
        }
    return true;
}