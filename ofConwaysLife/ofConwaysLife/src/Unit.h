#pragma once

enum State { UNKNOWN, ALIVE, DEAD };
struct Point
{
	Point (long int _x, long int _y) : x(_x), y(_y) {}
	long int x;
	long int y;
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

	virtual void	draw();

	void			predictionNextState(State _nextState);
	void			nextGeneration();

protected:
	State			currentState;
	unsigned int	age;
	Point			position;
	State			nextState;
};

