#include "Vector.h"
#include <cmath>

Vector::Vector(const Point & from, const Point & to){
	this->x = to.x-from.x;
	this->y = to.y-from.y;
}

Point operator+(const Vector & v, const Point & p){
	return Point(v.x+p.x, v.y+p.y);
}

Point operator+(const Point & p, const Vector & v){
	return v+p;
}

Vector operator*(const Vector & v, double d){
	return Vector(v.x*d,v.y*d);
}

Vector operator*(double d,const Vector & v){
	return v*d;
}

Vector operator*(const Vector & v,const Vector & v2){
	return Vector(v.x*v2.x,v.y*v2.y);
}

Vector operator+(const Vector & v,const Vector & v2){
	return Vector(v.x+v2.x,v.y+v2.y);
}

Vector operator-(const Vector & v,const Vector & v2){
	return Vector(v.x-v2.x,v.y-v2.y);
}

double Vector::getDot(const Vector & v) const{
	return (x*v.x)+(y*v.y);
}

int Vector::getLength() const{
	return sqrt((x*x) + (y*y));
}

Vector Vector::normalize() const {
	return Vector(x/getLength(),y/getLength());
}
