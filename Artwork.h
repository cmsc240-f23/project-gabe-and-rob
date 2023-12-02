#ifndef ARTWORK_H
#define ARTWORK_H

#include <iostream>
#include "Object.h"
#include <crow.h>
using namespace std;

class Artwork : public Object 
{
public:
    Artwork();
    Artwork(crow::json::rvalue readValueJson);
    string getArtist();
    void setArtist(string newArtist){artist = newArtist;}
    string getTypeOfArtwork();
    void setTypeOfArtWork(string newTypeOfWork){typeOfWork = newTypeOfWork;}
    string getDateCreated();
    void setDateCreated(string newDateCreated){dateCreated = newDateCreated;}

    virtual bool compare(Object& object);

    virtual crow::json::wvalue convertToJson();
    virtual void updateFromJson(crow::json::rvalue readValueJson);



private:
    string artist;
    string typeOfWork;
    string dateCreated;
};

#endif