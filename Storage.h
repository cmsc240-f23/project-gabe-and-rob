#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <iostream>
#include "Object.h"
using namespace std;

class Storage
{
public:
    Storage();
    Storage(crow::json::rvalue readValueJson);

    string getStorageName() const {return storageName; }
    bool objectExists(vector<Objects> object);
    bool addObject(vector<Objects> object);
    bool removeObject(vector<Objects> object);
    bool isEmpty();
    int getID() const {return id; }

private:
    string storageName;
    string id;
    vector<Objects> storedObject;
    


};

#endif