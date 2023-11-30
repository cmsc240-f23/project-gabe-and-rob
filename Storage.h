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
    bool objectExists(vector<Object> object);
    bool addObject(vector<Object> object);
    bool removeObject(vector<Object> object);
    bool isEmpty();
    string getID() const {return id; }

    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);
private:
    string storageName;
    string id;
    vector<Object> storedObject;
    


};

#endif