#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <iostream>
#include <crow.h>
#include "Object.h"
#include "Artwork.h"
#include "Gemstone.h"
using namespace std;


class Storage
{
public:
    Storage();
    Storage(crow::json::rvalue readValueJson);

    string getStorageName() const {return storageName; }
    void setStorageName(string newStorageName)
    {
        storageName = newStorageName;
    }
    bool objectExists(Object& object);
    bool addToStorage(string serialNum);
    bool removeFromStorage(string serialNum);
    bool addObject(Object& object);
    bool removeObject(Object& object);
    bool addArtwork(Artwork& object);
    bool removeArtwork(Artwork& object);
    bool addGemstone(Gemstone& object);
    bool removeGemstone(Gemstone& object);
    bool isEmpty();
    string getSerialNum() const {return serialNum; }
    void setSerialNum(string newSerialNum) 
    {
        serialNum = newSerialNum;
    }
    vector<Object> getStoredObjects() const {return storedObjects;}
    vector<Artwork> getStoredArtworks() const {return storedArtworks;}
    vector<Gemstone> getStoredGemstones() const {return storedGemstones;}

    bool objectExists(Object& object) const {return true;}

    crow::json::wvalue convertToJson();
    bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Artwork;
    friend class Gemstone;
    friend class Object;
private:
    string storageName;
    string serialNum;
    vector<Object> storedObjects;
    vector<Artwork> storedArtworks;
    vector<Gemstone> storedGemstones;
};

#endif