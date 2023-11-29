#ifndef CROW_FUNCTIONS_H
#define CROW_FUNCTIONS_H

#include <crow.h>
#include <string>

// Functions used to handle POST, GET, PUT, and DELETE requests for the Toppings resource.
crow::response createObject(crow::request req);
crow::response readObject(std::string id);
crow::response readAllObjects(crow::request req);
void updateObject(crow::request req, crow::response& res, std::string id); 
crow::response deleteObject(std::string id);

#endif // TOPPING_FUNCTIONS_H 