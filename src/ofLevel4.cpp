#include "ofLevel4.h"

//--------------------------------------------------------------
void ofLevel4::setup(){
	isFinished = false;
	background.load("microphone.jpg");
	
	text.load("Holitter_Tittan.ttf", 35);
	textPlus.load("Holitter_Tittan.ttf", 35, true, true);
	hintPlus = "";

	lastTime = ofGetElapsedTimef();
	frameRateForCapture = 30; // 30 fps  
	elapsedFrames = 0;

	iteration = 1;

	soundStream.setup(this, 0, 2, 44100, BUFFER_SIZE, 4);

	samples = new float[BUFFER_SIZE * 2];
	bandVolumes = new float[N_BANDS * 2];

	hint = "Use sine generator!";
	//ofSetColor(0x666666);
}

//--------------------------------------------------------------
void ofLevel4::update(){
	if (bandValue > 10 && bandValue < 20 && iteration == 1) {
		float timePerFrame = 1.0 / frameRateForCapture;
		float currentTime = ofGetElapsedTimef();
		if (currentTime - lastTime > timePerFrame ) {
			lastTime = currentTime;
			elapsedFrames += 1;
		}

		hint = "Good, hold it for 3 seconds!";

		if (elapsedFrames > 90) {
			hintPlus = "Got first!";
			iteration = 2;
			elapsedFrames = 0;
		}
	}
	else if (bandValue > 20 && bandValue < 30 && iteration == 2) {
		float timePerFrame = 1.0 / frameRateForCapture;
		float currentTime = ofGetElapsedTimef();
		if (currentTime - lastTime > timePerFrame) {
			lastTime = currentTime;
			elapsedFrames += 1;
		}

		hint = "Good, hold it for 3 seconds!";

		if (elapsedFrames > 90) {
			hintPlus = "Got first and second!";
			iteration = 3;
			elapsedFrames = 0;
		}
	}
	else if (bandValue > 30 && iteration == 3) {
		float timePerFrame = 1.0 / frameRateForCapture;
		float currentTime = ofGetElapsedTimef();
		if (currentTime - lastTime > timePerFrame) {
			lastTime = currentTime;
			elapsedFrames += 1;
		}

		hint = "Good, hold it for 3 seconds!";

		if (elapsedFrames > 90) {
			hintPlus = "Great job - but what's in the safe?";
			iteration = 4;
			elapsedFrames = 0;
		}
	}
	else if (iteration == 4) {
		float timePerFrame = 1.0 / frameRateForCapture;
		float currentTime = ofGetElapsedTimef();
		if (currentTime - lastTime > timePerFrame) {
			lastTime = currentTime;
			elapsedFrames += 1;
		}

		if (elapsedFrames > 180) {
			isFinished = true;
		}
	}
	else {
		hint = "Find good frequency, use your phone!";	
		elapsedFrames = 0;
	}
}

//--------------------------------------------------------------
void ofLevel4::draw() {
	background.draw(0, 0);

	
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(200, 150, 0);
	ofNoFill();

	ofSetColor(238, 1, 1, 240);
	ofSetLineWidth(3);

	ofPushMatrix();
	ofTranslate(500, -300);
	ofRotate(90);
	// draw the left channel:
	ofBeginShape();
	for (unsigned int i = 0; i < BUFFER_SIZE; i++) {
		ofVertex(50 + i * 2, 100 - samples[i * 2] * 180.0f);
	}
	ofEndShape(false);

	// draw the right channel:
	ofBeginShape();
	for (unsigned int i = 0; i < BUFFER_SIZE; i++) {
		ofVertex(150 + i * 2, 100 - samples[i * 2 + 1] * 180.0f);
	}
	ofEndShape(false);
	ofPopMatrix();

	bandValue = 0;
	for (int i = 0; i < N_BANDS; i++) {
		//ofLine(50 + (i * 3), 600, 50 + (i * 3), 600 - bandVolumes[i * 2] * 300); //left
		//ofLine(650 + (i * 3), 600, 650 + (i * 3), 600 - bandVolumes[i * 2 + 1] * 300); //right
		bandValue += bandVolumes[i];
	}

	bandValue = (bandValue / N_BANDS) * 100.0f;
	ofDrawBitmapString(ofToString(bandValue), 20, 20);

	

	ofPopMatrix();
	ofPopStyle();

	ofSetColor(220, 220, 220);
	text.drawString(hint,
		ofGetWidth() / 2 - text.stringWidth(hint) / 2,
		ofGetHeight() - ofGetHeight() / 10
	);
	textPlus.drawString(hintPlus,
		ofGetWidth() / 2 - text.stringWidth(hintPlus) / 2,
		0 + ofGetHeight() / 7
	);
}

void ofLevel4::audioReceived(float * input, int bufferSize, int nChannels) {
	// just remember the input to draw waveforms
	for (int i = 0; i < bufferSize * 2; i++) {
		samples[i] = input[i];
	}

	// do the FFT and compute spectrum
	BmFFT::getSimpleSpectrum(BUFFER_SIZE * 2, input, bandVolumes);
	bufferCounter++;
}
//--------------------------------------------------------------
void ofLevel4::keyPressed(int key){

}

//--------------------------------------------------------------
void ofLevel4::keyReleased(int key){

}

//--------------------------------------------------------------
void ofLevel4::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofLevel4::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel4::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel4::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel4::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofLevel4::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofLevel4::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofLevel4::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofLevel4::dragEvent(ofDragInfo dragInfo){ 

}