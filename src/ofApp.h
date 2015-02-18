#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    private:
        int centerX;
        int centerY;
        int centerZ;
        float theta;
    
        // 注視点
        ofVec3f lookVec;
        ofCamera cam;
        ofSpherePrimitive shpere;
    public:
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);    
    
        ofxPanel gui;
        ofxIntSlider lookAtX;
        ofxIntSlider lookAtY;
        ofxIntSlider lookAtZ;

};
