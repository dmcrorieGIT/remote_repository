all: main.o window.o player.o
	g++ main.o window.o player.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp window.hpp
	g++ -c main.cpp

window.o: window.cpp window.hpp player.hpp
	g++ -c window.cpp

player.o: player.cpp player.hpp
	g++ -c player.cpp
