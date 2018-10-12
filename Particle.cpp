#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle() {
	
	this->radius = 300;
	this->deg = (int)(ofRandom(360) / 10) * 10;
	this->small_radius = 80;
	this->small_deg = (int)(ofRandom(360) / 20) * 20;
}

//--------------------------------------------------------------
Particle::~Particle() {

}

//--------------------------------------------------------------
void Particle::Upate() {

	if (ofGetFrameNum() % 20 == 0) {

		int r = ofRandom(4);
		switch (r) {
		case 0:

			this->deg_step = 0.5;
			this->small_deg_step = 0.0;
			break;
		case 1:

			this->deg_step = -0.5;
			this->small_deg_step = 0.0;
			break;
		case 2:

			this->deg_step = 0.0;
			this->small_deg_step = 1.0;
			break;
		case 3:

			this->deg_step = 0.0;
			this->small_deg_step = -1.0;
			break;
		default:

			this->deg_step = 0.0;
			this->small_deg_step = 0.0;
			break;
		}
	}

	this->deg += this->deg_step;
	this->small_deg += this->small_deg_step;

	ofPoint point = this->make_point();
	this->logs.push_front(point);
	while (this->logs.size() > 45) { this->logs.pop_back(); }

}

//--------------------------------------------------------------
void Particle::Draw() {

	ofFill();
	ofDrawSphere(this->logs.front(), 3);

	ofNoFill();
	ofBeginShape();
	for (ofPoint& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}

//--------------------------------------------------------------
ofPoint Particle::make_point() {

	float x_1 = this->radius * cos(this->deg * DEG_TO_RAD);
	float y_1 = this->radius * sin(this->deg * DEG_TO_RAD);

	float x_2 = this->small_radius * cos(this->small_deg * DEG_TO_RAD) * cos(this->deg * DEG_TO_RAD);
	float y_2 = this->small_radius * cos(this->small_deg * DEG_TO_RAD) * sin(this->deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = this->small_radius * sin(this->small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}