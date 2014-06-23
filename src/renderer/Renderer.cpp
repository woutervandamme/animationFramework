#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "renderer/Renderer.h"
#include <vector>
#include <iostream>
void Renderer::render(){
	std::vector<const IDrawable *> drawables = scene.getDrawables();
	for(std::vector<const IDrawable *>::const_iterator it = drawables.begin(); it != drawables.end(); ++it) {
		const IDrawable * circle = *it;
		circle->draw();
	}

	std::vector<IAnimatable *> animatables = scene.getAnimatables();

	for(std::vector<IAnimatable *>::const_iterator it2 = animatables.begin(); it2 != animatables.end(); ++it2) {
		IAnimatable * circle = *it2;
		circle->update(this->scene);
	}

}




