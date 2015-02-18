#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    ofSetFrameRate(60);
    ofEnableSmoothing();
    // これが有効だとGUI Panelが表示されない
//    glEnable(GL_DEPTH_TEST);
    
    centerX = ofGetWidth()/2;
    centerY = ofGetHeight()/2;
    centerZ = 500;
    
    // カメラポジション
    cam.setPosition(centerX, centerY, centerZ);
    
    // 注視点の初期値
    lookVec = ofVec3f(centerX, centerY, 0);
    
    // gui
    gui.setup("Camera Postion");
    gui.add(lookAtX.setup("Camera Postion X", centerX, 0, 1000));
    gui.add(lookAtY.setup("Camera Postion Y", centerY, 0, 1000));
    gui.add(lookAtZ.setup("Camera Postion Z", 500, 0, 1000));
}

//--------------------------------------------------------------
void ofApp::update(){
    // カメラの軌道を計算
    theta += 0.01;
    
    ofVec3f upVector;
    upVector.x = (500) * sin(theta) * sin(PI/4) + lookAtX;
    upVector.y = (500) * sin(theta) * cos(PI/4) + lookAtY;
    upVector.z = (500) * cos(theta);
    
    cam.setPosition(upVector.x, upVector.y, upVector.z);

    // 注視点の変更
    cam.lookAt(lookVec, ofVec3f(0,-1,0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black);

    ofSetColor(255);
    cam.begin();
        // 球は常に同じ位置に描画
        shpere.set(100, 16);
        shpere.setPosition(centerX, centerY, 0);
        shpere.drawWireframe();
    cam.end();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}