#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetVerticalSync(true);
  ofBackground(255);  
  ofSetLogLevel(OF_LOG_VERBOSE);
  
  font.load("DIN.otf", 64);
  
  int baud = 115200;
  serial.setup(0, baud); //open the first device
  //serial.setup("/dev/ttyUSB0", baud); //linux example
  serial.startContinuousRead();
  ofAddListener(serial.NEW_MESSAGE, this, &ofApp::onNewMessage);

  message = "";
}

//--------------------------------------------------------------
void ofApp::update(){
  if(requestRead) {
    serial.sendRequest();
    requestRead = false;
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(0);  
  font.drawString(ofToString(items.size()), 50, 100);

  for(int i = 0; i < items.size(); i++) {
    ofPushMatrix();
    ofTranslate(0, i * 20);
    items[i].draw();
    ofPopMatrix();
  }
}


//--------------------------------------------------------------
void ofApp::onNewMessage(string & message){

  if(
    message != "time,timingDSP-classification-anomaly,c1,c2,c3," &&
    message != " " &&
    message != "ping" &&
    message != "done" &&
    message != "begin" &&
    message != ""
  ) {

    if(!recording) {
      items.clear();
      recording = true;
    }
    cout << message << endl;
    vector<string> splitted = ofSplitString( message, ",");
    cout << splitted.size() << endl;
    if(splitted.size() == 6) {
      Item i;
      i.setup(message);
      items.push_back(i); 
    }
  }
  if(message == "begin") {
    recording = false;
    cout << "end of message" << endl;
  }
  if(message == "done") {
    recording = false;
    cout << "end of message" << endl;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
  requestRead = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
  
}

