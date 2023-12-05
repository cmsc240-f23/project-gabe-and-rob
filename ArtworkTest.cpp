#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Artwork.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Artwork class")
{

    //Testing Artwork constructor
    SUBCASE("Testing the Artwork constructor")
    {
        // Create a new Artwork class from json.
        Artwork testArtwork(json::load(R"({"location":"DummyExhibit","dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"2","typeOfWork":"Painting","name":"Jane Doe","artist":"Picasso","dateCreated":"12-1-2023"})"));

        //Check that the constructor properly loaded the values
        CHECK(testArtwork.getArtist() == "Picasso");
        CHECK(testArtwork.getTypeOfArtwork() == "Painting");
        CHECK(testArtwork.getDateCreated() == "12-1-2023");

    }

    //Testing convertToJson method
    SUBCASE("Testing the convertToJson method")
    {
        // Create a new Artwork class from json.
        Artwork testArtwork(json::load(R"({"location":"DummyExhibit","dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"2","typeOfWork":"Painting","name":"Jane Doe","artist":"Picasso","dateCreated":"12-1-2023"})"));

        // Convert the Artwork class to json using the convertToJson method.
        json::wvalue jsonOutput = testArtwork.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["artist"].s() == "Picasso");
        CHECK(jsonReadValue["typeOfWork"].s() == "Painting");
        CHECK(jsonReadValue["dateCreated"].s() == "12-1-2023");
        //check the other values that are not in the Artwork class
        CHECK(jsonReadValue["weight"].s() == "32 Lbs");
        CHECK(jsonReadValue["location"].s() == "DummyExhibit");
        CHECK(jsonReadValue["name"].s() == "Jane Doe");
        CHECK(jsonReadValue["dateRetrieved"].s() == "N/A");
        CHECK(jsonReadValue["donor"].s() == "n/A");
        CHECK(jsonReadValue["serialNum"].s() == "2");
        
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method")
    {
        // Create a new Artwork class from json.
        Artwork testArtwork(json::load(R"({"location":"DummyExhibit","dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"2","typeOfWork":"Painting","name":"Jane Doe","artist":"Picasso","dateCreated":"12-1-2023"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"dateCreated":"10-12-13","typeOfWork":"Song","artist":"BlueManGroup","serialNum":"3","name":"John Doe","weight":"12 Lbs","location":"Unsorted","donor":"n/A","dateRetrieved":"N/A"})");

        // Update the Artwork with the updateFromJson method. 
        testArtwork.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testArtwork.getArtist() == "BlueManGroup");
        CHECK(testArtwork.getTypeOfArtwork() == "Song");
        CHECK(testArtwork.getDateCreated() == "10-12-13");

    }







}