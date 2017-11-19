#include "Unit.h"
#include <iostream>

Unit::Unit(Point _position) :
	age(0),
	currentState(ALIVE),
	position(_position),
	nextState(UNKNOWN)
{
	std::cout << "[INFO] \"I was born!\" - Luntik" << std::endl;
}

Unit::~Unit()
{
	std::cout << "[INFO] \"I'll be back\" - Terminator. I was " << age << " generations old." << std::endl;
}

State Unit::getCurrentState()
{
	return currentState;
}

State Unit::getNextState()
{
	return nextState;
}

unsigned int Unit::getAge()
{
	return age;
}

Point Unit::getPosition()
{
	return position;
}

void Unit::predictionNextState(State _nextState)
{
	nextState = _nextState;
}

void Unit::nextGeneration()
{
	if (nextState == UNKNOWN) {
		std::cout << "[WARNING] Uncertain behavior of the unit. The state of the unit was not counted. Use \"predictionNextState\"." << std::endl;
	}
	currentState = nextState;
	nextState = UNKNOWN;
	age++;
}
