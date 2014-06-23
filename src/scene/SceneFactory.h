/*
 * SceneFactory.h
 *
 *  Created on: Apr 30, 2014
 *      Author: wouter
 */

#ifndef SCENEFACTORY_H_
#define SCENEFACTORY_H_
#include "Scene.h"
#include <string>

class SceneFactory {
public:
	SceneFactory(){}
	virtual ~SceneFactory(){}
	static Scene & createScene(std::string filename, const WorldWindow & window);
};

#endif /* SCENEFACTORY_H_ */
