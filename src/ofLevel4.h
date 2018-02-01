#pragma once

#include "ofMain.h"
#include "bmFFT.h"
#define BUFFER_SIZE 512
#define N_BANDS 9

class ofLevel4 : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		bool isFinished;
		int iteration;

		ofTrueTypeFont text, textPlus;
		string hint;
		string hintPlus;

		float frameRateForCapture;
		float lastTime;
		int elapsedFrames;
		bool checkVolume;

		float bandValue;
		ofImage background;

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

		void audioReceived(float * input, int bufferSize, int nChannels);
private:
	float* samples;
	float* bandVolumes;
	int bufferCounter;

	ofSoundStream soundStream;
};
