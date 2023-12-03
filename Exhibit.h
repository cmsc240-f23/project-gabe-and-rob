#ifndef EXHIBIT_H
#define EXHIBIT_H
#include <iostream>
#include <vector>
#include <crow.h>
#include "Object.h"
#include "Artwork.h"
#include "Gemstone.h"
using namespace std;

class Exhibit
{ 
public:
    Exhibit();
    Exhibit(crow::json::rvalue readValueJson);
    string getExhibitName();
    void setExhibitName(string newExhibitName){exhibitName = newExhibitName;}
    bool addToExhibit(string serialNum);
    bool removeFromExhibit(string serialNum);
    bool addObject(Object& object);
    bool removeObject(Object& object);
    bool addArtwork(Artwork& object);
    bool removeArtwork(Artwork& object);
    bool addGemstone(Gemstone& object);
    bool removeGemstone(Gemstone& object);
    bool isEmpty();
    string getSerialNum(){return serialNum;}
    void setSerialNum(string newIdNum){serialNum = newIdNum;}

    bool objectExists(Object& object) const {return true;}
 
    crow::json::wvalue convertToJson();
    bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Artwork;
    friend class Gemstone;
    friend class Object;
private:
    string exhibitName;
    string serialNum;
    vector<Object> storedObjects;
    vector<Artwork> storedArtworks;
    vector<Gemstone> storedGemstones;

};

#endif