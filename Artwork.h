#ifndef ARTWORK_H
#define ARTWORK_H

#include <iostream>
#include "Object.h"
#include <crow.h>
using namespace std;

class Artwork : private Object 
{
public:
    Artwork();
    Artwork(crow::json::rvalue readValueJson);
    string getArtist();
    string getTypeOfWork();
    string getDateCreated();

    virtual bool compare(Object& object);

    virtual crow::json::wvalue convertToJson();
    virtual void updateFromJson(crow::json::rvalue readValueJson);



private:
    string artist;
    string typeOfWork;
    string dateCreated;
};

#endif