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
ListAllObjects: HTTP://URMuseums, GET, Expected Response Body: Printed List of all the objects within the Museums, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListExhibitObjects: HTTP:// URMuseums/ExhibitName, GET, Expected Response Body: Printed List of all the Object within the Exhibit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListStorgeObjects: HTTP:// URMuseums/StorageName, GET, Expected Response Body: Printed List of all the Object within the storage Unit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListObject: HTTP://URMuseums/ObjectSerial#, GET, Print the details for a single object within the museum. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found.
CreateObject: HTTP://URMuseums, POST, Request Body: Ideally, we want the user to have both authorization to create new objects, and input all the attributes of the New Object. The Response Body should be a copy of the new Object, with 201 Item Created. Errors: There could be a few, If the User does not meet the Authorization we will return a 401: Unauthorized, If the User does not give the correct amount of inputs, failing to create an object, we will return a 400: Bad Request
MoveObject: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: Exhibit or StorageName/ID that the User wants to move the Object to, it will update the Location class variable. The Response Body should be reflect the new location of the Object, with 200 OK. Errors: There could be a few, If the User does not meet the Authorization we will return a 401: Unauthorized, and if the object or the Exhibit/Storage cannot be found, we will return a 400: Bad Request
EditObjectINFO: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: Any Data the User wants to update for a given Object. Response Body: A copy of the object with its updated variables, with a 200 Ok. Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the object cannot be found, or if the user inpts data for a variable that does not exist, we will return a 400: Bad Request.
EditObjectSerial#: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: A Serial-Number for the Object, Response Body: A copy of the new Serial Number, with 200 OK. Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the user inputs a bad serial-number for the object, we will return a 400: Bad Request.
RemoveObject: HTTP://UrMusuems/ObjectSerial#, DELETE, Response Body: 204 No Content, Errors: If the User does not meet the Authorization we will return a 401: Unauthorized, if the user inputs a bad serial-number for the object, we will return a 400: Bad Request.

## UML Diagrams
Picture Attached in GitHub
