#pragma once

#include "ofMain.h"

class Item {
  
  public:

    string message;
    string date;

    int timeDSP;
    int classifications;
    int anomaly;

    float c1;
    float c2;
    float c3;

    
    ofTrueTypeFont    font;

    Item();
    void setup(string message);
    void draw();
};

