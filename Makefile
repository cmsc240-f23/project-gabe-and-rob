all: MuseumAPI static-analysis run-unit-tests

MuseumAPI: MuseumAPI.o Object.o Storage.o Artwork.o Gemstone.o Exhibit.o GenericAPI.o
	g++ -lpthread MuseumAPI.o Storage.o Exhibit.o Object.o Artwork.o Gemstone.o GenericAPI.o -o MuseumAPI

MuseumAPI.o: MuseumAPI.cpp Object.h Storage.h Artwork.h Gemstone.h Exhibit.h persistence.h GenericAPI.h
	g++ -Wall -c MuseumAPI.cpp

Storage.o: Storage.cpp Storage.h GenericAPI.h persistence.h
	g++ -Wall -c Storage.cpp

Object.o: Object.cpp Object.h Exhibit.h Storage.h
	g++ -Wall -c Object.cpp

Artwork.o: Artwork.cpp Artwork.h Object.h
	g++ -Wall -c Artwork.cpp

Gemstone.o: Gemstone.cpp Gemstone.h Object.h
	g++ -Wall -c Gemstone.cpp

Exhibit.o: Exhibit.cpp Exhibit.h GenericAPI.h persistence.h
	g++ -Wall -c Exhibit.cpp

GenericAPI.o: GenericAPI.cpp GenericAPI.h Storage.h Object.h Artwork.h Gemstone.h
	g++ -Wall -c GenericAPI.cpp

GenericAPITest: GenericAPITest.cpp GenericAPI.o Exhibit.o Gemstone.o Artwork.o Object.o Storage.o
	g++ -lpthread GenericAPITest.cpp GenericAPI.o Exhibit.o Gemstone.o Artwork.o Object.o Storage.o -o GenericAPITest

persistenceTest: persistenceTest.cpp persistence.h GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread persistenceTest.cpp persistence.h Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o persistenceTest

ObjectTest: ObjectTest.cpp GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread ObjectTest.cpp Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o ObjectTest

ExhibitTest: ExhibitTest.cpp GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread ExhibitTest.cpp Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o ExhibitTest

StorageTest: StorageTest.cpp GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread StorageTest.cpp Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o StorageTest

GemstoneTest: GemstoneTest.cpp GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread GemstoneTest.cpp Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o GemstoneTest

ArtworkTest: ArtworkTest.cpp GenericAPI.cpp GenericAPI.h GenericAPI.o Artwork.cpp Artwork.h Artwork.o Gemstone.cpp Gemstone.h Gemstone.o Object.cpp Object.h Object.o Exhibit.cpp Exhibit.h Exhibit.o Storage.cpp Storage.h Storage.o
	g++ -lpthread ArtworkTest.cpp Artwork.o Gemstone.o Exhibit.o Storage.o Object.o GenericAPI.o -o ArtworkTest

run-unit-tests: GenericAPITest ExhibitTest ObjectTest StorageTest GemstoneTest ArtworkTest persistenceTest
	./GenericAPITest    ;\
	./persistenceTest	;\
	./ObjectTest		;\
	./ExhibitTest		;\
	./StorageTest		;\
	./GemstoneTest		;\
	./ArtworkTest

static-analysis:
	cppcheck *.cpp
	
clean:
	rm -f *.o MuseumAPI