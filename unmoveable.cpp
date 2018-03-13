#include "stdafx.h"
#include "unmoveable.h"
#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>



Unmoveable::Unmoveable(int blockLen, int x, int y, sf::Texture & texture) {
	blockSize = blockLen;
	setSpriteTexture(texture);
	setPos(x, y);
}
