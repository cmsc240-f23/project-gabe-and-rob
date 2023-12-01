MuseumAPI: MuseumAPI.o Object.o Storage.o GenericAPI.o
	g++ -lpthread MuseumAPI.o Storage.o Object.o GenericAPI.o -o MuseumAPI

MuseumAPI.o: MuseumAPI.cpp Object.h Storage.h persistence.h GenericAPI.h
	g++ -Wall -c MuseumAPI.cpp

Storage.o: Storage.cpp Storage.h
	g++ -Wall -c Storage.cpp

Object.o: Object.cpp Object.h
	g++ -Wall -c Object.cpp

GenericAPI.o: GenericAPI.cpp GenericAPI.h Storage.h Object.h
	g++ -Wall -c GenericAPI.cpp

clean:
	rm -f *.o MuseumAPI