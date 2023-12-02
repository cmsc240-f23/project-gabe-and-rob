#include <crow.h>
#include <map>
#include <csignal>
#include <string>
#include "Artwork.h"
//#include "Exhibit.h"
#include "Gemstone.h"
#include "GenericAPI.h"
#include "persistence.h"
#include "Storage.h"
#include "Object.h"

using namespace crow;
using namespace std;

// Load resources from files.
//map<std::string, Exhibit> exhibitsMap = loadFromFile<Exhibit>("exhibits.json");
map<std::string, Storage> storagesMap = loadFromFile<Storage>("storages.json");
map<std::string, Object> objectsMap = loadFromFile<Object>("objects.json");
map<std::string, Gemstone> gemstonesMap = loadFromFile<Gemstone>("gemstones.json");
map<std::string, Artwork> artworksMap = loadFromFile<Artwork>("artworks.json");

int main(){
    // Create GenericAPIs to use in the CROW_ROUTES
    //GenericAPI<Exhibit>::resourceMap = exhibitsMap;
    GenericAPI<Storage>::resourceMap = storagesMap;
    GenericAPI<Object>::resourceMap = objectsMap;
    GenericAPI<Gemstone>::resourceMap = gemstonesMap;
    GenericAPI<Artwork>::resourceMap = artworksMap;

    // Setup the simple web service.
    SimpleApp app;

    // Exhibits
    // CROW_ROUTE(app, "/api/exhibits").methods("POST"_method)(GenericAPI<Exhibit>::createResource);
    // CROW_ROUTE(app, "/api/exhibits").methods("GET"_method)(GenericAPI<Exhibit>::readAllResources);
    // CROW_ROUTE(app, "/api/exhibits/<string>").methods("GET"_method)(GenericAPI<Exhibit>::readResource);
    // CROW_ROUTE(app, "/api/exhibits/<string>").methods("PUT"_method)(GenericAPI<Exhibit>::updateResource);
    // CROW_ROUTE(app, "/api/exhibits/<string>").methods("DELETE"_method)(GenericAPI<Exhibit>::deleteResource);

    // Objects
    CROW_ROUTE(app, "/api/objects").methods("POST"_method)(GenericAPI<Object>::createResource);
    CROW_ROUTE(app, "/api/objects").methods("GET"_method)(GenericAPI<Object>::readAllResources);
    CROW_ROUTE(app, "/api/objects/<string>").methods("GET"_method)(GenericAPI<Object>::readResource);
    CROW_ROUTE(app, "/api/objects/<string>").methods("PUT"_method)(GenericAPI<Object>::updateResource);
    CROW_ROUTE(app, "/api/objects/<string>").methods("DELETE"_method)(GenericAPI<Object>::deleteResource);

    // storages
    CROW_ROUTE(app, "/api/storages").methods("POST"_method)(GenericAPI<Storage>::createResource);
    CROW_ROUTE(app, "/api/storages").methods("GET"_method)(GenericAPI<Storage>::readAllResources);
    CROW_ROUTE(app, "/api/storages/<string>").methods("GET"_method)(GenericAPI<Storage>::readResource);
    CROW_ROUTE(app, "/api/storages/<string>").methods("PUT"_method)(GenericAPI<Storage>::updateResource);
    CROW_ROUTE(app, "/api/storages/<string>").methods("DELETE"_method)(GenericAPI<Storage>::deleteResource);

    // gemstones
    CROW_ROUTE(app, "/api/gemstones").methods("POST"_method)(GenericAPI<Gemstone>::createResource);
    CROW_ROUTE(app, "/api/gemstones").methods("GET"_method)(GenericAPI<Gemstone>::readAllResources);
    CROW_ROUTE(app, "/api/gemstones/<string>").methods("GET"_method)(GenericAPI<Gemstone>::readResource);
    CROW_ROUTE(app, "/api/gemstones/<string>").methods("PUT"_method)(GenericAPI<Gemstone>::updateResource);
    CROW_ROUTE(app, "/api/gemstones/<string>").methods("DELETE"_method)(GenericAPI<Gemstone>::deleteResource);

    // // Artworks
    CROW_ROUTE(app, "/api/artworks").methods("POST"_method)(GenericAPI<Artwork>::createResource);
    CROW_ROUTE(app, "/api/artworks").methods("GET"_method)(GenericAPI<Artwork>::readAllResources);
    CROW_ROUTE(app, "/api/artworks/<string>").methods("GET"_method)(GenericAPI<Artwork>::readResource);
    CROW_ROUTE(app, "/api/artworks/<string>").methods("PUT"_method)(GenericAPI<Artwork>::updateResource);
    CROW_ROUTE(app, "/api/artworks/<string>").methods("DELETE"_method)(GenericAPI<Artwork>::deleteResource);

    // Run the web service app.
    app.port(17953).run();

    // Perform persistence of resources
    //saveToFile<Exhibit>(GenericAPI<Exhibit>::resourceMap, "exhibits.json");
    saveToFile<Storage>(GenericAPI<Storage>::resourceMap, "storages.json");
    saveToFile<Object>(GenericAPI<Object>::resourceMap, "objects.json");
    saveToFile<Gemstone>(GenericAPI<Gemstone>::resourceMap, "gemstones.json");
    saveToFile<Artwork>(GenericAPI<Artwork>::resourceMap, "artwork.json");

}