/*
 * Scene.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: wouter
 */

#include "Scene.h"
#include <vector>

Scene::Scene(const WorldWindow & window){
	drawables.push_back(&window);
}

void Scene::addAnimatable(IAnimatable* a){
	animatables.push_back(a);
}

void Scene::addDrawable(const IDrawable* d){
	drawables.push_back(d);
}


Scene::~Scene(){
	for(std::vector<const IDrawable *>::iterator it = drawables.begin(); it != drawables.end(); ++it) {
		delete *it;
		it++;
	}
	for(std::vector<IAnimatable *>::iterator it = animatables.begin(); it != animatables.end(); ++it) {
		delete *it;
		it++;
	}
}
