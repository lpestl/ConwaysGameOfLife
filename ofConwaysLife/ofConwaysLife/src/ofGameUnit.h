#pragma once

#include "Unit.h"
#include "ofMain.h"

class ofGameUnit : public Unit
{
public:
	ofGameUnit(Point _point) : 
		Unit(_point), 
		rect(ofRectangle(0,0,0,0)), 
		scale(1), 
		betweenInterval(0),
		color(ofColor::black),
		scaledSize(ofPoint(0,0))
	{ }

	void setup(ofPoint _gridPosition, float _width, float _height, float _betweenInterval, ofColor _color);
	void setup(ofPoint _gridPosition);
	void update(ofPoint _gridPosition, float _scale);
	void draw();
	
	void setColor(ofColor _color);
	void setSize(float _width, float _height);
	void setBetweenInterval(float _betweenInterval);

private:
	ofRectangle rect;
	ofPoint scaledSize;
	float scale;
	float betweenInterval;
	ofColor color;
};

