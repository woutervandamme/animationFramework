/*
 * Mouse.cpp
 *
 *  Created on: May 24, 2014
 *      Author: wouter
 */

#include "Player.h"
#include <cmath>
#include <iostream>
void Player::draw() const{
	glColor3f(this->colour.r, this->colour.g, this->colour.b);
	 glBegin(GL_POLYGON);
	    for (double i = 0; i < 360; i+=2) {
	        double radiaal = i/180*M_PI;
	        glVertex2f(this->center.x + (this->radius*cos(radiaal)), this->center.y + (this->radius*sin(radiaal)));
	    }
	    glEnd();
}
