Scraps: 

[{"StorageName":"Dummy","SerialNum":"Storage1","storedObjects":[],"storedArtworks":[],"storedGemstones":[]}]


# Project Design Document

## Introduction
It's going to be a mock database for the University of Richmond's Harnett museum. It wil allow people to search through different exibits, types of artworks, and things in storage. 

## Background/Context
The University of Richmond doesn't have a comprehensive database for their art museum as we know.

## Stakeholders
UR Museums and student workers of the museums and people who want to browse the catalog.

## Functional Requirements
1. All Users should be able to browse and read information for art pieces and objects in storage in the University musueams. Should be able to store the objects serial number, where it is right now. Description of the object, where it came from, and the condition of the objects. The service shall return a `200 OK` return code.
2. Authorized users should be able to create new objects for artworks, gemstones, exhibits or storage closets. The service will validate the format of data coming in, and check for authorization of the user. It will then return a `201 Created` or `403 Unauthorized`
3. Authorized Users should be able to update objects with new information. The service should be able to identify which characteristics are going to be changed, validate the format of data coming in, and verify that the data is being updated by a authorized user. The Service will return a `200 OK` or `403 Unauthorized` along with a response body containing the new information
4. Authorized Users should be able to delete objects once they leave the University. 
   - The service shall return a `204 No Content` status code upon successful deletion.
   - The service shall return a `403 Forbidden` status code if an unauthorized user attempts to delete a resource.
5. The service shall implement comprehensive error handling to provide meaningful error messages and appropriate HTTP status codes to the client for all failed operations.
   - The service shall return a `404 Not Found` status code when a requested resource cannot be located.
   - The service shall return a `500 Internal Server Error` status code in the event of unexpected server-side errors.

## Use Case Description
Exhibits:
1. Create(POST)
    - As a museum curator, I want to be able to create a new Exhibit and fill it with objects
2. Read (Get)
    - As a person visiting the museum, I want to know the exhibits name, what artworks it holds, and how long it will be there
    - As a curator, I want to know what objects are curently active for organization
3. Update (PUT)
    - As a curator, I want to update information on artworks, such as if I update the object's serial number
4. Delete(DELETE)
    - As a curator, if an object leaves my collection I want to be able to delete it from the records

Storage
1. Create(POST)
    - As a museum curator, I want to be able to create a new Storage Facility and fill it with objects
2. Read (Get)
    - As a curator, I want to know what objects are curently in storage for organization.
3. Update (PUT)
    - As a curator, I want to update information on artworks, such as if I update the object's serial number
4. Delete(DELETE)
    - As a curator, if an object leaves my collection I want to be able to delete it from the records

Artworks
1. Create (POST)
    - As a museum curator, if I get a new artpiece I want to 
    

## List Of Resources
Active exibits: different rooms, vector with what the exhibit holds, exhibit name. 
Generic Object class which would have the serial number, its current location, donor, date of aquisition, and weight. Two different subclasses for object: 
    artworks (variables listed): artist, type of artwork, date created; 
    gem-stones (variables listed): type of gem-stone, and dimensions;
Storage: has a long vector with a catalogue of what object are stored and ordered by serial number, the physical location of the storage unit, and how much capacity it has left?

## List of End Points
**General**
GET
    - api/
    - Description: Print a list of all current storage areas and exhibits
    - Response: 200 OK. with a return list

POST
    - api/
    - Description: Will create a new Gemstone, Artwork, Object, Storage, or Exhibit
    - Response: 201 Created. Returns the created resource

PUT
    - api/
    - Description: Will update the the Gemstone, Artwork, Object, Storage, or Exhibit
    - Response: 200 OK. With a return list

DELETE
    - api/
    - Description: Deletes a resource from the map
    - Response: 204 No Content.

Search
    - api/

**Exhibits**
1. GET
    - api/exhibits
    - Description: Print List of all the Object within the Exhibit, ordered by serial number, along with the exhibit information, including when it is open and where it is located.
    - Response: 200 OK. with a returned list of Objects.

