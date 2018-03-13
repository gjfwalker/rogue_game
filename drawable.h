#pragma once
#include <SFML/Graphics.hpp>


class Drawable
{
public:
	int getPosX();
	int getPosY();
	void setPos(int x, int y);
	void draw(sf::RenderWindow & window);
	void setSpriteTexture(sf::Texture& texture);

protected:
	int blockSize;
	int posX;
	int posY;
	sf::Sprite sprite;
};

