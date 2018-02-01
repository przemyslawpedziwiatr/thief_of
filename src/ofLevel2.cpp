#include "ofLevel2.h"

//--------------------------------------------------------------
void ofLevel2::setup(){
	isFinished = false;
	background.load("room.jpg");
	createCandle();
	createFlame();
	randomCandlePosition();

	text.load("Holitter_Tittan.ttf", 35);
	hint = "Blow on your computer!\nBigger flame = blow harder!";

	flameno = 0;
	counter = 0;
	counterlimit = 50;

	iteration = 1;

	lastTime = ofGetElapsedTimef();
	frameRateForCapture = 30; // 30 fps  
	elapsedFrames = 0;

	int bufferSize = 16;

	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);

	bufferCounter = 0;
	drawCounter = 0;
	smoothedVol = 0.0;
	scaledVol = 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

	checkVolume = true;
}


//--------------------------------------------------------------
void ofLevel2::update(){
	//lets scale the vol up to a 0-1 range 
	if (checkVolume) {
		scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	}
	else {
		scaledVol = 0;
	}

	manageMicrophone();
	std::cout << ofToString(scaledVol) << " and " << ofToString(smoothedVol) << "\n";

	switch (iteration) {
		case 1: {
			int blow = checkBlowAmount();
			if (blow > 25) {
				iteration += 1;
				randomCandlePosition();
				checkVolume = false;
				elapsedFrames = 0;
			}
			break;
		}
		case 2: {
			int blow = checkBlowAmount();
			if (blow > 55) {
				iteration += 1;
				randomCandlePosition();
				checkVolume = false;
				elapsedFrames = 0;
			}
			break;
		}
		case 3: {
		
			int blow = checkBlowAmount();
			if (blow > 87) {
				iteration += 1;
				checkVolume = false;
				elapsedFrames = 0;
			}
			break;
		}
		case 4: {
			isFinished = true;
		}
	}
}

int ofLevel2::checkBlowAmount() {
	return scaledVol * 100.0;
}

void ofLevel2::manageMicrophone() {
	float timePerFrame = 1.0 / frameRateForCapture;
	float currentTime = ofGetElapsedTimef();
	if (currentTime - lastTime > timePerFrame && checkVolume == false) {
		lastTime = currentTime;
		elapsedFrames += 1;
	}

	if (elapsedFrames > 20) {
		checkVolume = true;
	}
}

//--------------------------------------------------------------
void ofLevel2::draw(){
	ofPushMatrix();

	background.setAnchorPercent(0.5, 0.5);
	ofPushStyle();
	ofSetColor(255, 255, 255, 250 - (iteration*75));
	background.draw(ofGetWidth() / 2, ofGetHeight() / 2);
	ofPopStyle();

	candle.setAnchorPercent(0.5, 0.5);
	candle.draw(candlePos);

	flames[flameno].setAnchorPercent(0.5, 0.5);
	flames[flameno].draw(flamePos);

	flames[flameno].resize(
		100 * (iteration),
		100 * (iteration)
	);

	counter++;
	if (counter >= counterlimit) {
		counter = 0;
		flameno += 1;
		if (flameno > 2) flameno = 0;
	}	

	ofPopMatrix();


	ofPushStyle();
	ofSetColor(220, 220, 220);
	text.drawString(hint,
		ofGetWidth() / 2 - text.stringWidth(hint) / 2,
		ofGetHeight() - ofGetHeight() / 8
	);
	ofPopStyle();
}

void ofLevel2::createCandle() {
	candle.load("candle.png");
}

void ofLevel2::createFlame() {
	for (int i = 0; i < 3; i++) {
		ofImage flame = ofImage();
		flame.load("flame-" + ofToString(i + 1) + ".png");
		flames.push_back(flame);
	}
}

void ofLevel2::randomCandlePosition() {
	candlePos.set(
		ofRandom(100, ofGetWidth() - 100),
		ofRandom(ofGetHeight() - 160, ofGetHeight() - 250)
	);

	flamePos.set(
		candlePos.x,
		candlePos.y - 200
	);
}

void ofLevel2::audioIn(float * input, int bufferSize, int nChannels) {

	float curVol = 0.0;

	// samples are "interleaved"
	int numCounted = 0;

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++) {
		left[i] = input[i * 2] * 0.5;
		right[i] = input[i * 2 + 1] * 0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted += 2;
	}

	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;

	// this is how we get the root of rms :) 
	curVol = sqrt(curVol);

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;

	bufferCounter++;

}




//--------------------------------------------------------------
void ofLevel2::keyPressed(int key){

}

//--------------------------------------------------------------
void ofLevel2::keyReleased(int key){

}

//--------------------------------------------------------------
void ofLevel2::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofLevel2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel2::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel2::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofLevel2::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofLevel2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofLevel2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofLevel2::dragEvent(ofDragInfo dragInfo){ 

}