/*
 * IAnimatable.h
 *
 *  Created on: Apr 25, 2014
 *      Author: wouter
 */

#ifndef IANIMATABLE_H_
#define IANIMATABLE_H_

class Scene;
class IAnimatable {
public:
	virtual ~IAnimatable(){};
	virtual void update(const Scene & scene) = 0;
};



#endif /* IANIMATABLE_H_ */
