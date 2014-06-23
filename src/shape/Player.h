/*
 * Mouse.h
 *
 *  Created on: May 24, 2014
 *      Author: wouter
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "IDrawable.h"
#include "shape/Shape.h"
#include "util/Point.h"
class Player : public Shape{
	Point center;
	double radius;
public:
	Player(const Colour & colour,double radius = 5):Shape(colour),radius(radius){}

	Point getCenter() const { return center; }
	void setCenter(const Point & center){ this->center = center;}
	double getRadius() const { return radius;}
	void setRadius(double radius){this->radius = radius;}

	virtual void draw() const;
	virtual void intersection(DynamicCircle & circle) const{}
};

#endif /* MOUSE_H_ */
