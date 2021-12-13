Animals.exe : Lion.o Gazelle.o Animals.o Monde.o main.o
	g++ Lion.o Gazelle.o Animals.o main.o Monde.o -o animals.exe
Lion.o : Lion.cpp Lion.h
	g++ -std=c++11 -c Lion.cpp
Gazelle.o :Gazelle.cpp Gazelle.h
	g++ -std=c++11 -c Gazelle.cpp
Animals.o : Animals.cpp Animals.h
	g++ -std=c++11 -c Animals.cpp
Monde.o : Monde.cpp Monde.h
	g++ -std=c++11 -c Monde.cpp
main.o : main.cpp Animals.h
	g++ -std=c++11 -c main.cpp
clean :
	rm *.o