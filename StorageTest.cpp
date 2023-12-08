#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <algorithm>
#include <string>
#include "Storage.h"

using namespace std;  
using namespace crow;  



TEST_CASE("Testing Storage Class") 
{
    // Testing Storage constructor
    SUBCASE("Testing the Storage Constructor") 
    {
        // Create a new Storage class from json.
        Storage testStorage{json::load(R"({storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","storageName":"Unsorted"})")};

        // Check that the constructor properly loaded the values.
        CHECK(testStorage.getSerialNum() == "Unsorted");
        CHECK(testStorage.getName() == "Unsorted");
        CHECK(testStorage.
        CHECK(testStorage.
        CHECK(testStorage.
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Storage class from json.
        Storage testStorage(json::load(R"({storedGemstones":[{"serialNum":"4"}],"storedObjects":[{"serialNum":"1"},{"serialNum":"2"},{"serialNum":"MoveObject1"}],"storedArtworks":[{"serialNum":"3"}],"serialNum":"Unsorted","storageName":"Unsorted"})"));

        // Convert the Storage class to json using the convertToJson method.
        json::wvalue jsonOutput = testStorage.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["storedGemstones"].s() == "[{"serialNum":"4"}]");
        CHECK(jsonReadValue["storedObjects"].s() == "[{"serialNum":"1"},{"serialNum":"2"}]");
        CHECK(jsonReadValue["storedArtworks"].s() == "[{"serialNum":"3"}]"
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Storage class from json.
        Storage testStorage(json::load(R"({"Storage":"Rock","id":"1"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"Storage":"Jazz","id":"2"})");

        // Update the Storage with the updateFromJson method. 
        testStorage.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testStorage.getId() == "2");
        CHECK(testStorage.getStorage() == "Jazz");
    }
}