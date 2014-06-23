/*
 * Shape.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: wouter
 */
#include "Shape.h"

Shape::Shape(Colour a){
	this->setColour(a);
}

void Shape::setColour(Colour a){
	this->colour = a;
}

Colour Shape::getColour(){
	return this->colour;
}



