#include "Artwork.h"
#include <crow.h>
#include <iostream>

using namespace std;


Artwork::Artwork(){}

Artwork::Artwork(crow::json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}


crow::json::wvalue Artwork::convertToJson()
{
    json::wvalue writeJson;
    writeJson["artist"]= artist;
    writeJson["typeOfWork"]= typeOfWork;
    writeJson["dateCreated"] = dateCreated; 
    return writeJson;
}

void Artwork::updateFromJson(json::rvalue readValueJson)
{
    artist = readValueJson["artist"].s();
    typeOfWork = readValueJson["typeOfWork"].s();
    dateCreated = readValueJson["dateCreated"].s();
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