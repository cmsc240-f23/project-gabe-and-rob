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
    bool addObject(vector<Object> stored);
    bool isEmpty();
    bool removeObject(vector<Object> stored);
    int getID();

    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);



private:
    string exhibitName;
    int idNum;
    vector<Object> exhibits;



};

#endif