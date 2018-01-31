#pragma once

#include "ofMain.h"

class ofLevel3 : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		bool isFinished;
		
		ofTrueTypeFont hint;
		string hintText;

		bool guessed;

		ofImage background, lock, lockpick;
		ofVec2f lockPos, lockpickPos;
		int lockpickRotate, lockpickLowerBound, lockpickUpperBound;

		void keyReleased(ofKeyEventArgs& ev);
		void mouseMoved(ofMouseEventArgs& ev);
		void mousePressed(ofMouseEventArgs& ev);
};
