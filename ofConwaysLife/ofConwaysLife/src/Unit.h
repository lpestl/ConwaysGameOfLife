#pragma once

class Unit
{
public:
	enum State { UNKNOWN, ALIVE, DEAD };
	struct Point
	{
		unsigned int x;
		unsigned int y;
	};

	Unit(Point _position);
	~Unit();

	State getCurrentState();
	State getNextState();
	unsigned int getAge();
	Point getPosition();

	void predictionNextState(State _nextState);
	void nextGeneration();

private:
	State			currentState;
	unsigned int	age;
	Point			position;
	State			nextState;
};

