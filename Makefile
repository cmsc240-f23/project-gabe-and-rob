all: MuseumAPI

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

persistenceTest: persistenceTest.cpp persistence.h Object.o
	g++ -lpthread persistenceTest.cpp Object.o -o persistenceTest

ObjectTest: ObjectTest.cpp Object.cpp Object.h Object.o
	g++ -lpthread ObjectTest.cpp Object.o -o ObjectTest

ExhibitTest: ExhibitTest.cpp Exhibit.cpp Exhibit.h Artwork.h Gemstone.h Object.h Exhibit.o
	g++ -lpthread ExhibitTest.cpp Exhibit.o -o ExhibitTest

StorageTest: StorageTest.cpp Storage.cpp Storage.h Artwork.h Gemstone.h Object.h Storage.o
	g++ -lpthread StorageTest.cpp Storage.o -o StorageTest

GemstoneTest: GemstoneTest.cpp Gemstone.cpp Gemstone.h Gemstone.o
	g++ -lpthread GemstoneTest.cpp Gemstone.o -o GemstoneTest

ArtworkTest: ArtworkTest.cpp Artwork.cpp Artwork.h Artwork.o
	g++ -lpthread ArtworkTest.cpp Artwork.o -o ArtworkTest

run-unit-tests: GenericAPITest persistenceTest ObjectTest ExhibitTest StorageTest GemstoneTest ArtworkTest
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