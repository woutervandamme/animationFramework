/*
 * Flock.cpp
 *
 *  Created on: May 21, 2014
 *      Author: wouter
 */

#include "Flock.h"
#include <vector>
#include "util/Point.h"
void Flock::draw() const{
	for(std::vector<Boid * >::const_iterator it = boids.begin(); it != boids.end(); ++it) {
			Boid * boid = *it;
			boid->draw();
	}
}

void Flock::update(const Scene & scene){
	for(std::vector<Boid * >::iterator it = boids.begin(); it != boids.end(); ++it) {
		 	int index = it - boids.begin();
		 	Vector v = rule1(index) + rule2(index) + rule3(index);
		 	v = v * damping;
			Boid * boid = *it;
		 	v = v + boid->getVelocity();

		 	if(v.getLength() > maxSpeed){
		 		v = v * (maxSpeed/v.getLength());
		 	}

			Point p = boid->getCenter();
			double wind = 0.12;
			Vector windVector;
			if(p.x> 900 ){
				windVector = Vector(-wind,0);
			} else if(p.x< 150 ){
				windVector = Vector(wind,0);
			} else if(p.y> 350 ){
				windVector = Vector(0,-wind);
			} else if(p.y< 150 ){
				windVector = Vector(0,wind);
			}

			boid->setVelocity(v + windVector);
		 	boid->setCenter(boid->getCenter() + boid->getVelocity());
	}
}


Vector Flock::rule1(unsigned index){
	Point flockCenter;
	for(std::vector<Boid * >::iterator it = boids.begin(); it != boids.end(); ++it) {
		if(*it != boids.at(index)){
			Boid * boid = *it;
			flockCenter = flockCenter+boid->getCenter();
		}
	}
	flockCenter /= boids.size();
	Vector v(boids.at(index)->getCenter(),flockCenter);
	v = v*cohesion;
	return v;
}

Vector Flock::rule2(unsigned index){
	Vector res;

	for(std::vector<Boid * >::iterator it = boids.begin(); it != boids.end(); ++it) {
		if(*it != boids.at(index)){
			Boid * boid = *it;
			if(boid->getCenter().distance(boids.at(index)->getCenter()) < separation){
				Vector v(boid->getCenter(),boids.at(index)->getCenter());
				double factor = separation / (v.getLength() * v.getLength());
				if(factor > 100){ factor = 100; } ;
				v = v * factor;
				res = res +  v;
			}
		}
	}
	return res;
}

Vector Flock::rule3(unsigned index){
	Vector avVelocity;
	for(std::vector<Boid * >::iterator it = boids.begin(); it != boids.end(); ++it) {
		if(*it != boids.at(index)){
			Boid * boid = *it;
			avVelocity = avVelocity+boid->getVelocity();
		}
	}
	avVelocity /= boids.size();
	Vector v = avVelocity - boids.at(index)->getVelocity();

	v = v*alignment;
	return v;
}


