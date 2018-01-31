#include "ofThief.h"
#include "ofFinish.h"
#include "ofSplash.h"

//--------------------------------------------------------------
void ofThief::setup(){
	splash = ofSplash();
	splash.setup();

	currentLevel = "splash";
}

//--------------------------------------------------------------
void ofThief::update(){
	if (currentLevel == "splash") {
		splash.update();
	}
}

//--------------------------------------------------------------
void ofThief::draw(){
	if (currentLevel == "splash") {
		splash.draw();
	}
}

//--------------------------------------------------------------
void ofThief::keyPressed(int key){

}

//--------------------------------------------------------------
void ofThief::keyReleased(int key){

}

//--------------------------------------------------------------
void ofThief::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofThief::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofThief::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofThief::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofThief::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofThief::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofThief::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofThief::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofThief::dragEvent(ofDragInfo dragInfo){ 

}