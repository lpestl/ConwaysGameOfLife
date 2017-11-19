#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	grid = new GridUniverse(GridUniverse::LOOPED);
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
		grid->initNull(GridUniverse::Size(3, 3));
		grid->draw();
		break;
	case 1:
		grid->initRandom(GridUniverse::Size(3, 3));
		grid->draw();
		break;
	case 2:
		std::cout << "Count unit = " << grid->getPopulation() << std::endl;
		break;
	case 3:
		grid->nextGeneration();
		grid->nextGeneration();
		std::cout << "Age universe = " << grid->getAge() << std::endl;
		break;
	case 4:
		break;
	default:
		grid->initRandom(GridUniverse::Size(3, 3));
		grid->draw();
		std::cout << "Count unit = " << grid->getPopulation() << std::endl;
		grid->nextGeneration();
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
