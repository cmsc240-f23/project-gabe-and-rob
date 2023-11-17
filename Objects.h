#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <vector>
using namespace std;
 
class Objects
{
public:
    Objects() {}
    Objects(string location, string donor, string dateRetrieved, int weight, int serialNum)
        : location(location), donor(donor), dateRetrieved(dateRetrieved), weight(weight), serialNum(serialNum) { } 
    string moveObjects(string loc);
    string getLocation() {return location;}
    string getDonor() {return donor;}
    string getDateRetrieved() {return dateRetrieved;}
    int getWeight() {return weight;}
    int getSerialNumber() {return serialNum;}


private:
    string location;
    string donor;
    string dateRetrieved;
    int weight; 
    int serialNum;
 



};

#endif