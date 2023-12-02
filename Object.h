#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
#include <string>
#include <crow.h>

 
class Object
{
public:
    Object();
    Object(crow::json::rvalue readValueJson);
    // Object(std::string location, std::string donor, std::string dateRetrieved, int weight, int serialNum)
    //     : location(location), donor(donor), dateRetrieved(dateRetrieved), weight(weight), serialNum(serialNum) { } 
    std::string moveObjects(std::string loc);
    std::string getLocation();
    std::string getDonor();
    std::string getDateRetrieved();
    int getWeight();
    std::string getSerialNum();
    std::string getName() const {return name;}
    bool compare(Object& object);

    virtual crow::json::wvalue convertToJson();
    virtual void updateFromJson(crow::json::rvalue readValueJson);

    friend class Storage;
private:
    std::string location;
    std::string donor;
    std::string dateRetrieved;
    int weight; 
    std::string serialNum;
    std::string name;
};

#endif