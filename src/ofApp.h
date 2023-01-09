#pragma once

#include "ofMain.h"
#include "ofxSimpleSerial.h"

#include "Item.h"

class ofApp : public ofBaseApp{
	
	public:

		string message;

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void onNewMessage(string & message);
		
		ofTrueTypeFont		font;
		ofxSimpleSerial serial;
		bool requestRead;


		bool recording = false;
		vector<Item> items;
};

