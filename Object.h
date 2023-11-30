#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <vector>
using namespace std;
 
class Object
{
public:
    Object();
    Object(string location, string donor, string dateRetrieved, int weight, int serialNum)
        : location(location), donor(donor), dateRetrieved(dateRetrieved), weight(weight), serialNum(serialNum) { } 
    string moveObjects(string loc);
    string getLocation();
    string getDonor();
    string getDateRetrieved();
    int getWeight();
    int getSerialNumber();
    bool compare(Object)


private:
    string location;
    string donor;
    string dateRetrieved;
    int weight; 
    int serialNum;
 



};

#endif