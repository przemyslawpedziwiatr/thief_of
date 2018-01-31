#pragma once

#include "ofMain.h"
#include "ofSplash.h"
#include "ofLevel1.h"
#include "ofLevel2.h"
#include "ofLevel3.h"
#include "ofLevel4.h"
#include "ofFinish.h"

class ofThief : public ofBaseApp{
	public:
		void setup();
		void update();
		void checkLevels();
		void draw();
		
		ofSplash splash;
		ofLevel1 level1;
		ofLevel2 level2;
		ofLevel3 level3;
		ofLevel4 level4;
		ofFinish finish;

		int level;
};
