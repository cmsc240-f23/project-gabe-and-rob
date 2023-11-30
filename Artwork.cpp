#include "Artwork.h"
#include <iostream>

using namespace std;

Artwork(){}

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