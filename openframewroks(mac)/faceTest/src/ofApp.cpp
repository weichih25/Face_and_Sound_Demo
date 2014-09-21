#include "ofApp.h"
using namespace ofxCv;
//--------------------------------------------------------------
void ofApp::setup(){
	cam.initGrabber(640, 480);
	tracker.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
        
        mouseWidth = tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH);
        mouseHeight = tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT);
        eyeHeight = (tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT) + tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT))/2;
        faceX = tracker.getPosition().x ;
        faceY = tracker.getPosition().y;
        
        sender.setup(HOST, PORT);
		ofxOscMessage m;
		m.addFloatArg(mouseWidth);
		m.addFloatArg(mouseHeight);
		m.addFloatArg(eyeHeight);
		m.addFloatArg(faceX);
        m.addFloatArg(faceY);
	    sender.sendMessage(m);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0);
	ofSetLineWidth(2);
	tracker.draw();
	ofDrawBitmapString("FPS : " + ofToString((int) ofGetFrameRate()), 10, 20);
    
    ofDrawBitmapString("MOUTH_WIDTH : " + ofToString(mouseWidth) , 10, 50);
    ofDrawBitmapString("MOUTH_HEIGHT) : " + ofToString(mouseHeight) , 10, 62);
    ofDrawBitmapString("EYEBROW_HEIGHT : " + ofToString(eyeHeight) , 10, 74);
    ofDrawBitmapString("FACE_X : " + ofToString(faceX) , 10, 86);
    ofDrawBitmapString("FACE_Y : " + ofToString(faceY) , 10, 98);

    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r') {
		tracker.reset();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
