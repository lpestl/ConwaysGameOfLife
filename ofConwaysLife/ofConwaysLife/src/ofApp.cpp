#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	grid = new GridUniverse(GridUniverse::BOUNDED);
	countClick = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::exit()
{
	delete grid;
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
		//grid->initRandom(GridUniverse::Size(5, 5));
		grid->initNull(GridUniverse::Size(5, 5));
		grid->createNewUnit(Point(0, 1));
		grid->createNewUnit(Point(1, 2));
		grid->createNewUnit(Point(2, 0));
		grid->createNewUnit(Point(2, 1));
		grid->createNewUnit(Point(2, 2));
		grid->draw();
		std::cout << "Count unit = " << grid->getPopulation() << std::endl;
		std::cout << "Age universe = " << grid->getAge() << std::endl;
		break;
	default:
		grid->nextGeneration();
		grid->draw();
		std::cout << "Count unit = " << grid->getPopulation() << std::endl;
		std::cout << "Age universe = " << grid->getAge() << std::endl;
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
