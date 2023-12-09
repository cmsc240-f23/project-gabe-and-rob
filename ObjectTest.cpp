#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "GenericAPI.h"
#include "Exhibit.h"
#include "Storage.h"
#include "Object.h"
#include "Gemstone.h"
#include "Artwork.h"

using namespace std;  
using namespace crow;

map<std::string, Object> objectsMap;
map<std::string, Gemstone> gemstonesMap;
map<std::string, Artwork> artworksMap;
map<std::string, Exhibit> exhibitsMap;
map<std::string, Storage> storagesMap;

TEST_CASE("Test Object Class")
{

    //Testing Object constructor
    SUBCASE("Testing the Object constructor")
    {
        //create new Object class loaded from json
        Object testObject(json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})"));

        //Check that the constructor properly loaded the value
        CHECK(testObject.getDateRetrieved() == "N/A");
        CHECK(testObject.getWeight() == "32 Lbs");
        CHECK(testObject.getDonor() == "n/A");
        CHECK(testObject.getSerialNum() == "1");
        CHECK(testObject.getLocation() == "Unsorted");
        CHECK(testObject.getName() == "Jane Doe");
    }

    //Testing convertToJson method
    SUBCASE("Testing the convertToJson method")
    {
        //create new Object class loaded from json
        Object testObject(json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})"));

        // Convert the Object class to json using the convertToJson method.
        json::wvalue jsonOutput = testObject.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        //Check the values
        CHECK(jsonReadValue["dateRetrieved"].s() == "N/A");
        CHECK(jsonReadValue["weight"].s() == "32 Lbs");
        CHECK(jsonReadValue["donor"].s() == "n/A");
        CHECK(jsonReadValue["serialNum"].s() == "1");
        CHECK(jsonReadValue["location"].s() == "Unsorted");
        CHECK(jsonReadValue["name"].s() == "Jane Doe");
    }
    //Testing updateFromJson method
    SUBCASE("Testing updateFromJson method")
    {
        //create new Object class loaded from json
        Object testObject(json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})"));

        //Create the updated json
        json::rvalue updateJson = json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})");

        //Update the Object using the updateFromJson method
        testObject.updateFromJson(updateJson);

        //Check the updated values
        CHECK(testObject.getName() == "DummyObject");
        CHECK(testObject.getLocation() == "Unsorted");
        CHECK(testObject.getSerialNum() == "2");
        CHECK(testObject.getDonor() == "n/A");
        CHECK(testObject.getWeight() == "32 Lbs");
        CHECK(testObject.getDateRetrieved() == "N/A");
    }



}