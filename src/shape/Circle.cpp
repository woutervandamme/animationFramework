/*
 * Circle.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: wouter
 */

#include "Circle.h"
#include <cmath>
#include "shape/DynamicCircle.h"
#include <iostream>
Circle::Circle( const Point& center, double radius, const Colour& colour):Shape(colour),center(center),radius(radius){}


void Circle::intersection(DynamicCircle & dcircle) const{

	double distance = center.distance(dcircle.center);

	if(distance < radius + dcircle.radius){

		double a,b,c,d,t;
		Vector u(center,dcircle.center);

		a = dcircle.getVelocity().getDot(dcircle.getVelocity());
		b = 2*(dcircle.getVelocity().getDot(u));
		c = u.getDot(u) - pow(dcircle.radius + radius,2);
		d = (b*b) - 4*a*c;
		t = (-b - sqrt(d)) / (2*a);

		dcircle.setCenter(dcircle.center + t*dcircle.getVelocity());
		Vector u2(center,dcircle.center);
		u2 = u2.normalize();
//		std::cout << "oude snelheid: " << dcircle.getVelocity().getLength() << "\n";
		Vector test(dcircle.getVelocity() - 2*(dcircle.getVelocity().getDot(u2))*u2);
		dcircle.setVelocity(test);
//		std::cout << "nieuwe snelheid: " << dcircle.getVelocity().getLength() << "\n";
	}
}


void Circle::draw() const{

	glColor3f(this->colour.r, this->colour.g, this->colour.b);
	 glBegin(GL_POLYGON);
	    for (double i = 0; i < 360; i+=2) {
	        double radiaal = i/180*M_PI;
	        glVertex2f(this->center.x + (this->radius*cos(radiaal)), this->center.y + (this->radius*sin(radiaal)));
	    }
	    glEnd();
}




