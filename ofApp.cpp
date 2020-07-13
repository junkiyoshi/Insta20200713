#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int x = 140; x <= ofGetWidth(); x += 220) {

		for (int y = 140; y <= ofGetHeight(); y += 220) {

			ofPushMatrix();
			ofTranslate(x, y);

			for (int k = 0; k < 5; k++) {

				auto noise_seed_deg = ofRandom(1000);
				auto noise_seed_radius = ofRandom(1000);

				vector<glm::vec2> vertices;
				for (int i = 0; i < 25; i++) {

					auto noise_deg = ofMap(ofNoise(noise_seed_deg, (ofGetFrameNum() + i) * 0.001), 0, 1, -360, 360);
					auto noise_radius = ofMap(ofNoise(noise_seed_radius, (ofGetFrameNum() + i) * 0.01), 0, 1, -100, 100);
					vertices.push_back(glm::vec2(noise_radius * cos(noise_deg * DEG_TO_RAD), noise_radius * sin(noise_deg * DEG_TO_RAD)));
				}

				for (int i = 0; i < 10; i++) {

					ofRotateZ(36);

					ofBeginShape();
					ofVertices(vertices);
					ofEndShape();
				}
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}