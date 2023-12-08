#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "GenericAPI.h"
#include "Artwork.h"
#include "Gemstone.h"
#include "Exhibit.h"
#include "Storage.h"
#include "Object.h"

using namespace std;  
using namespace crow;  

map<std::string, Object> objectsMap;
map<std::string, Gemstone> gemstonesMap;
map<std::string, Artwork> artworksMap;
map<std::string, Exhibit> exhibitsMap;
map<std::string, Storage> storagesMap;


 
TEST_CASE("Creating New Object Resource") 
{
    //clear resource map before test
    GenericAPI<Object>::resourceMap.clear();

    //setup request object
    request req;
    req.body = R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})";
    
    // Perform the action
    response res = GenericAPI<Object>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(GenericAPI<Object>::resourceMap.size() == 1); // Ensure the resource was added to the map
    CHECK(GenericAPI<Object>::resourceMap.at("2").getSerialNum() == "2"); // Validate the resource content
    CHECK(GenericAPI<Object>::resourceMap.at("2").getLocation() == "Unsorted"); // Validate the resource content
    CHECK(GenericAPI<Object>::resourceMap.at("2").getDonor() == "N/A");
    CHECK(GenericAPI<Object>::resourceMap.at("2").getWeight() == "32");
    CHECK(GenericAPI<Object>::resourceMap.at("2").getName() == "DummyObject"); 
    CHECK(GenericAPI<Object>::resourceMap.at("2").getDateRetrieved() == "N/A");
}   

TEST_CASE("Reading from an Object")
{
    // Load a resource to read.
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    
    // Setup resource map to be empty before the test
    GenericAPI<Object>::resourceMap = objectsMap;

    // Perform the action
    response res = GenericAPI<Object>::readResource("2");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == objectsMap["2"].convertToJson().dump()); // Validate the reponse body
    CHECK(GenericAPI<Object>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Read All Objects")
{
    // Load a resource to read.
    objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    objectsMap["3"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"DummyExhibit","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Object>::resourceMap = objectsMap;

    // Perform the action
    response res = GenericAPI<Object>::readAllResources();

    string expectedResponseBody = R"([{"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"},{"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"},{"dateRetrieved":"N/A","donor":"n/A","location":"DummyExhibit","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(GenericAPI<Object>::resourceMap.size() == 3); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Updating an Object Resource")
{
    // Load resources to update.
    // Load a resource to read.
    objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    objectsMap["3"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"DummyExhibit","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"})")};

    storagesMap["Dummy"] = Storage{json::load(R"({"storedGemstones":[],"storedObjects":[],"storedArtworks":[],"serialNum":"Dummy","storageName":"Dummy"})")};
    // Setup resource map to be empty before the test
    GenericAPI<Object>::resourceMap = objectsMap;
    GenericAPI<Storage>::resourceMap = storagesMap;

    // Setup request object
    request req;
    req.body = R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Dummy","name":"John Doe"})"; 

    // Setup a response object
    response res;

    // Perform the action
    GenericAPI<Object>::updateResource(req, res, "1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(GenericAPI<Object>::resourceMap.size() == 4); // Ensure no resource was added or removed from the map
    CHECK(GenericAPI<Object>::resourceMap.at("2").getSerialNum() == "1"); // Validate the resource content
    CHECK(GenericAPI<Object>::resourceMap.at("2").getLocation() == "Dummy"); // Validate the resource content
    CHECK(GenericAPI<Object>::resourceMap.at("2").getDonor() == "N/A");
    CHECK(GenericAPI<Object>::resourceMap.at("2").getWeight() == "32");
    CHECK(GenericAPI<Object>::resourceMap.at("2").getName() == "John Doe"); 
    CHECK(GenericAPI<Object>::resourceMap.at("2").getDateRetrieved() == "N/A");
    CHECK(GenericAPI<Storage>::resourceMap.at("Dummy"));
}

TEST_CASE("Deleting a Object resource") 
{
    // Load a resources to update.
    objectsMap["1"] = Object{json::load(R"({"dateRetrieved":"N/A","weight":"32 Lbs","donor":"n/A","serialNum":"1","location":"Unsorted","name":"Jane Doe"})")};
    objectsMap["2"] = Object{json::load(R"({"name":"DummyObject","location":"Unsorted","serialNum":"2","donor":"n/A","weight":"32 Lbs","dateRetrieved":"N/A"})")};
    objectsMap["3"] = Object{json::load(R"({"dateRetrieved":"N/A","donor":"n/A","location":"DummyExhibit","weight":"32 Lbs","name":"DummyObject2","serialNum":"3"})")};

    // Setup resource map to be empty before the test
    GenericAPI<Object>::resourceMap = objectsMap;

    // Perform the action
    response res = GenericAPI<Object>::deleteResource("2");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(GenericAPI<Object>::resourceMap.size() == 2); // Ensure one resource was removed from the map
}
