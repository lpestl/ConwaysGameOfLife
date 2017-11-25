#include "ofGameUniverse.h"

// TODO: Write code, blead!
void ofGameUniverse::setup(ofPoint _size, float _betweenInterval)
{
}

void ofGameUniverse::update()
{
}

void ofGameUniverse::createNewUnit(Point _position)
{
}

void ofGameUniverse::draw()
{
}
// End TODO

void ofGameUniverse::setSize(ofPoint _size)
{
	rect.width = _size.x;
	rect.height = _size.y;
}

ofPoint ofGameUniverse::getSize()
{
	return ofPoint(rect.width, rect.height);
}

ofPoint ofGameUniverse::getScaledSize()
{
	return scaledSize;
}

void ofGameUniverse::setScale(float _scale)
{
	scale = _scale;
}

float ofGameUniverse::getScale()
{
	return scale;
}

void ofGameUniverse::setBetweenInterval(float _interval)
{
	betweenInterval = _interval;
}

float ofGameUniverse::getBetweenInterval()
{
	return betweenInterval;
}

void ofGameUniverse::setColorBackground(ofColor _colorBakground)
{
	colorBackground = _colorBakground;
}

ofColor ofGameUniverse::getColorBackground()
{
	return colorBackground;
}

void ofGameUniverse::setColorInterval(ofColor _colorInterval)
{
	colorIntervals = _colorInterval;
}

ofColor ofGameUniverse::getColorInterval()
{
	return colorIntervals;
}

void ofGameUniverse::setColorUnits(ofColor _colorUnits)
{
	colorUnits = _colorUnits;
	for (auto it_unit = units->begin(); it_unit != units->end(); ++it_unit) 
	{
		try
		{
			ofGameUnit* unit = dynamic_cast<ofGameUnit*>((*it_unit));
			unit->setColor(colorUnits);
		}
		catch (const std::bad_cast& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
			std::cerr << "[INFO] Live units in the list are logical, but not physical, and therefore do not have color." << std::endl;
		}
	}
}

ofColor ofGameUniverse::getColorUnits()
{
	return colorUnits;
}
