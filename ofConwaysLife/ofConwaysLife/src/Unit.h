#pragma once


enum State { UNKNOWN, ALIVE, DEAD };
struct Point
{
	Point (unsigned int _x, unsigned int _y) : x(_x), y(_y) {}
	unsigned int x;
	unsigned int y;
};

class Unit
{
public:
	Unit(Point _position);
	~Unit();

	State			getCurrentState();
	State			getNextState();
	unsigned int	getAge();
	Point			getPosition();

	void			predictionNextState(State _nextState);
	void			nextGeneration();

private:
	State			currentState;
	unsigned int	age;
	Point			position;
	State			nextState;
};

