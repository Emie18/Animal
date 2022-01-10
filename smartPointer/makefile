smart.exe :  Animals.o  main.o
	g++ -std=c++14 Animals.o main.o  -o smart.exe
Animals.o : Animals.cpp Animals.h
	g++ -std=c++14 -c Animals.cpp
main.o : main.cpp Animals.h
	g++ -std=c++14 -c main.cpp
clean :
	rm *.o