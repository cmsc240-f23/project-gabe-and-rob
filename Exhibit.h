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
    int getID();
    void setID(int newIdNum){idNum = newIdNum;}
 
    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);



private:
    string exhibitName;
    int idNum;
    vector<Object> exhibits;



};

#endif