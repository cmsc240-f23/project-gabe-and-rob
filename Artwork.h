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
    string getTypeOfArtwork();
    string getDateCreated();

    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);



private:
    string artist;
    string typeOfWork;
    string dateCreated;
};

#endif