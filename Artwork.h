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
    string getArtist(){return artist;}
    void setArtist(string newArtist){artist = newArtist;}
    string getTypeOfArtwork();
    void setTypeOfArtWork(string newTypeOfWork){typeOfWork = newTypeOfWork;}
    string getDateCreated();
    void setDateCreated(string newDateCreated){dateCreated = newDateCreated;}

    crow::json::wvalue convertToJson();
    bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Storage;
    friend class Exhibit;
private:
    string artist;
    string typeOfWork;
    string dateCreated;
};

#endif