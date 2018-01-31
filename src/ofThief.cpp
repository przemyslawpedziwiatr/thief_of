#include "ofThief.h"
#include "ofFinish.h"
#include "ofSplash.h"
#include "ofLevel1.h"
#include "ofLevel2.h"
#include "ofLevel3.h"
#include "ofLevel4.h"
#include "ofFinish.h"

enum levels {
	SPLASH,
	LEVEL1,
	LEVEL2,
	LEVEL3,
	LEVEL4,
	FINISH
};

//--------------------------------------------------------------
void ofThief::setup(){
	splash = ofSplash();
	splash.setup();

	level1 = ofLevel1();
	level1.setup();

	level2 = ofLevel2();
	level2.setup();

	level3 = ofLevel3();
	level3.setup();

	level4 = ofLevel4();
	level4.setup();

	finish = ofFinish();
	finish.setup();

	level = SPLASH;
}

//--------------------------------------------------------------
void ofThief::update(){
	checkLevels();

	switch(level) {
		case SPLASH: {
			splash.update();
			break;
		}
		case LEVEL1: {
			level1.update();
			break;
		}
		case LEVEL2: {
			level2.update();
			break;
		}
		case LEVEL3: {
			level3.update();
			break;
		}
		case LEVEL4: {
			level4.update();
			break;
		}
		case FINISH: {
			finish.update();
			break;
		}
	}
}

void ofThief::checkLevels() {
	switch (level) {
		case SPLASH: {
			if (splash.isFinished) {
				level = LEVEL1;
			}
			break;
		}
		case LEVEL1: {
			if (level1.isFinished) {
				level = LEVEL2;
			}
			break;
		}
		case LEVEL2: {
			if (level2.isFinished) {
				level = LEVEL3;
			}
			break;
		}
		case LEVEL3: {
			if (level3.isFinished) {
				level = LEVEL4;
			}
			break;
		}
		case LEVEL4: {
			if (level4.isFinished) {
				level = FINISH;
			}
			break;
		}
	}
}

//--------------------------------------------------------------
void ofThief::draw(){
	switch (level) {
		case SPLASH: {
			splash.draw();
			break;
		}
		case LEVEL1: {
			level1.draw();
			break;
		}
		case LEVEL2: {
			level2.draw();
			break;
		}
		case LEVEL3: {
			level3.draw();
			break;
		}
		case LEVEL4: {
			level4.draw();
			break;
		}
		case FINISH: {
			finish.draw();
			break;
		}
	}
}

