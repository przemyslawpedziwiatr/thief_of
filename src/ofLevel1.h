#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO		

class ofLevel1 : public ofBaseApp{
	public:
		int size_x, size_y;

		ofVideoGrabber 		vidGrabber;

		ofxCvColorImage			colorImg;
		ofxCvGrayscaleImage		grayImg;
		ofxCvGrayscaleImage		diffImg;
		ofxCvGrayscaleImage		previousFrame;
		int 				threshold;
		bool				bLearnBakground;
		float ratio;

		void setup();
		void pushLeaves();
		void update();
		void resetLeaves();
		int checkLeavesOut();
		void draw();

		void stepCloser();
		
		bool isFinished;

		ofImage background;
		
		std::vector<ofImage> leafes;
		std::vector<ofVec2f> leafesPoints;

		int iteration;
		int leavesAmount;

		float frameRateForCapture;
		float lastTime;
		int resizeSteps;

		void keyReleased(ofKeyEventArgs&);

		void keyPressed(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
