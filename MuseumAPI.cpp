#include <crow.h>
#include <map>
#include <csignal>
#include <string>
#include "Artwork.h"
#include "CrowFunctions.h"
#include "Exhibits.h"
#include "Gemstones.h"
#include "GenericAPI.h"
#include "persistence.h"
#include "Storages.h"
#include "Objects.h"

using namespace crow;
using namespace std;

// Load resources from files.
map<std::string, Exhibit> genresMap = loadFromFile<Exhibit>("exhibits.json");
map<std::string, Storage> artistsMap = loadFromFile<Storage>("storages.json");
map<std::string, Object> recordsMap = loadFromFile<Object>("objects.json");

int main(){
    // Create GenericAPIs to use in the CROW_ROUTES
    GenericAPI<Exhibit>::resourceMap = exhibitsMap;
    GenericAPI<Storage>::resourceMap = storagesMap;
    GenericAPI<Object>::resourceMap = objectsMap;

    // Setup the simple web service.
    SimpleApp app;


    // Run the web service app.
    app.port(17953).run();

    // Perform persistence of resources
    saveToFile<Exhibit>(GenericAPI<Exhibit>::resourceMap, "exhibits.json");
    saveToFile<Storage>(GenericAPI<Storage>::resourceMap, "storages.json");
    saveToFile<Object>(GenericAPI<Object>::resourceMap, "objects.json");

}