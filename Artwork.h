#ifndef ARTWORK_H
#define ARTWORK_H

#include <iostream>
#include <crow.h>
#include "Object.h"
using namespace std;

class Artwork
{
public:
    Artwork();
    Artwork(crow::json::rvalue readValueJson);
    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);

    string getArtist();
    string getTypeOfWork();
    string getDateCreated();

private:
    string artist;
    string typeOfWork;
    string dateCreated;



};

#endif