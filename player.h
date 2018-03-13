#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "drawable.h"


class Player : public Drawable
{
public:
	Player(int blockLen, int x, int y, sf::Texture &texture);
	void setSpriteTexture(sf::Texture & texture);
	void move(int x, int y);
};

