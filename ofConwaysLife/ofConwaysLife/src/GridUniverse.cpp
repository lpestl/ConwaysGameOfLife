#include "GridUniverse.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

GridUniverse::GridUniverse(Type _type) :
	type(_type),
	age(0),
	size(Size(0,0)),
	units(new std::list<Unit*>())
{
	std::cout << "[INFO] Create universe" << std::endl;
}

GridUniverse::~GridUniverse()
{
	cleareGrid();
	delete units;
	std::cout << "[INFO] Destroy universe" << std::endl;
}

void GridUniverse::initNull(Size _size)
{
	if (units->size() != 0) {
		cleareGrid();
	}
	size = _size;
}

void GridUniverse::initRandom(Size _size)
{

	if (units->size() != 0) {
		cleareGrid();
	}
	size = _size;

	std::srand(unsigned(std::time(0)));
	for (auto i = 0; i < size.height; ++i) {
		for (auto j = 0; j < size.width; ++j) {
			if ((std::rand() % 2) == 1) {
				createNewUnit(Point(i, j));
			}
		}
	}
}

void GridUniverse::cleareGrid()
{
	auto i = units->begin();
	while (i != units->end())
	{
		delete *i;
		units->erase(i++);
	}
}

void GridUniverse::createNewUnit(Point _position)
{
	units->push_back(new Unit(_position));
	std::cout << "[INFO] Create new Unit in ("<< _position.x << "; " << _position.y << ")" << std::endl;
}

void GridUniverse::draw()
{
	for (auto i = 0; i < size.height; ++i) {
		for (auto j = 0; j < size.width; ++j) {
			if (isThereUnit(Point(i,j))) {
				std::cout << "1 ";
			}
			else {
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//void GridUniverse::killUnit(Unit * _unit)
//{
//	auto it = std::find(units->begin(), units->end(), _unit);
//	if (it != units->end()) {
//		units->erase(it);
//		std::cout << "[INFO] Delete unit with call erase" << std::endl;
//	}
//	else {
//		delete _unit;
//		std::cout << "[INFO] Simple delete unit" << std::endl;
//	}
//}

bool GridUniverse::isThereUnit(Point _position)
{
	bool contain = false;
	for (auto it = units->begin(); it != units->end(); ++it) {
		auto pos = (*it)->getPosition();
		if ((pos.x == _position.x) && (pos.y == _position.y)) {
			contain = true;
			break;
		}
	}
	return contain;
}

unsigned int GridUniverse::getPopulation()
{
	return units->size();
}

unsigned int GridUniverse::getAge()
{
	return age;
}

unsigned int GridUniverse::numberNeighbors(Point _point)
{
	unsigned int count = 0;

	int prevX = _point.x - 1;
	int prevY = _point.y - 1;
	int nextX = _point.x + 1;
	int nextY = _point.y + 1;

	// LOOPED type game
	if (prevX < 0) prevX = size.width - 1;
	if (nextX >= size.width) nextX = 0;
	if (prevY < 0) prevY = size.height - 1;
	if (nextY >= size.height) nextY = 0;

	// Top Left
	if (isThereUnit(Point(prevX, prevY))) count++;
	// Top Middle
	if (isThereUnit(Point(_point.x, prevY))) count++;
	// Top Right
	if (isThereUnit(Point(nextX, prevY))) count++;
	// Middle Left
	if (isThereUnit(Point(prevX, _point.y))) count++;
	// Middle Right
	if (isThereUnit(Point(nextX, _point.y))) count++;
	// Bottom Left
	if (isThereUnit(Point(prevX, nextY))) count++;
	// Bottom Middle
	if (isThereUnit(Point(_point.x, nextY))) count++;
	// Bottom Right
	if (isThereUnit(Point(nextX, nextY))) count++;

	return count;
}

void GridUniverse::nextGeneration()
{
	std::list<Point> placesBirth;

	for (auto it = units->begin(); it != units->end(); ++it) {
		auto countNeighbors = numberNeighbors((*it)->getPosition());
		// Any live cell with two or three live neighbours lives on to the next generation.
		if ((countNeighbors == 2) || (countNeighbors == 3)) 
		{
			(*it)->predictionNextState(ALIVE);
		}
		else 
		{
			// Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
			if (countNeighbors < 2) {
				(*it)->predictionNextState(DEAD);
			}
			else
			{
				// Any live cell with more than three live neighbours dies, as if by overpopulation.
				if (countNeighbors > 3) {
					(*it)->predictionNextState(DEAD);
				}
			}
		}

		// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

	}

	age++;
}
//
//unsigned int GridUniverse::numberEndlesNeighbors(Point _point)
//{
//	return 0;
//}
//
//unsigned int GridUniverse::numberBoundedNeighbors(Point _point)
//{
//	return 0;
//}
//
//unsigned int GridUniverse::numberLoopedNeighbors(Point _point)
//{
//	return 0;
//}