#include "ofLevel1.h"

//--------------------------------------------------------------
void ofLevel1::setup(){
	isFinished = false;
	background.load("building-woods.jpg");
	iteration = 1;
	ofAddListener(ofEvents().keyReleased, this, &ofLevel1::keyReleased);

	text.load("Holitter_Tittan.ttf", 35);
	hint = "Use arms to move leaves aside!";

	leavesAmount = 30;;
	pushLeaves();

	lastTime = ofGetElapsedTimef();
	resizeSteps = 0;
	frameRateForCapture = 60; // 30 fps  

	// camera 

	size_x = 300;
	size_y = 200;
	ratio = 4;

	vidGrabber.setup(size_x, size_y);

	colorImg.allocate(size_x, size_y);
	diffImg.allocate(size_x, size_y);
	previousFrame.allocate(size_x, size_y);
	threshold = 10;

	
}
	
void ofLevel1::pushLeaves() {
	for (int i = 0; i < leavesAmount; i++) {
		ofImage leaf = ofImage();
		string name = "leaf-" + ofToString((int)ofRandom(1, 4)) + ".png";
		leaf.load(name);
		leafes.push_back(leaf);

		ofVec2f position = ofVec2f();
		if (i < leavesAmount /2) {
			position.set(ofRandom(0, ofGetWidth() / 2),
				ofRandom(0, ofGetHeight()) - 50);
		}
		else {
			position.set(ofRandom(ofGetWidth() / 2, ofGetWidth()),
				ofRandom(50, ofGetHeight() - 50));
		}
		leafesPoints.push_back(position);
	}
}
//--------------------------------------------------------------
void ofLevel1::update(){
	bool bNewFrame = false;

	vidGrabber.update();
	bNewFrame = vidGrabber.isFrameNew();

	colorImg.setFromPixels(vidGrabber.getPixels());

	if (bNewFrame && previousFrame.bAllocated) {
		grayImg = colorImg;

		diffImg.absDiff(grayImg, previousFrame);
		diffImg.threshold(threshold);

		ofPixels pixels = diffImg.getPixels();

		for (int leafIndex = 0; leafIndex < leafesPoints.size(); leafIndex++) {
			int moveAmount = 0;
			
			ofVec2f leaf = leafesPoints[leafIndex];

			int posx = leaf.x;
			int posy = leaf.y;

			int pixelValue = pixels[abs(posy/ratio)*(ofGetWidth()/ratio) + abs(posx/ratio)];

			if (pixelValue > 200) {
				if (leaf.x < ofGetWidth() / 2) {
					leafesPoints[leafIndex].x -= 35;
				}
				else {
					leafesPoints[leafIndex].x += 35;
				}
			}
		}
	}

	previousFrame = colorImg;

	switch (iteration) {
		case 1: {
			int leafesOut = checkLeavesOut();
			if (leafesOut > leavesAmount * 0.50) {
				iteration += 1;
				resetLeaves();
			}
			break;
		}
		case 2: {
			int leafesOut = checkLeavesOut();
			if (leafesOut > leavesAmount * 0.70) {
				iteration += 1;
				resetLeaves();
				resizeSteps = 0;
			}
			break;
		}
		case 3: {
			int leafesOut = checkLeavesOut();
			if (leafesOut > leavesAmount * 0.85) {
				iteration += 1;
			}
			break;
		}
		case 4: {
			isFinished = true;
			break;
		}
	}
}

void ofLevel1::resetLeaves() {
	leafes.clear();
	leafesPoints.clear();
	pushLeaves();
}

int ofLevel1::checkLeavesOut() {
	int leavesOut = 0;
	for (int i = 0; i < leafesPoints.size(); i++) {
		if (leafesPoints[i].x < 100 || leafesPoints[i].x > ofGetWidth() - 100) {
			leavesOut += 1;
		}
	}
	return leavesOut;
}

//--------------------------------------------------------------
void ofLevel1::draw(){
	diffImg.draw(0, 0, 1200, 800);
	ofSetColor(255, 255, 255, 200);
	ofPushMatrix();
	background.setAnchorPercent(0.5, 0.5);
	background.draw(ofGetWidth()/2, ofGetHeight()/2);
	ofPopMatrix();

	ofPushMatrix();
	for (int i = 0; i < leafes.size(); i++) {
		leafes[i].setAnchorPercent(0.5, 0.5);
		leafes[i].draw(leafesPoints[i]);
	}
	ofPopMatrix();

	if (iteration == 1) {

	}
	else if (iteration == 2) {
		stepCloser();
	}
	else if (iteration == 3) {
		stepCloser();
	}

	ofPushStyle();
	ofSetColor(220, 220, 220);
	text.drawString(hint,
		ofGetWidth() / 2 - text.stringWidth(hint) / 2,
		ofGetHeight() - ofGetHeight() / 10
	);
	ofPopStyle();
}

void ofLevel1::stepCloser() {
	float timePerFrame = 1.0 / frameRateForCapture;
	float currentTime = ofGetElapsedTimef();
	if (currentTime - lastTime > timePerFrame && resizeSteps < 10) {
		resizeSteps++;
		int width = background.getWidth();
		int height = background.getHeight();
		ofPushMatrix();
		background.setAnchorPercent(0.5, 0.5);
		background.resize(width + 9, height + 5);
		ofPopMatrix();
		lastTime = currentTime;
	}
}
//--------------------------------------------------------------
void ofLevel1::keyPressed(int key){

}

//--------------------------------------------------------------
void ofLevel1::keyReleased(ofKeyEventArgs& ev){

}

//--------------------------------------------------------------
void ofLevel1::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofLevel1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofLevel1::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofLevel1::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofLevel1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofLevel1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofLevel1::dragEvent(ofDragInfo dragInfo){ 

}