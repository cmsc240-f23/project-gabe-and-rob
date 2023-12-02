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
    string getSerialNum(){return idNum;}
    void setSerialNum(string newIdNum){idNum = newIdNum;}
 
    crow::json::wvalue convertToJson();
    bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Artwork;
    friend class Gemstone;
    friend class Object;
private:
    string exhibitName;
    string idNum;
    vector<Object> storedObjects;



};

#endif