#include "Unit.h"
#include <iostream>

Unit::Unit(Unit::Point _position) :
	age(0),
	currentState(Unit::ALIVE),
	position(_position),
	nextState(Unit::UNKNOWN)
{
	std::cout << "[INFO] \"I was born!\" - Luntik" << std::endl;
}

Unit::~Unit()
{
	std::cout << "[INFO] \"I'll be back\" - Terminator. I was " << age << " generations old." << std::endl;
}

Unit::State Unit::getCurrentState()
{
	return currentState;
}

Unit::State Unit::getNextState()
{
	return nextState;
}

unsigned int Unit::getAge()
{
	return age;
}

Unit::Point Unit::getPosition()
{
	return position;
}

void Unit::predictionNextState(State _nextState)
{
	nextState = _nextState;
}

void Unit::nextGeneration()
{
	currentState = nextState;
	nextState = Unit::UNKNOWN;
	age++;
}
