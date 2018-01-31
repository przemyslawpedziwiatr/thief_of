#include "ofThief.h"
#include "ofFinish.h"
#include "ofSplash.h"

enum levels {
	SPLASH,
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	FINISH
};

//--------------------------------------------------------------
void ofThief::setup(){
	splash = ofSplash();
	splash.setup();

	level = SPLASH;
}

//--------------------------------------------------------------
void ofThief::update(){
	checkLevels();

	switch(level) {
		case SPLASH: {
			splash.update();
			break;
		}
	}
}

void ofThief::checkLevels() {
	if (level == SPLASH) {
		if (splash.isFinished) {
			level = LEVEL1;
		}
	}
}

//--------------------------------------------------------------
void ofThief::draw(){
	switch (level) {
		case SPLASH: {
			splash.draw();
			break;
		}
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