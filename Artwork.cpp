#include "Artwork.h"
#include <crow.h>
#include <iostream>

using namespace std;
using namespace crow;

Artwork::Artwork(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}


crow::json::wvalue Artwork::convertToJson()
{
    json::wvalue writeJson = Object::convertToJson();
    writeJson["artist"]= artist;
    writeJson["typeOfWork"]= typeOfWork;
    writeJson["dateCreated"] = dateCreated; 
    return writeJson;
}

bool Artwork::updateFromJson(json::rvalue readValueJson)
{
    if(Object::updateFromJson(readValueJson))
    {
        artist = readValueJson["artist"].s();
        typeOfWork = readValueJson["typeOfWork"].s();
        dateCreated = readValueJson["dateCreated"].s();
        return true;
    }
    else
    {
        return false;
    }
}


string Artwork::getArtist()
{
    return artist;
}

string Artwork::getTypeOfArtwork()
{
    return typeOfWork;
}

string Artwork::getDateCreated()
{
    return dateCreated;
}