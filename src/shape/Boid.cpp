/*
 * Boid.cpp
 *
 *  Created on: May 14, 2014
 *      Author: wouter
 */

#include "Boid.h"
#include <cmath>
#include <iostream>

Boid::Boid(const Point & center, const Colour & colour, const Vector & velocity,double size):Shape(colour){
	this->setCenter(center);
	this->setVelocity(velocity);
	this->setSize(size);
}


void Boid::intersection(DynamicCircle & circle) const{

}

void Boid::update(const Scene & scene){
	// "wind"
	this->setCenter(this->getCenter() + this->velocity);
	Point p = this->getCenter();
	double wind = 0.04;
	Vector windVector;
	if(p.x> 850 ){
		windVector = Vector(-wind,0);
	} else if(p.x< 150 ){
		windVector = Vector(wind,0);
	} else if(p.y> 350 ){
		windVector = Vector(0,-wind);
	} else if(p.y< 150 ){
		windVector = Vector(0,wind);
	}
	this->setVelocity(this->getVelocity() + windVector);

}

void Boid::draw() const{
	Vector v = this->getVelocity();
	Vector u(1,0);
	double angle = (atan2(v.y,v.x) - atan2(u.y,u.x));
	Point p1(center.x+size*cos(angle),center.y+size*sin(angle));
	Point p2(center.x+size*cos(angle+2.61799387799),center.y+size*sin(angle+2.61799387799));
	Point p3(center.x+size*cos(angle+3.66519142919),center.y+size*sin(angle+3.66519142919));

	glBegin(GL_TRIANGLES);
		glColor3f(this->colour.r, this->colour.g, this->colour.b);
	    glVertex2d(p1.x, p1.y);
	    glVertex2d(p2.x, p2.y);
	    glVertex2d(p3.x, p3.y);
	glEnd();
}



