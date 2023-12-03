#include "Storage.h"
#include <algorithm>
#include <iostream>
#include <crow.h>

using namespace std;
using namespace crow;

extern map<std::string, Object> objectsMap;
extern map<std::string, Artwork> artworksMap;
extern map<std::string, Gemstone> gemstonesMap;

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
    
    //Convert objects to json (Save only the ids)
    int index = 0;
    for (Object object : storedObjects) 
    {
        writeJson["storedObjects"][index]["serialNum"] = object.getSerialNum();
        index ++;
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

// Update from JSON
bool Storage::updateFromJson(json::rvalue readValueJson) 
{
    serialNum = readValueJson["serialNum"].s();
    storageName = readValueJson["storageName"].s();

    // Setting Objects
    for (json::rvalue storedObjectReadValueJson: readValueJson["storedObjects"])
    {
        storedObjects.push_back(objectsMap.at(storedObjectReadValueJson["serialNum"].s()));
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

bool Storage::objectExists(Object& object)
{
    string serialNumber = object.getSerialNum();
    for(size_t i = 0; i < storedObjects.size(); i++)
    {
        Object storedObject = storedObjects.at(i);
        if(serialNumber == storedObject.getSerialNum())
        {
            return true;
        }
    }
    return false;
}

bool Storage::addObject(Object& object)
{
    if(!objectExists(object))
    {
        return false;
    }
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

bool Storage::removeObject(Object& object)
{
    string serialNumber = object.getSerialNum();
    int i = 0;
    for (auto& storedObject : storedObjects) {
        if(serialNum == storedObject.getSerialNum())
        {
            storedObjects.erase(storedObjects.begin()+i);
        }
        i++;
        }
    return true;
}

// bool Storage::addArtwork(Artwork& object)
// {
//     if(!objectExists(object))
//     {
//         return false;
//     }
//     string serialNumber = object.getSerialNum();
//     for (auto& storedArtwork : storedArtworks)
//     {
//         if(serialNumber == storedArtwork.getSerialNum())
//         {
//             return false;
//         } 
//     }
//     //add the object to the back
//     storedArtworks.push_back(object);
//     return true;
    

// }

// bool Storage::removeArtwork(Artwork& object)
// {
//     string serialNumber = object.getSerialNum();
//     int i = 0;
//     for (auto& storedArtwork : storedArtworks) {
//         if(serialNum == storedArtwork.getSerialNum())
//         {
//             storedArtworks.erase(storedArtworks.begin()+i);
//         }
//         i++;
//         }
//     return true;
// }

// bool Storage::addGemstone(Gemstone& object)
// {
//     if(!objectExists(object))
//     {
//         return false;
//     }
//     string serialNumber = object.getSerialNum();
//     for (auto& storedGemstone : storedGemstones)
//     {
//         if(serialNumber == storedGemstone.getSerialNum())
//         {
//             return false;
//         } 
//     }
//     //add the object to the back
//     storedGemstones.push_back(object);
//     return true;
    

// }

// bool Storage::removeGemstone(Gemstone& object)
// {
//     string serialNumber = object.getSerialNum();
//     int i = 0;
//     for (auto& storedGemstone : storedGemstones) {
//         if(serialNum == storedGemstone.getSerialNum())
//         {
//             storedGemstones.erase(storedGemstones.begin()+i);
//         }
//         i++;
//         }
//     return true;
// }


