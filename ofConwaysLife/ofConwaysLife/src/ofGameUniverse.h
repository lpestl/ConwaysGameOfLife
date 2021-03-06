#pragma once

#include "ofMain.h"
#include "GridUniverse.h"
#include "ofGameUnit.h"

class ofGameUniverse : public GridUniverse
{
public:
	ofGameUniverse() :
		GridUniverse(GridUniverse::LOOPED),
		rect(ofRectangle(0, 0, 0, 0)),
		scaledSize(ofPoint(0, 0)),
		scale(1),
		betweenInterval(0),
		colorBackground(ofColor(255, 255, 255, 0)),
		colorIntervals(ofColor(255, 255, 255, 0)),
		colorUnits(ofColor::black), 
		unitSize(ofPoint(0, 0))
	{}

	void setup(ofPoint _size, unsigned int _countColumns, unsigned int _countRows, float _betweenInterval = NULL, bool randomGrid = false);
	void update(ofPoint _position, float _scale);

	virtual void createNewUnit(Point _position);
	virtual void draw(bool withBg = true);

	void setSize(ofPoint _size, float _betweenInterval = NULL);
	ofPoint getSize();
	ofPoint getScaledSize();
	ofPoint getPosition();
	
	float getScale();
	float getBetweenInterval();

	void setColorBackground(ofColor _colorBakground);
	ofColor getColorBackground();

	void setColorInterval(ofColor _colorInterval);
	ofColor getColorInterval();

	void setColorUnits(ofColor _colorUnits);
	ofColor getColorUnits();

	ofPoint getUnitSize();

private:
	ofPoint calculateUnitSize();

	ofRectangle rect;
	ofPoint scaledSize;
	float scale;
	float betweenInterval;
	ofColor colorBackground;
	ofColor colorIntervals;
	ofColor colorUnits;
	ofPoint unitSize;
};

