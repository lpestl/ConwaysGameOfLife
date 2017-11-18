#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	unit = new Unit(Unit::Point{ 0, 0 });
	countClick = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	switch (countClick)
	{
	case 0:
		unit->predictionNextState(Unit::ALIVE);
		break;
	case 1:
		unit->nextGeneration();
		break;
	case 2:
		unit->nextGeneration();
		break;
	case 3:
		delete unit;
		unit = nullptr;
		break;
	case 4:
		if (unit == nullptr)
			std::cout << "[INFO] Unit is NULL" << std::endl;
		else {
			std::cout << "[INFO] Unit is not NULL" << std::endl;
			std::cout << "[INFO] Unit age is "<< unit->getAge() << std::endl;
		}
		break;
	default:
		break;
	}
	countClick++;
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
