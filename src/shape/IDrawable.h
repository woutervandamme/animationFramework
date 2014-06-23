#ifndef IDRAWABLE_H_
#define IDRAWABLE_H_
class DynamicCircle;

class IDrawable{
public:
	virtual ~IDrawable(){}
	virtual void draw() const = 0;
	virtual void intersection(DynamicCircle & circle) const= 0;
};

#endif

