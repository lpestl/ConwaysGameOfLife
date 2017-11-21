#include "ofApp.h"
#include <iostream>
#include "Unit.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grid = new GridUniverse(GridUniverse::BOUNDED);
	countClick = 0;

	unit1 = new ofGameUnit(Point(0, 0));
	unit2 = new ofGameUnit(Point(1, 1));
	unit3 = new ofGameUnit(Point(3, 1));

	unit1->setup(ofPoint(100, 10), 100, 100, 5, ofColor::red);
	unit2->setup(ofPoint(100, 10), 100, 100, 5, ofColor::red);
	unit3->setup(ofPoint(100, 10), 100, 100, 5, ofColor::red);
}

//--------------------------------------------------------------
void ofApp::update(){
	//if (countClick > 2) {
	//	unit1->update(ofPoint(200, 200), 2);
	//	unit2->update(ofPoint(200, 200), 2);
	//	unit3->update(ofPoint(200, 200), 2);
	//}
	//else if (countClick > 1)
	//{

	//	unit1->update(ofPoint(200, 200), 1);
	//	unit2->update(ofPoint(200, 200), 1);
	//	unit3->update(ofPoint(200, 200), 1);
	//} 
	//else
	//{
	//	unit1->update(ofPoint(100, 10), 1);
	//	unit2->update(ofPoint(100, 10), 1);
	//	unit3->update(ofPoint(100, 10), 1);
	//}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::aqua, ofColor::black, ofGradientMode::OF_GRADIENT_CIRCULAR);
	unit1->draw();
	unit2->draw();
	unit3->draw();
}

void ofApp::exit()
{
	delete unit1;
	delete unit2;
	delete unit3;

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

		unit1->update(ofPoint(100, 10), 1);
		unit2->update(ofPoint(100, 10), 1);
		unit3->update(ofPoint(100, 10), 1);
		break;
	case 1:
		unit1->update(ofPoint(200, 200), 1);
		unit2->update(ofPoint(200, 200), 1);
		unit3->update(ofPoint(200, 200), 1);
		break;
	case 2:
		unit1->update(ofPoint(200, 200), 2);
		unit2->update(ofPoint(200, 200), 2);
		unit3->update(ofPoint(200, 200), 2);
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
