#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Gemstone.h"

using namespace std;  
using namespace crow; 

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
        Gemstone testGemstone(json::load(R"({"location":"Unsorted","dateRetrieved":"N/A","weight":"31 Lbs","name":"BigRock","donor":"n/A","serialNum":"4","type":"DumbRock","dimensions":"big"})"));


        // Convert the Gemstone class to json using the convertToJson method.
        json::wvalue jsonOutput = testGemstone.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

    }





}