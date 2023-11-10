# Project Design Document

## Introduction
It's going to be a mock database for the University of Richmond's Harnett museum. It wil allow people to search through different exibits, types of artworks, and things in storage. 

## Background/Context
The University of Richmond doesn't have a comprehensive database for their art museum as we know.

## Stakeholders
UR Museums and student workers of the museums and people who want to browse the catalog.

## Functional Requirements
Should be able to browse and read information for art pieces and objects in storage in the University musueams. Should be able to store the objects seriall number. Where it is stored vs where it is right now. Description of the object. Where it came from. The condition of the objects.

## Use Case Description
As a manager of the museum, I want to know everything that my department has access to, where they are stored, and what their condition is. 

## List Of Resources
Active exibits: different rooms, vector with what the exhibit holds, exhibit name. 
Object which would have the serial number, its current location, donor, date of aquisition, and weight. Two different subclasses for object: artworks (variables listed): artist, type of artwork, date created; gem-stones (variables): type of gem-stone, and dimensions.
Storage: has a long vector with a catalogue of what object are stored and ordered by serial number, the physical location of the storage unit, and how much capacity it has left?

## List of End Points
ListAllObjects: HTTP://URMuseums, GET, Expected Response Body: Printed List of all the objects within the Museums, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListExhibitObjects: HTTP:// URMuseums/ExhibitName, GET, Expected Response Body: Printed List of all the Object within the Exhibit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListStorgeObjects: HTTP:// URMuseums/StorageName, GET, Expected Response Body: Printed List of all the Object within the storage Unit, ordered by serial number. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found. 
ListObject: HTTP://URMuseums/ObjectSerial#, GET, Print the details for a single object within the museum. 200 OK. The main error that can occur is probably a user mistyping the URL, so we will run the general 404: Page not Found.
CreateObject: HTTP://URMuseums, POST, Request Body: Ideally, we want the user to have both authorization to create new objects, and input all the attributes of the New Object. 201 Item Created. Errors: There could be a few, If the User does not meet the Authorization we will return a 401: Unauthorized, If the User does not give the correct amount of inputs, failing to create an object, we will return a 400: Bad Request
MoveObject: HTTP://URMuseums/ObjectSerial#, PUT, Request Body: Exhibit or StorageName that the 
EditObjectINFO: HTTP://URMuseums/ObjectSerial#, PUT,
EditObjectSerial#: HTTP://URMuseums/ObjectSerial#, PUT,
RemoveObject: HTTP://UrMusuems/ObjectSerial#, DELETE, 


## UML Diagrams
Picture Attached in GitHub
