#include<iostream>
#include"player.h"
#include"game.h"

int main() {
	player p("Ivan", "1111", 19, 100);

	game g;
	g.play(p);
}