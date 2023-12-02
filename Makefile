all: MuseumAPI

MuseumAPI: MuseumAPI.o Object.o Storage.o Artwork.o Gemstone.o Exhibit.o GenericAPI.o
	g++ -lpthread MuseumAPI.o Storage.o Exhibit.o Object.o Artwork.o Gemstone.o GenericAPI.o -o MuseumAPI

MuseumAPI.o: MuseumAPI.cpp Object.h Storage.h Artwork.h Gemstone.h Exhibit.h persistence.h GenericAPI.h
	g++ -Wall -c MuseumAPI.cpp

Storage.o: Storage.cpp Storage.h
	g++ -Wall -c Storage.cpp

Object.o: Object.cpp Object.h Exhibit.h Storage.h
	g++ -Wall -c Object.cpp

Artwork.o: Artwork.cpp Artwork.h Object.h
	g++ -Wall -c Artwork.cpp

Gemstone.o: Gemstone.cpp Gemstone.h Object.h
	g++ -Wall -c Gemstone.cpp

Exhibit.o: Exhibit.cpp Exhibit.h
	g++ -Wall -c Exhibit.cpp

GenericAPI.o: GenericAPI.cpp GenericAPI.h Storage.h Object.h Artwork.h Gemstone.h
	g++ -Wall -c GenericAPI.cpp

clean:
	rm -f *.o MuseumAPI