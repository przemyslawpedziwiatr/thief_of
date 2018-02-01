#include "ofFinish.h"

//--------------------------------------------------------------
void ofFinish::setup(){
	isFinished = false;
	background.load("safe-open.jpg");

	prices.push_back("New\ntracksuit!");
	prices.push_back("Great\ngrades!");
	prices.push_back("Holidays\nin\nMorocco!");
	prices.push_back("Absolutetly\nnothing!");
	prices.push_back("Golf 3!");
	prices.push_back("A skateboard?!");
	prices.push_back("Chuck\nNorris's\nhandshake!");
	prices.push_back("Volkswagen\nPassat!");

	price.load("Holitter_Tittan.ttf", 90);
	wonPrice = ofRandom(0, prices.size()-1);
}

//--------------------------------------------------------------
void ofFinish::update(){

}

//--------------------------------------------------------------
void ofFinish::draw(){
	background.draw(0, 0);

	string actualPrice = prices[wonPrice];

	ofPushStyle();
	ofSetColor(ofRandom(125, 250), ofRandom(125, 250), ofRandom(125, 250));
	price.drawString("Stolen:\n" + actualPrice,
		-(price.stringWidth("Stolen:\n" + actualPrice) / 2) + ofGetWidth() / 2,
		ofGetHeight() / 5);
	ofPopStyle();
}

//--------------------------------------------------------------
void ofFinish::keyPressed(int key){

}

//--------------------------------------------------------------
void ofFinish::keyReleased(int key){

}

//--------------------------------------------------------------
void ofFinish::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofFinish::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofFinish::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofFinish::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofFinish::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofFinish::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofFinish::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofFinish::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofFinish::dragEvent(ofDragInfo dragInfo){ 

}