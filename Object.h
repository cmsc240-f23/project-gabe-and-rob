#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include <string>

 
class Object
{
public:
    Object();
    Object(std::string location, std::string donor, std::string dateRetrieved, int weight, int serialNum)
        : location(location), donor(donor), dateRetrieved(dateRetrieved), weight(weight), serialNum(serialNum) { } 
    std::string moveObjects(std::string loc);
    std::string getLocation();
    std::string getDonor();
    std::string getDateRetrieved();
    int getWeight();
    int getSerialNumber();
    bool compare(Object& object);


private:
    std::string location;
    std::string donor;
    std::string dateRetrieved;
    int weight; 
    int serialNum;
 



};

#endif