/*
 * Circle.h
 *
 *  Created on: Apr 25, 2014
 *      Author: wouter
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "util/Point.h"
#include "shape/Shape.h"

class DynamicCircle;

class Circle : public Shape{

protected:
	Point center;
	double radius;
public:
	Circle(const Point & center, double radius, const Colour & colour);
	Point getCenter() const { return center; }
	void setCenter(const Point & center){ this->center = center;}
	double getRadius() const { return radius;}
	void setRadius(double radius){this->radius = radius;}
	virtual void draw() const;
	virtual void intersection(DynamicCircle & circle) const;
};

#endif /* CIRCLE_H_ */
