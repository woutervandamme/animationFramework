/*
 * Flock.h
 *
 *  Created on: May 21, 2014
 *      Author: wouter
 */

#ifndef FLOCK_H_
#define FLOCK_H_
#include "shape/Shape.h"
#include "shape/IAnimatable.h"
#include "shape/Boid.h"
#include <vector>
#include <iostream>

class Flock:public IAnimatable, public Shape {
private:
    std::vector<Boid *> boids;
    double cohesion;
    double separation;
    double alignment;
    double damping;
    double maxSpeed;
public:
	Flock(const Colour & colour):Shape(colour){
		cohesion = 0.08;
		separation = 30;
		alignment = 0.025;
		damping = 0.15;
		maxSpeed = 0;
	}

	virtual ~Flock(){}
	void setBoids(std::vector<Boid * > b ){ this->boids = b; }
	std::vector<Boid * > getBoids() const { return this->boids; }
	void addBoid( Boid * boid){ boids.push_back(boid);}
	void draw() const;
	virtual void update(const Scene & scene);
	virtual void intersection(DynamicCircle & circle) const{}
	Vector rule1(unsigned index);
	Vector rule2(unsigned index);
	Vector rule3(unsigned index);


};

#endif /* FLOCK_H_ */
