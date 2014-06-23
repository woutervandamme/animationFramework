/*
 * Scene.h
 *
 *  Created on: Apr 30, 2014
 *      Author: wouter
 */

#ifndef SCENE_H_
#define SCENE_H_
#include <vector>
#include "shape/IDrawable.h"
#include "shape/IAnimatable.h"
#include "WorldWindow.h"
class Scene {
private:
    std::vector<const IDrawable *> drawables;
    std::vector<IAnimatable *> animatables;
public:
    Scene(){}
	Scene(const WorldWindow & window);
	~Scene();
	const std::vector<const IDrawable *>& getDrawables() const{ return drawables;}
	const std::vector<IAnimatable *> & getAnimatables() const{ return animatables;}

	void addAnimatable(IAnimatable* a);
	void addDrawable(const IDrawable* d);
};

#endif /* SCENE_H_ */
