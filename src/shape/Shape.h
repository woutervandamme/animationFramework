
#ifndef SHAPE_H_
#define SHAPE_H_

#include "util/Colour.h"
#include "IDrawable.h"

#include <GL/glut.h>

class Shape : public IDrawable{
protected:
	Colour colour;
public:
	Shape(Colour colour);
	Colour getColour();
	void setColour(Colour colour);
};
#endif /* SHAPE_H_ */
