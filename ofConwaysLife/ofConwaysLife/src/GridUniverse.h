#pragma once

#include "Unit.h"
#include <list>

class GridUniverse
{
public:
	struct Size {
		Size(unsigned int w, unsigned int h) : width(w), height(h) {}

		unsigned int width;
		unsigned int height;
	};

	enum Type { /*ENDLES, BOUNDED,*/ LOOPED };

	GridUniverse(Type _type);
	~GridUniverse();

	void initNull(Size _size);
	void initRandom(Size _size);
	void cleareGrid();
	virtual void createNewUnit(Point _position);

	virtual void draw();

	//void killUnit(Unit *_unit);
	bool isThereUnit(Point _position);
	unsigned int getPopulation();
	unsigned int getAge();
	unsigned int numberNeighbors(Point _point);
		
	void nextGeneration();	

private:
	//unsigned int numberEndlesNeighbors(Point _point);
	//unsigned int numberBoundedNeighbors(Point _point);
	//unsigned int numberLoopedNeighbors(Point _point);

	Type					type;
	unsigned int			age;
	Size					size;
	std::list<Unit*>		*units;
};

