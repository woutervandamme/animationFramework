/*
 * GravityCircle.cpp
 *
 *  Created on: May 21, 2014
 *      Author: wouter
 */

#include "GravityCircle.h"

GravityCircle::GravityCircle(const Point & center, double radius, const Colour & colour, const Vector & velocity)
	:DynamicCircle(center,radius,colour,velocity){
}

void GravityCircle::update(const Scene & scene){
	DynamicCircle::update(scene);
	//gravity goes down duuuh
	Vector gravity(0,-0.1);
	this->setVelocity((this->getVelocity() + gravity));
}

