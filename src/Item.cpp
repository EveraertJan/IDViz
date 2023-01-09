#include "Item.h"


Item::Item(){
}

void Item::setup(string msg){

    cout << "added " << endl;
    message = msg;
    font.load("DIN-Regular.ttf", 10);

    vector<string> splitted = ofSplitString( message, ",");
    date = splitted[0];
    vector<string> spl = ofSplitString(splitted[1], "-");

    timeDSP = ofToInt(spl[0]);
    classifications = ofToInt(spl[1]);
    anomaly = ofToInt(spl[2]);

    c1 = ofToFloat(splitted[2]);
    c2 = ofToFloat(splitted[3]);
    c3 = ofToFloat(splitted[4]);
}


void Item::draw() {
    ofPushMatrix();
    ofSetColor(0);
    font.drawString(date, 0, 0);
    font.drawString(ofToString(timeDSP), 280, 0);
    font.drawString(ofToString(classifications), 320, 0);
    font.drawString(ofToString(anomaly), 340, 0);
      
    if(c1 > c2 && c1 > c3) {
      ofDrawRectangle(380, -5, 10, 10);
    }
    if(c2 > c1 && c2 > c3) {
      ofDrawRectangle(420, -5, 10, 10);
    }
    if(c3 > c1 && c3 > c2) {
      ofDrawRectangle(460, -5, 10, 10);
    }

    ofPopMatrix();
}