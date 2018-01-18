#include "ofGameUnit.h"
#include <iostream>

void ofGameUnit::setup(ofPoint _gridPosition, float _width, float _height, float _betweenInterval, ofColor _color)
{
	setSize(_width, _height);
	setBetweenInterval(_betweenInterval);
	setColor(_color);
	update(_gridPosition, scale);
}

void ofGameUnit::setup(ofPoint _gridPosition)
{
	rect.x = _gridPosition.x;
	rect.y = _gridPosition.y;
}

void ofGameUnit::update(ofPoint _gridPosition, float _scale)
{
	scale = _scale;
	ofPoint offset = ofPoint(Unit::position.x * (betweenInterval + rect.width) * scale , 
							 Unit::position.y * (betweenInterval + rect.height) * scale);
	rect.x = _gridPosition.x + offset.x;
	rect.y = _gridPosition.y + offset.y;

	scaledSize.x = rect.width * scale;
	scaledSize.y = rect.height * scale;

	std::cout << "[INFO] Unit position: (" << Unit::position.x << "; " << Unit::position.y << "); " << std::endl;
	//std::cout << "[INFO] Scale Unit: " << scale << "; Rect (" << rect.x << "; " << rect.y << "; " << scaledSize.x << "; " << scaledSize.y << ");" << std::endl;
}

void ofGameUnit::draw()
{
	ofSetColor(color);
	ofDrawRectangle(ofRectangle(rect.x, rect.y, scaledSize.x, scaledSize.y));
}

void ofGameUnit::setColor(ofColor _color)
{
	color = _color;
}

void ofGameUnit::setSize(float _width, float _height)
{
	rect.width = _width;
	rect.height = _height;
}

void ofGameUnit::setBetweenInterval(float _betweenInterval)
{
	betweenInterval = _betweenInterval;
}
