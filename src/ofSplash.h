#pragma once

#include "ofMain.h"

class ofSplash : public ofBaseApp{
	public:
		void setup();
		void draw();
		
		bool isFinished;

		ofTrueTypeFont textTitle;
		ofTrueTypeFont textInstructions;
		
		int titleColorPulse;
		void drawTitle();
		void drawInstruction();

		void keyReleased(ofKeyEventArgs&);
};
