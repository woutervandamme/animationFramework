/*
 * DynamicCircle.h
 *
 *  Created on: Apr 27, 2014
 *      Author: wouter
 */

#ifndef DYNAMICCIRCLE_H_
#define DYNAMICCIRCLE_H_
#include "util/Vector.h"
#include "scene/Scene.h"
#include "shape/IAnimatable.h"
#include "util/Colour.h"
#include "shape/Circle.h"

class DynamicCircle : public IAnimatable, public Circle{
private:
	Vector velocity;
public:
	DynamicCircle(const Point & center, double radius, const Colour & colour, const Vector & velocity);
	const Vector & getVelocity() const {	return this->velocity;}
	void setVelocity(Vector velo){ this->velocity = velo;}
	void update(const Scene & scene);
	void intersection(DynamicCircle & circle) const;
};

#endif /* DYNAMICCIRCLE_H_ */
