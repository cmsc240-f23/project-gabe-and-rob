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

TEST_CASE("Testing Gemstone class")
{
    //Testing Gemtone constructor
    SUBCASE("Testing the Gemstone constructor")
    {
        //Create a new Gemstone class from json
        Gemstone testGemstone(json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})"));

        //Check that the constructor properly loaded the values
        CHECK(testGemstone.getType() == "Dumbrock");
        CHECK(testGemstone.getDimensions() == "big");
       
    }

    //Testing convertToJson method
    SUBCASE("Testing the convertToJson method")
    {
        //Create a new Gemstone class from json
        Gemstone testGemstone(json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})"));


        // Convert the Gemstone class to json using the convertToJson method.
        json::wvalue jsonOutput = testGemstone.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["type"].s() == "Dumbrock");
        CHECK(jsonReadValue["dimensions"].s() == "big");

    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method")
    {
        //Create a new Gemstone class from json
        Gemstone testGemstone(json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"dimensions":"medium","type":"Amethyst","serialNum":"5","name":"BiggerRock","weight":"47 Lbs","location":"DummyExhibit","donor":"n/A","dateRetrieved":"N/A"})");


        // Update the Gemstone with the updateFromJson method. 
        testGemstone.updateFromJson(updateJson);

        //Check the updated values
        CHECK(testGemstone.getType() == "Amethyst");
        CHECK(testGemstone.getDimensions() == "medium");

    }


    // SUBCASE("Checking errors")
    // {
    //     //Testing an ivalid json Gemstone without location
        

    //     response res = response(400, "Invalid JSON");

    //     CHECK(Gemstone testGemstone(json::load(R"({"dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})")) ==  res);


    // }





}