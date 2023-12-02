#ifndef EXHIBIT_H
#define EXHIBIT_H
#include <iostream>
#include <vector>
#include <crow.h>
#include "Object.h"
using namespace std;

class Exhibit
{ 
public:
    Exhibit();
    Exhibit(crow::json::rvalue readValueJson);
    string getExhibitName();
    void setExhibitName(string newExhibitName){exhibitName = newExhibitName;}
    bool addObject(Object& object);
    bool isEmpty();
    bool removeObject(Object& object);
    string getSerialNum(){return serialNum;}
    void setSerialNum(string newIdNum){serialNum = newIdNum;}
 
    crow::json::wvalue convertToJson();
    bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Artwork;
    friend class Gemstone;
    friend class Object;
private:
    string exhibitName;
    string serialNum;
    vector<Object> storedObjects;



};

#endif