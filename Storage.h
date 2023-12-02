#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <iostream>
#include <crow.h>
#include "Object.h"
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
    bool addObject(Object& object);
    bool removeObject(Object& object);
    bool isEmpty();
    string getSerialNum() const {return serialNum; }
    void setSerialNum(string newSerialNum) 
    {
        serialNum = newSerialNum;
    }
    vector<Object> getStoredObjects() const {return storedObjects;}

    //bool objectExists();

    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);
private:
    string storageName;
    string serialNum;
    vector<Object> storedObjects;
};

#endif