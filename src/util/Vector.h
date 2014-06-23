#ifndef VECTOR_H_
#define VECTOR_H_
#include "Point.h"

class Vector {
public:
	double x;
	double y;
	Vector(double x=0, double y=0): x(x), y(y) { }
	Vector(const Point & from, const  Point & to);
	friend Point operator+(const Point & p,const Vector & v);
	friend Point operator+(const Vector & v,const Point & p);

	friend Vector operator*(const Vector & v,double d);
	friend Vector operator*(double d,const Vector & v);

	friend Vector operator*(const Vector & v,const Vector & v2);
	friend Vector operator+(const Vector & v,const Vector & v2);
	friend Vector operator-(const Vector & v,const Vector & v2);

	void operator/=(double a){x/=a; y/=a;}

	double getDot(const Vector & v) const;
	int getLength() const;
	Vector normalize() const;

};

#endif /* POINT_H_ */
