all: main.o
	g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main.0: main.cpp
	g++ -c main.cpp
