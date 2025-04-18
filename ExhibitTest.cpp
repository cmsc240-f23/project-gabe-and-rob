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
    TEST_CASE("Testing the Exhibit Constructor") 
    {
        //Create objects for Exhibit
        objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        artworksMap["3"] = Artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        gemstonesMap["4"] = Gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        //Create a new Storage class from json.
        Exhibit testStorage{json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"}],"storedArtworks":[{"serialNum":"3"}],"exhibitName":"Unsorted","serialNum":"Unsorted"})")};

         // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check that the constructor properly loaded the values.
        CHECK(testStorage.getSerialNum() == "Unsorted");
        CHECK(testStorage.getExhibitName() == "Unsorted");
        crow::json::rvalue objectReadValueJson = jsonReadValue["storedObjects"][0];
        CHECK(objectReadValueJson["serialNum"].s() == "1");
        crow::json::rvalue objectReadValueJson2 = jsonReadValue["storedObjects"][1];
        CHECK(objectReadValueJson2["serialNum"].s() == "2");
        crow::json::rvalue artworkReadValueJson = jsonReadValue["storedArtworks"][0];
        CHECK(artworkReadValueJson["serialNum"].s() == "3");
        crow::json::rvalue gemstoneReadValueJson = jsonReadValue["storedGemstones"][0];
        CHECK(gemstoneReadValueJson["serialNum"].s() == "4");
    }

    // Testing convertToJson method
    TEST_CASE("Testing the convertToJson Method") 
    {
        //Create objects for Exhibit
        objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        artworksMap["3"] = Artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        gemstonesMap["4"] = Gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        //Create a new Storage class from json.
        Exhibit testStorage(json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","exhibitName":"Unsorted"})"));

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        crow::json::rvalue objectReadValueJson = jsonReadValue["storedObjects"][0];
        CHECK(objectReadValueJson["serialNum"].s() == "1");
        crow::json::rvalue objectReadValueJson2 = jsonReadValue["storedObjects"][1];
        CHECK(objectReadValueJson2["serialNum"].s() == "2");
        crow::json::rvalue artworkReadValueJson = jsonReadValue["storedArtworks"][0];
        CHECK(artworkReadValueJson["serialNum"].s() == "3");
        crow::json::rvalue gemstoneReadValueJson = jsonReadValue["storedGemstones"][0];
        CHECK(gemstoneReadValueJson["serialNum"].s() == "4");
        CHECK(jsonReadValue["exhibitName"].s() == "Unsorted");
        CHECK(jsonReadValue["serialNum"].s() == "Unsorted");
    }

    // Testing updateFromJson method
    TEST_CASE("Testing updateFromJson Method") 
    {
        //Create objects for Exhibit
        objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
        objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
        artworksMap["3"] = Artwork{json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})")};
        gemstonesMap["4"] = Gemstone{json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")};
        //Create a new Storage class from json.
        Exhibit testStorage(json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","exhibitName":"Unsorted"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Jazz","exhibitName":"Jazz"})");

        // Update the Storage with the updateFromJson method. 
        testStorage.updateFromJson(updateJson);

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());


        // Check the updated values.
        CHECK(testStorage.getExhibitName() == "Jazz");
        CHECK(testStorage.getSerialNum() == "Jazz");
        crow::json::rvalue objectReadValueJson = jsonReadValue["storedObjects"][0];
        CHECK(objectReadValueJson["serialNum"].s() == "1");
        crow::json::rvalue objectReadValueJson2 = jsonReadValue["storedObjects"][1];
        CHECK(objectReadValueJson2["serialNum"].s() == "2");
        crow::json::rvalue artworkReadValueJson = jsonReadValue["storedArtworks"][0];
        CHECK(artworkReadValueJson["serialNum"].s() == "3");
        crow::json::rvalue gemstoneReadValueJson = jsonReadValue["storedGemstones"][0];
        CHECK(gemstoneReadValueJson["serialNum"].s() == "4");
    }