2. GET
    - api/exhibits/{serial #}
    - Description: Return all of the information about a specific object within an exhibit
    - Response: 200 OK. with all the information on a spcific object

3. PUT
    - api/exhibits/<string>
    - Description: Update the exhibit and all of its information
    - Response: 200 OK. Returns the updated list of exhibits

4. POST
    - /api/exhibits
    - Description: Creates a new exhibit for the exhibit list
    - Response: 201 Created. Returns the created exhibit.

5. DELETE
    - /api/exhibits/<string>
    - Description: Delete a specific exhibit from the exhibit list.
    - Response: 204 No Content. Nothing gets returned.

**Storage** 
1. GET
    - api/storages
    - Description: Print List of all the Object within the Storage, ordered by serial number.
    - Response: 200 OK. with a returned list of Objects

2. GET
    - api/storages/{serial #}
    - Description: Return all of the information about a specific object within an exhibit
    - Response: 200 OK, along with a printout of the Object's attributes

3. PUT
    - api/storages/<string>
    - Description: Update the storage room and all of its information
    - Response: 200 OK. Returns the updated list of storages

4. PUT
    - api/storages/<string>/<string>/
    - Description: Will add something to the storage map.
    - Response: 200 OK, along with a printout of the added object to the storage map

5. POST
    - /api/storages
    - Description: Creates a new storage for the storage list
    - Response: 201 Created. Returns the created storage.

6. DELETE
    - /api/exhibits/<string>
    - Description: Delete a specific exhibit from the exhibit list.
    - Response: 204 No Content. Nothing gets returned.

**Object**
1. GET
    - api/object
    - Description: Return all the objects within the Museum's collection, ordered by Serial#
    - Response: 200 OK, along with a list of Objects

2. GET
    - api/object/{serial #}
    - Description: Return all of the information about a specific object within the museum collection

3. PUT
    - api/object/<string>
    - Description: Update the object and all of its information
    - Response: 200 OK. Returns the updated object

4. PUT
    - api/object/<string>/<string>/
    - Description: Moves the object to the storage room.
    - Response: 200 OK, along with a printout of the added object to the storage room

5. POST
    - /api/object
    - Description: Creates a new object for the object list
    - Response: 201 Created. Returns the created object.

6. DELETE
    - /api/object/<string>
    - Description: Delete a specific object from the object list.
    - Response: 204 No Content. Nothing gets returned.

**Artwork** 
1. GET
    - api/artwork
    - Description: Return all the artworks within the Museum's collection, ordered by Serial#
    - Response: 200 OK, along with a list of artworks

2. GET
    - api/artwork/{serial #}
    - Description: Return all of the information about a specific artwork within the museum collection

3. PUT
    - api/artwork/<string>
    - Description: Update the artwork and all of its information
    - Response: 200 OK. Returns the updated artwork

4. PUT
    - api/artwork/<string>/<string>/
    - Description: Moves the artwork to the storage room.
    - Response: 200 OK, along with a printout of the added artwork to the storage room

5. POST
    - /api/artwork
    - Description: Creates a new artwork for the artwork list
    - Response: 201 Created. Returns the created artwork.

6. DELETE
    - /api/artwork/<string>
    - Description: Delete a specific artwork from the object list.
    - Response: 204 No Content. Nothing gets returned.

**Gemstone**
1. GET
    - api/gemstone
    - Description: Return all the gemstones within the Museum's collection, ordered by Serial#
    - Response: 200 OK, along with a list of gemstones

2. GET
    - api/gemstones/{serial #}
    - Description: Return all of the information about a specific gemstone within the museum collection

3. PUT
    - api/gemstone/<string>
    - Description: Update the gemstone and all of its information
    - Response: 200 OK. Returns the updated gemstone

4. PUT
    - api/gemstone/<string>/<string>/
    - Description: Moves the gemstone to the storage room.
    - Response: 200 OK, along with a printout of the added gemstone to the storage room

5. POST
    - /api/gemstone
    - Description: Creates a new gemstone for the gemstone list
    - Response: 201 Created. Returns the created gemstone.

6. DELETE
    - /api/gemstone/<string>
    - Description: Delete a specific gemstone from the gemstone list.
    - Response: 204 No Content. Nothing gets returned.

ListAllObjects: HTTP://URMuseums, GET, Expected Response Body: Printed List of all the objects within the Museums, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListExhibitObjects: HTTP:// URMuseums/ExhibitName, GET, Expected Response Body: Print List of all the Object within the Exhibit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListStorgeObjects: HTTP:// URMuseums/StorageName, GET, Expected Response Body: Printed List of all the Object within the storage Unit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListObject: HTTP://URMuseums/ObjectSerial#, GET, Print the details for a single object within the museum. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found.
CreateObject: HTTP://URMuseums, POST, Request Body: Ideally, we want the user to have both authorization to create new objects, and input all the attributes of the New Object. The Response Body should be a copy of the new Object, with 201 Item Created. Errors: There could be a few, If the User does not meet the Authorization we will return a 401: Unauthorized, If the User does not give the correct amount of inputs, failing to create an object, we will return a 400: Bad Request
MoveObject: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: Exhibit or StorageName/ID that the User wants to move the Object to, it will update the Location class variable. The Response Body should be reflect the new location of the Object, with 200 OK. Errors: There could be a few, If the User does not meet the Authorization we will return a 401: Unauthorized, and if the object or the Exhibit/Storage cannot be found, we will return a 400: Bad Request
EditObjectINFO: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: Any Data the User wants to update for a given Object. Response Body: A copy of the object with its updated variables, with a 200 Ok. Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the object cannot be found, or if the user inpts data for a variable that does not exist, we will return a 400: Bad Request.
EditObjectSerial#: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: A Serial-Number for the Object, Response Body: A copy of the new Serial Number, with 200 OK. Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the user inputs a bad serial-number for the object, we will return a 400: Bad Request.
RemoveObject: HTTP://UrMusuems/ObjectSerial#, DELETE, Response Body: 204 No Content, Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the user inputs a bad serial-number for the object, we will return a 400: Bad Request.

## UML Diagrams
Picture Attached in GitHub
