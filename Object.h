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
    bool compare(Object& object);

    crow::json::wvalue convertToJson();
    void updateFromJson(crow::json::rvalue readValueJson);

private:
    std::string location;
    std::string donor;
    std::string dateRetrieved;
    int weight; 
    std::string serialNum;
 



};

#endif