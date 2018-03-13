#include "stdafx.h"
#include "drawable.h"
#include <iostream>
#include <SFML/Graphics.hpp>




void Drawable::setSpriteTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
}

int Drawable::getPosX() {
	return posX;
}
int Drawable::getPosY() {
	return posY;
}

void Drawable::draw(sf::RenderWindow & window) {
	window.draw(sprite);
}

void Drawable::setPos(int x, int y) {
	posX = x * blockSize;
	posY = y * blockSize;
	std::cout << posX << " " << posY<< " " << blockSize << std::endl;
	sprite.setPosition(posX, posY);
}