MuseumAPI: MuseumAPI.o Object.o Storage.o Artwork.o Gemstone.o GenericAPI.o
	g++ -lpthread MuseumAPI.o Storage.o Object.o Artwork.o Gemstone.o GenericAPI.o -o MuseumAPI

MuseumAPI.o: MuseumAPI.cpp Object.h Storage.h Artwork.h Gemstone.h persistence.h GenericAPI.h
	g++ -Wall -c MuseumAPI.cpp

Storage.o: Storage.cpp Storage.h
	g++ -Wall -c Storage.cpp

Object.o: Object.cpp Object.h
	g++ -Wall -c Object.cpp

Artwork.o: Artwork.cpp Artwork.h Object.h
	g++ -Wall -c Artwork.cpp

Gemstone.o: Gemstone.cpp Gemstone.h Object.h
	g++ -Wall -c Gemstone.cpp

GenericAPI.o: GenericAPI.cpp GenericAPI.h Storage.h Object.h Artwork.h Gemstone.h
	g++ -Wall -c GenericAPI.cpp

clean:
	rm -f *.o MuseumAPI