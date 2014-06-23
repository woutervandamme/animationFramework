/*
 * DynamicCircle.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: wouter
 */

#include <iostream>
#include "shape/DynamicCircle.h"

DynamicCircle::DynamicCircle(const Point & center, double radius, const Colour & colour, const Vector & velocity):Circle(center,radius,colour){
	this->setVelocity(velocity);
}

void DynamicCircle::intersection(DynamicCircle & circle) const{
}

void DynamicCircle::update(const Scene & scene){
	this->setCenter(this->getCenter() + this->velocity);
	std::vector<const IDrawable *> drawables = scene.getDrawables();

	for(std::vector<const IDrawable *>::const_iterator it = drawables.begin(); it != drawables.end(); ++it) {
		const IDrawable * circle = *it;
		circle->intersection(*this);
	}
}




