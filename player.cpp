#include "stdafx.h"
#include "player.h"

Player::Player(int blockLen, int x, int y, sf::Texture &texture) {
	blockSize = blockLen;
	setSpriteTexture(texture);
	setPos(x, y);
}

void Player::setSpriteTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
	sf::Vector2u size = texture.getSize();
	sprite.setScale((float)blockSize / (float)size.x, (float)blockSize / (float)size.y);
	sprite.setPosition(posX, posY);
}

void Player::move(int x, int y) {
	sf::Vector2f pos = sprite.getPosition();
	posX = pos.x + x * blockSize;
	posY = pos.y + y * blockSize;
	sprite.setPosition(posX, posY);
}
