#include "ofSplash.h"

//--------------------------------------------------------------
void ofSplash::setup(){
	textTitle.load("Holitter_Tittan.ttf", 70, true, true);
	textInstructions.load("Holitter_Tittan.ttf", 35, true, true);
	ofBackground(0, 0, 0);
	titleColorPulse = 0;

	isFinished = false;

	ofAddListener(ofEvents().keyReleased, this, &ofSplash::keyReleased);
}

//--------------------------------------------------------------
void ofSplash::draw(){
	drawTitle();
	drawInstruction();
}

void ofSplash::drawTitle() {
	titleColorPulse = ofRandom(125, 250);
	ofSetColor(titleColorPulse);
	textTitle.drawString("Thief",
		-(textTitle.stringWidth("Thief") / 2) + ofGetWidth() / 2,
		ofGetHeight() / 4);
}

void ofSplash::drawInstruction() {
	ofSetColor(240);
	string lines[5] = { "Run, crack, hack and hide!" ,
					   "Open the safe!",
						"Steal your biggest desire!",
						" ",
						"Press space to begin!"
						};
	for (int i = 0; i < 5; i++) {
		std::cout << i << "\n";
		textInstructions.drawString(lines[i],
			-(textInstructions.stringWidth(lines[i]) / 2) + ofGetWidth() / 2,
			ofGetHeight() / 2 + (i*50) );
	}
}

//--------------------------------------------------------------
void ofSplash::keyReleased(ofKeyEventArgs& eventArgs){
	if (eventArgs.key == ' ') {
		isFinished = true;
	}
}
