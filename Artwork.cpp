#include "Artwork.h"
#include <crow.h>
#include <iostream>

using namespace std;
using namespace crow;


Artwork::Artwork(){}

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

void Artwork::updateFromJson(json::rvalue readValueJson)
{
    Object::updateFromJson(readValueJson); 
    artist = readValueJson["artist"].s();
    typeOfWork = readValueJson["typeOfWork"].s();
    dateCreated = readValueJson["dateCreated"].s();
}

bool compare()
{
    return true;
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