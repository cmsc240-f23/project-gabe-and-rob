#ifndef ARTWORK_H
#define ARTWORK_H

#include <iostream>
#include "Objects.h"
using namespace std;

class Artwork
{
public:
    Artwork();
    string getArtist();
    string getTypeOfWork();
    string getDateCreated();

private:
    string artist;
    string typeOfWork;
    string dateCreated;



};

#endif