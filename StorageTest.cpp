#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <algorithm>
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

    // Testing Storage constructor
    TEST_CASE("Testing the Storage Constructor") 
    {
        // //Create objects for storage
        Object object1{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        Object object2{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        vector<Object> objectVector = {object1, object2};
        Artwork artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        vector<Artwork> artworkVector = {artwork};
        Gemstone gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        vector<Gemstone> gemstoneVector = {gemstone};
        objectsMap["1"] = object1;
        objectsMap["2"] = object2;
        artworksMap["3"] = artwork;
        gemstonesMap["4"] = gemstone;
        // Create a new Storage class from json.
        Storage testStorage{json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","storageName":"Unsorted"})")};

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check that the constructor properly loaded the values.
        CHECK(testStorage.getSerialNum() == "Unsorted");
        CHECK(testStorage.getStorageName() == "Unsorted");
        CHECK(jsonReadValue["storedGemstones"].s() == "[{serialNum:4}]");
        CHECK(jsonReadValue["storedObjects"].s() == "[{serialNum:1},{serialNum:2}]");
        CHECK(jsonReadValue["storedArtworks"].s() == "[{serialNum:3}]");
    }

    // Testing convertToJson method
    TEST_CASE("Testing the convertToJson Method") 
    {
        Object object1{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        Object object2{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        vector<Object> objectVector = {object1, object2};
        Artwork artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        vector<Artwork> artworkVector = {artwork};
        Gemstone gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        vector<Gemstone> gemstoneVector = {gemstone};
        objectsMap["1"] = object1;
        objectsMap["2"] = object2;
        artworksMap["3"] = artwork;
        gemstonesMap["4"] = gemstone;
        // Create a new Storage class from json.
        Storage testStorage(json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","storageName":"Unsorted"})"));

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["storedGemstones"].s() == "[{serialNum:4}]");
        CHECK(jsonReadValue["storedObjects"].s() == "[{serialNum:1},{serialNum:2}]");
        CHECK(jsonReadValue["storedArtworks"].s() == "[{serialNum:3}]");
        CHECK(jsonReadValue["storageName"].s() == "Unsorted");
        CHECK(jsonReadValue["serialNum"].s() == "Unsorted");
    }

    // Testing updateFromJson method
    TEST_CASE("Testing updateFromJson Method") 
    {
        //Create objects for storage
        Object object1{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        Object object2{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        vector<Object> objectVector = {object1, object2};
        Artwork artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        vector<Artwork> artworkVector = {artwork};
        Gemstone gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        vector<Gemstone> gemstoneVector = {gemstone};
        objectsMap["1"] = object1;
        objectsMap["2"] = object2;
        artworksMap["3"] = artwork;
        gemstonesMap["4"] = gemstone;
        // Create a new Storage class from json.
        Storage testStorage{json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","storageName":"Unsorted"})")};

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Jazz","storageName":"Jazz"}))");

        // Update the Storage with the updateFromJson method. 
        testStorage.updateFromJson(updateJson);

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the updated values.
        CHECK(testStorage.getStorageName() == "Jazz");
        CHECK(testStorage.getSerialNum() == "Jazz");
        CHECK(jsonReadValue["storedGemstones"].s() == "[{serialNum:4}]");
        CHECK(jsonReadValue["storedObjects"].s() == "[{serialNum:1},{serialNum:2}]");
        CHECK(jsonReadValue["storedArtworks"].s() == "[{serialNum:3}]");
    }