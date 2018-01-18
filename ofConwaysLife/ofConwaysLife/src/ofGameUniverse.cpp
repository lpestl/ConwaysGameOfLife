#include "ofGameUniverse.h"

void ofGameUniverse::setup(ofPoint _size, unsigned int _countColumns, unsigned int _countRows, float _betweenInterval, bool randomGrid)
{
	setSize(_size, _betweenInterval);
	if (randomGrid) {
		GridUniverse::initRandom(Size(_countColumns, _countRows));
	}
	else {
		GridUniverse::initNull(Size(_countColumns, _countRows));
	}
	calculateUnitSize();
}

void ofGameUniverse::update(ofPoint _position, float _scale)
{
	rect.x = _position.x;
	rect.y = _position.y;

	scale = _scale;

	scaledSize.x = rect.width * scale;
	scaledSize.y = rect.height * scale;

	for (auto* unit : *units) {
		try 
		{
			ofGameUnit* ofUnit = dynamic_cast<ofGameUnit*>(unit);
			ofUnit->update(_position, scale);
		}
		catch (const std::bad_cast& e)
		{
			std::cerr << "[ERROR] " << e.what() << ". Chech ofGameUniverse.update " << std::endl;
			std::cerr << "[INFO] Live units in the list are logical, but not physical, and therefore do not have color." << std::endl;
		}
	}

	std::cout << "Size universe: (" << GridUniverse::size.width << "; " << GridUniverse::size.height << "); " << std::endl;
}

void ofGameUniverse::createNewUnit(Point _position)
{
	ofGameUnit* unit = new ofGameUnit(_position);
	unit->setBetweenInterval(betweenInterval);
	unit->setColor(colorUnits);
	unit->setSize(unitSize.x, unitSize.y);
	units->push_back(std::move(unit));
}

void ofGameUniverse::draw(bool withBg)
{
	if (withBg) {
		ofSetColor(colorBackground);
		for (auto i = 0; i < size.height; ++i) {
			for (auto j = 0; j < size.width; ++j) {
				ofDrawRectangle(ofRectangle((rect.x + j * (betweenInterval + unitSize.x) * scale),
					(rect.y + i * (betweenInterval + unitSize.y) * scale),
					unitSize.x * scale,
					unitSize.y * scale));
			}
		}
	}

	for (auto* unit : *units) {
		try
		{
			ofGameUnit* ofUnit = dynamic_cast<ofGameUnit*>(unit);
			ofUnit->draw();
		}
		catch (const std::bad_cast& e)
		{
			std::cerr << "[ERROR] " << e.what() << ". Chech ofGameUniverse.update " << std::endl;
			std::cerr << "[INFO] Live units in the list are logical, but not physical, and therefore do not have color." << std::endl;
		}
	}
}

void ofGameUniverse::setSize(ofPoint _size, float _betweenInterval)
{
	rect.width = _size.x;
	rect.height = _size.y;

	betweenInterval = _betweenInterval;

	calculateUnitSize();

	for (auto* unit : *units) {
		try 
		{
			ofGameUnit* ofUnit = dynamic_cast<ofGameUnit*>(unit);
			ofUnit->setBetweenInterval(betweenInterval);
			ofUnit->setSize(unitSize.x, unitSize.y);
		}
		catch (const std::bad_cast& e)
		{
			std::cerr << "[ERROR] " << e.what() << ". Chech ofGameUniverse.setSize " << std::endl;
			std::cerr << "[INFO] Live units in the list are logical, but not physical, and therefore do not have color." << std::endl;
		}
	}
}

ofPoint ofGameUniverse::getSize()
{
	return ofPoint(rect.width, rect.height);
}

ofPoint ofGameUniverse::getScaledSize()
{
	return scaledSize;
}

ofPoint ofGameUniverse::getPosition()
{
	return ofPoint(rect.x, rect.y);
}

float ofGameUniverse::getScale()
{
	return scale;
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
			std::cerr << "[ERROR] " << e.what() << ". Chech ofGameUniverse.setColorUnits " << std::endl;
			std::cerr << "[INFO] Live units in the list are logical, but not physical, and therefore do not have color." << std::endl;
		}
	}
}

ofColor ofGameUniverse::getColorUnits()
{
	return colorUnits;
}

ofPoint ofGameUniverse::getUnitSize()
{
	return unitSize;
}

ofPoint ofGameUniverse::calculateUnitSize()
{
	unitSize.x = (rect.width - (size.width - 1) * betweenInterval) / size.width;
	unitSize.y = (rect.height - (size.height - 1) * betweenInterval) / size.height;
	return unitSize;
}
