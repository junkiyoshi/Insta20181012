#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	void Upate();
	void Draw();
	
private:

	ofPoint make_point();

	float radius;
	float deg;
	float small_radius;
	float small_deg;

	float deg_step;
	float small_deg_step;

	std::deque<ofPoint> logs;
};