#pragma once
#ifndef GAME
#define GAME

#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <iostream>
#include "player.h"
#include "unmoveable.h"


class Game
{
public:
	Game();
	int getScore();
	void addScore(int diff);
	void readMap(std::string fname);
	std::vector<std::vector<char>> loadMap(std::string fname);
	void drawMap(sf::RenderWindow &window);
	void setTextures(std::string wall, std::string player);
	void dealWithInput(int i);
private:
	void tryPlayerMove(int x, int y);
	static const int MAP_WIDTH = 60;
	static const int MAP_HEIGHT = 20;
	static const int BLOCK_SIZE = 20;
	int score;
	std::vector<Unmoveable> walls{};
	std::vector<Player> players; // Why can't I instantiate a Player object with block_size input in the header?  
	// Player player(BLOCK_SIZE) // Having to use this workaround whereby player is players.at(0).
	sf::Texture wallTexture;
	sf::Texture playerTexture;
};


#endif
