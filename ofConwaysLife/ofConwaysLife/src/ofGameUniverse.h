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
		colorUnits(ofColor::black)
	{}

	void setup(ofPoint _size, float _betweenInterval);
	void update();

	// Overrides start
	virtual void createNewUnit(Point _position);
	virtual void draw();
	// Overrides end

	void setSize(ofPoint _size);
	ofPoint getSize();
	ofPoint getScaledSize();
	
	void setScale(float _scale);
	float getScale();

	void setBetweenInterval(float _interval);
	float getBetweenInterval();

	void setColorBackground(ofColor _colorBakground);
	ofColor getColorBackground();

	void setColorInterval(ofColor _colorInterval);
	ofColor getColorInterval();

	void setColorUnits(ofColor _colorUnits);
	ofColor getColorUnits();

private:
	ofRectangle rect;
	ofPoint scaledSize;
	float scale;
	float betweenInterval;
	ofColor colorBackground;
	ofColor colorIntervals;
	ofColor colorUnits;
};

