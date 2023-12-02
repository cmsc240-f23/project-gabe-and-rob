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
    void moveObjects(std::string newLocation){location = newLocation;}
    std::string getLocation();
    std::string getDonor();
    void setDonor(std::string newDonor){donor = newDonor;}
    std::string getDateRetrieved();
    void setDateRetrieved(std::string newDateRetrieved){dateRetrieved = newDateRetrieved;}
    int getWeight();
    void setWeight(int newWeight){weight = newWeight;}
    std::string getSerialNum();
    std::string getName() const {return name;}
    void setName(std::string new_name) {name = new_name;}
    void setSerialNum(std::string newSerialNum){serialNum = newSerialNum;}
    virtual bool compare(Object& object);

    virtual crow::json::wvalue convertToJson();
    virtual bool updateFromJson(crow::json::rvalue readValueJson);

    friend class Storage;
    friend class Exhibit;
private:
    std::string location;
    std::string donor;
    std::string dateRetrieved;
    int weight; 
    std::string serialNum;
    std::string name;
};

#endif