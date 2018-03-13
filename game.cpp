#include "stdafx.h"
#include "game.h"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <string>

Game::Game() {

}

void Game::setTextures(std::string wall, std::string player) {
	if (!wallTexture.loadFromFile(wall, sf::IntRect(0, 0, 20, 20))) {
		std::cout << "load of wall failed" << std::endl;
	}

	if (!playerTexture.loadFromFile(player)) {
		std::cout << "load of player failed" << std::endl;
	}
}

std::vector<std::vector<char>> Game::loadMap(std::string fname) {
	std::vector<std::vector<char>> map;
	std::ifstream file;
	file.open("maps/" + fname);

	std::string line;
	if (file) {
		while (std::getline(file, line)) {
			std::vector<char> row(line.begin(), line.end());
			map.push_back(row);
		}
	}
	file.close();

	return map;

}

void Game::readMap(std::string fname) {

	std::vector<std::vector<char>> map = loadMap(fname);
	std::vector<char> row;
	for (int i = 0; i<map.size(); i++) {
		row = map.at(i);
		for (int j = 0; j<row.size(); j++) {
			switch (map.at(i).at(j)) {
			case '#':
				{
					Unmoveable wall(BLOCK_SIZE, j, i, wallTexture);
					walls.push_back(wall);
					break;
				}
				case '@':
				{
					Player player(BLOCK_SIZE, j, i, playerTexture);
					players.push_back(player);
					break;
				}
			}
		}
	}
}


int Game::getScore() {
	return score;
}

void Game::addScore(int diff) {
	score += diff;
}

void Game::drawMap(sf::RenderWindow &window) {
	for (int i = 0; i<walls.size(); i++) {
		walls.at(i).draw(window);
	}
	players.at(0).draw(window);
}

void Game::dealWithInput(int i) {
	switch (i){
		case 119: // w
			tryPlayerMove(0, -1);
			break;
		case 115: // s
			tryPlayerMove(0, 1);
			break;
		case 97: // a
			tryPlayerMove(-1, 0);
			break;
		case 100: // d
			tryPlayerMove(1, 0);
			break;
	}
}


void Game::tryPlayerMove(int x, int y) {
	if (abs(x) > 1 || abs(y) > 1){
		std::cout << "only move 1 square at a time" << std::endl;
		return;
	}
	int propPosX = players.at(0).getPosX() + (x * BLOCK_SIZE);
	int propPosY = players.at(0).getPosY() + (y * BLOCK_SIZE);
	std::cout << propPosX << " " << propPosY << std::endl;

	for (int i = 0; i < walls.size(); i++) {
		if (propPosX == walls.at(i).getPosX() && propPosY == walls.at(i).getPosY()) {
			std::cout << "can't move there" << std::endl;
			return;
		}
	}
	players.at(0).move(x, y);
}