#ifndef OBJECTS_H
#define OBJECTS_H
#include <iostream>
#include <vector>
using namespace std;

class Objects
{
public:
    Objects();
    string moveObjects(string loc);
    string getLocation();
    string getDonor();
    string getDateRetrieved();
    int getWeight();
    int getSerialNumber();


private:
    int serialNum;
    string location;
    string donor;
    string dateRetrieved;
    int weight;




};

#endif