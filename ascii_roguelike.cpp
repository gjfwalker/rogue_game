#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "game.h"
#include <SFML/Graphics.hpp>

int main() {

	Game game;
	game.setTextures("res/img/wall.jpg", "res/img/hero.jpg");
	game.readMap("map1.txt");


	sf::RenderWindow window(sf::VideoMode(1200, 800), "game");

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch(evnt.type){
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128) {
						game.dealWithInput(evnt.text.unicode);
					}
					break;
			}
		}
		window.clear();
		game.drawMap(window);
		window.display();
	}




	system("pause");
	return 0;
}