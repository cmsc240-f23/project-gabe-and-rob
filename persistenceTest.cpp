#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Object.h"
#include "Storage.h"
#include "Exhibit.h"
#include "Gemstone.h"
#include "Artwork.h"
#include "GenericAPI.h"
#include "persistence.h"

using namespace std;
using namespace crow;

extern map<std::string, Storage> storagesMap;
extern map<std::string, Exhibit> exhibitsMap;

TEST_CASE("Saving to a file and loading from a file.") 
{
    
    // Load a resources to read.
    map<string, Object> objectsMap;
    objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    objectsMap["3"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"Unsorted","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"})")};
    objectsMap["4"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"Unsorted","weight":"32 Lbs","name":"ObjectToMove","serialNum":"MoveObject1"})")};

    //Load Storage Container
    Storage storage = Storage{json::load(R"("storedGemstones":[],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"3"}.{"serialNum":"MoveObject1"}],"storedArtworks":[],"serialNum":"Unsorted","storageName":"Unsorted"})")};
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
    CHECK(objectsMap.at("4").getSerialNum() == objectsMapLoaded.at("4").getSerialNum()); // Validate the resource content
    CHECK(objectsMap.at("4").getName() == objectsMapLoaded.at("4").getName()); // Validate the resource content
    CHECK(objectsMap.at("4").getDateRetrieved() == objectsMapLoaded.at("4").getDateRetrieved()); // Validate the resource content
    CHECK(objectsMap.at("4").getWeight() == objectsMapLoaded.at("4").getWeight()); // Validate the resource content
    CHECK(objectsMap.at("4").getDonor() == objectsMapLoaded.at("4").getDonor()); // Validate the resource content
    CHECK(objectsMap.at("4").getLocation() == objectsMapLoaded.at("4").getLocation()); // Validate the resource content
}