/*
 * GravityCircle.h
 *
 *  Created on: May 21, 2014
 *      Author: wouter
 */

#ifndef GRAVITYCIRCLE_H_
#define GRAVITYCIRCLE_H_
#include "shape/DynamicCircle.h"
#include "util/Vector.h"
#include "util/Colour.h"
class GravityCircle : public DynamicCircle{
private:
public:
	GravityCircle(const Point & center, double radius, const Colour & colour, const Vector & velocity);
	virtual void update(const Scene & scene);
};

#endif /* GRAVITYCIRCLE_H_ */
