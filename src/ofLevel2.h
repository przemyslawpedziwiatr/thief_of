#pragma once

#include "ofMain.h"

class ofLevel2 : public ofBaseApp{
	public:
		void setup();
		void createCandle();
		void createFlame();
		void randomCandlePosition();
		void update();
		int checkBlowAmount();
		void manageMicrophone();
		void draw();
		
		bool isFinished;

		ofImage background;

		ofVec2f flamePos, candlePos;
		std::vector<ofImage> flames;
		ofImage candle;

		int flameno;
		int counter;
		int counterlimit;

		int iteration;

		// audio 

		vector <float> lAudio;
		vector <float> rAudio;

		void audioIn(float * input, int bufferSize, int nChannels);

		vector <float> left;
		vector <float> right;
		vector <float> volHistory;

		int 	bufferCounter;
		int 	drawCounter;

		float smoothedVol;
		float scaledVol;

		ofSoundStream soundStream;

		float frameRateForCapture;
		float lastTime;
		int elapsedFrames;
		bool checkVolume;

		ofTrueTypeFont text;
		string hint;

		void keyPressed(int key);
		void keyReleased(int key);
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
