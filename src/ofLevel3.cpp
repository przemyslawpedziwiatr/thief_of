#include "ofLevel3.h"

//--------------------------------------------------------------
void ofLevel3::setup(){
	isFinished = false;
	background = ofImage();
	lock = ofImage();
	lockpick = ofImage();

	background.load("door.jpg");
	lock.load("lock.png");
	lockpick.load("lockpick.png");

	lockPos.set(ofGetWidth() / 2, ofGetHeight() / 2);

	ofAddListener(ofEvents().mouseMoved, this, &ofLevel3::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &ofLevel3::mousePressed);
	ofAddListener(ofEvents().keyReleased, this, &ofLevel3::keyReleased);

	lockpickLowerBound = ofRandom(0, 340);
	lockpickUpperBound = lockpickLowerBound + 5;

	hint.load("Holitter_Tittan.ttf", 35, true, true);
	hintText = "Rotate with mouse and click to pick!";


	guessed = false;
}

//--------------------------------------------------------------
void ofLevel3::update(){
	if (!guessed) {
		lockpickPos.set(
			lockPos.x,
			lockPos.y - 115
		);
	}
	else {
		hintText = "Press space to open lock!";
	}
}

//--------------------------------------------------------------
void ofLevel3::draw(){
	background.draw(0, 0);

	ofPushMatrix();
	if (guessed) {
		ofTranslate(lockPos);
		ofRotate(3, 0, 0, 1);
		lock.setAnchorPercent(0.5, 0.5);
		lock.draw(0,0);
	}
	else {
		lock.setAnchorPercent(0.5, 0.5);
		lock.draw(lockPos);
	}
	ofPopMatrix();

	ofPushMatrix();
	ofTranslate(lockpickPos);
	ofRotate(lockpickRotate, 0, 0, 1);
	lockpick.setAnchorPercent(0.5, 0.5);
	lockpick.draw(0,0);
	ofPopMatrix();

	ofSetColor(220, 220, 220);
	hint.drawString(hintText,
		ofGetWidth() /2 - hint.stringWidth(hintText) /2,
		ofGetHeight() - ofGetHeight()/10
	);


}


//--------------------------------------------------------------
void ofLevel3::keyReleased(ofKeyEventArgs& ev){
	if (ev.key == ' ' && guessed) {
		isFinished = true;
	}
}

//--------------------------------------------------------------
void ofLevel3::mouseMoved(ofMouseEventArgs& ev){
	if (!guessed) {
		float mouseProgress = (ev.x / ofGetWidth());
		lockpickRotate = 90 + mouseProgress * 360;
	}
}


//--------------------------------------------------------------
void ofLevel3::mousePressed(ofMouseEventArgs& ev){
	if (ev.button == 0) {
		if (lockpickLowerBound < lockpickRotate - 90 && lockpickUpperBound > lockpickRotate - 90) {
			hintText = "That's right!";
			guessed = true;
		}
		else if (lockpickLowerBound - 10 < lockpickRotate - 90 && lockpickUpperBound + 10 > lockpickRotate - 90) {
			hintText = "Very close...";
		}
		else if (lockpickLowerBound - 25 < lockpickRotate - 90 && lockpickUpperBound + 25 > lockpickRotate - 90) {
			hintText = "We're getting somewhere...";
		}
		else {
			hintText = "Crap! Nothing...";
		}
	}
}
