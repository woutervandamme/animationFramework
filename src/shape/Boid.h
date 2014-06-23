/*
 * Boid.h
 *
 *  Created on: May 14, 2014
 *      Author: wouter
 */

#ifndef BOID_H_
#define BOID_H_
#include "shape/Shape.h"
#include "shape/IAnimatable.h"
#include "util/Vector.h"

class Boid : public IAnimatable, public Shape {
private:
	double size;
	Vector velocity;
	Point center;
public:
	Boid(const Point & center, const Colour & colour, const Vector & velocity,double size);
	virtual ~Boid(){}
	double getSize() const {return size;}
	const Vector & getVelocity() const {	return velocity;}
	const Point & getCenter() const { return center; }
	void setCenter(const Point & center){ this->center = center;}
	void setVelocity(const Vector & velocity){ this->velocity = velocity;}
	void setSize(double size){this->size = size;}

	virtual void intersection(DynamicCircle & circle) const;
	virtual void update(const Scene & scene);
	virtual void draw() const;
};

#endif /* BOID_H_ */
