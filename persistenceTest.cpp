#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "persistence.h"
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

TEST_CASE("Saving to a file and loading from a file.") 
{
    
    // Load a resources to read.
    map<string, Object> objectsMap;
    objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"","name":"Jane Doe"})")};
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    objectsMap["3"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"})")};
    
    // Perform the action
    saveToFile<Object>(objectsMap, "persistenceTest.json");
    map<string, Object> objectsMapLoaded = loadFromFile<Object>("persistenceTest.json");

    // Check the results
    CHECK(objectsMap.size() == objectsMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(objectsMap.at("1").getSerialNum() == objectsMapLoaded.at("1").getSerialNum()); // Validate the resource content
    CHECK(objectsMap.at("1").getName() == objectsMapLoaded.at("1").getName()); // Validate the resource content
    CHECK(objectsMap.at("1").getDateRetrieved() == objectsMapLoaded.at("1").getDateRetrieved()); // Validate the resource content
    CHECK(objectsMap.at("1").getWeight() == objectsMapLoaded.at("1").getWeight()); // Validate the resource content
    CHECK(objectsMap.at("1").getDonor() == objectsMapLoaded.at("1").getDonor()); // Validate the resource content
    CHECK(objectsMap.at("1").getLocation() == objectsMapLoaded.at("1").getLocation()); // Validate the resource content
    CHECK(objectsMap.at("2").getSerialNum() == objectsMapLoaded.at("2").getSerialNum()); // Validate the resource content
    CHECK(objectsMap.at("2").getName() == objectsMapLoaded.at("2").getName()); // Validate the resource content
    CHECK(objectsMap.at("2").getDateRetrieved() == objectsMapLoaded.at("2").getDateRetrieved()); // Validate the resource content
    CHECK(objectsMap.at("2").getWeight() == objectsMapLoaded.at("2").getWeight()); // Validate the resource content
    CHECK(objectsMap.at("2").getDonor() == objectsMapLoaded.at("2").getDonor()); // Validate the resource content
    CHECK(objectsMap.at("2").getLocation() == objectsMapLoaded.at("2").getLocation()); // Validate the resource content
    CHECK(objectsMap.at("3").getSerialNum() == objectsMapLoaded.at("3").getSerialNum()); // Validate the resource content
    CHECK(objectsMap.at("3").getName() == objectsMapLoaded.at("3").getName()); // Validate the resource content
    CHECK(objectsMap.at("3").getDateRetrieved() == objectsMapLoaded.at("3").getDateRetrieved()); // Validate the resource content
    CHECK(objectsMap.at("3").getWeight() == objectsMapLoaded.at("3").getWeight()); // Validate the resource content
    CHECK(objectsMap.at("3").getDonor() == objectsMapLoaded.at("3").getDonor()); // Validate the resource content
    CHECK(objectsMap.at("3").getLocation() == objectsMapLoaded.at("3").getLocation()); // Validate the resource content
}