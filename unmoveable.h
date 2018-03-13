#pragma once
#include <SFML/Graphics.hpp>
#include "drawable.h"

class Unmoveable : public Drawable
{
public:
	Unmoveable(int blockLen, int x, int y, sf::Texture & texture);
};

