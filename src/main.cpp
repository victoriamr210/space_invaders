#include <iostream>
#include "../include/game.hpp"

// g++ -c main.cpp
// g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
// ./sfml-app

int main(int argc, char *argv[]) {
	game a;
	a.gameloop();
}