#include "ofApp.h"
#include <iostream>
#include "Unit.h"

//--------------------------------------------------------------
void ofApp::setup(){
	countClick = 0;

	universe = new ofGameUniverse();

	universe->setup(ofPoint(ofGetWindowWidth(), ofGetWindowHeight()), 30, 30, 2);
	universe->setColorBackground(ofColor(255, 255, 255, 120));
	universe->setColorUnits(ofColor(255, 0, 0, 255));
	
}

//--------------------------------------------------------------
void ofApp::update() {
	universe->nextGeneration();
	universe->update(universe->getPosition(), universe->getScale());
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::aqua, ofColor::black, ofGradientMode::OF_GRADIENT_CIRCULAR);
	universe->draw();
}

void ofApp::exit()
{
	delete universe;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (countClick)
	{
	case 0:
		universe->createNewUnit(Point(0, 0));
		universe->createNewUnit(Point(1, 1));
		universe->createNewUnit(Point(1, 2));
		universe->createNewUnit(Point(2, 0));
		universe->createNewUnit(Point(2, 1));
		universe->update(universe->getPosition(), universe->getScale());
		break;
	case 1:

		break;
	case 2:

		break;
	default:
		universe->nextGeneration();
		universe->update(universe->getPosition(), universe->getScale());
		break;
	}
	countClick++;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
