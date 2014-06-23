#ifndef RENDERER_H_
#define RENDERER_H_

#include "scene/Scene.h"

class Renderer {

private:
	const Scene & scene;
public:
	Renderer(const Scene & s):scene(s){}
	void render();
};

#endif /* RENDERER_H_ */

