#ifndef STORAGES_H
#define STORAGES_H

#include <vector>
#include <iostream>
#include "Objects.h"
using namespace std;

class Storages
{
public:
    Storages();
    string getStorageName();
    bool objectExists(vector<Objects> object);
    bool addObject(vector<Objects> object);
    bool removeObject(vector<Objects> object);
    bool isEmpty();
    int getID();

private:
    string storageName;
    int idNum;
    vector<Objects> storedObject;
    


};

#endif