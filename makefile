all: main.o window.o player.o object.o
	g++ main.o window.o player.o object.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp window.hpp
	g++ -c main.cpp

window.o: window.cpp window.hpp player.hpp
	g++ -c window.cpp

player.o: player.cpp player.hpp
	g++ -c player.cpp

object.o: object.cpp object.hpp
	g++ -c object.cpp

clean:
	rm -f *.o
