/*
 * WorldWindow.cpp
 *
 *  Created on: May 8, 2014
 *      Author: wouter
 */


#include "scene/WorldWindow.h"
#include "shape/DynamicCircle.h"

void WorldWindow::intersection(DynamicCircle & circle) const{

	Point p = circle.getCenter();
	double rad = circle.getRadius();

	if(p.x> right-rad ){
			Vector normalVector(-1,0);
			circle.setVelocity(circle.getVelocity() - (2*circle.getVelocity()*normalVector)*normalVector);
	}
	if(p.y > top-rad){
			Vector normalVector(0,-1);
			circle.setVelocity(circle.getVelocity() - (2*circle.getVelocity()*normalVector)*normalVector);
	}

	if(p.x < left+rad){
			Vector normalVector(1,0);
			circle.setVelocity(circle.getVelocity() - (2*circle.getVelocity()*normalVector)*normalVector);
	}
	if(p.y < bottom+rad ){
			Vector normalVector(0,1);
			circle.setVelocity(circle.getVelocity() - (2*circle.getVelocity()*normalVector)*normalVector);
	}
}
