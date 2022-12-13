#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"

using namespace std;

//Class definition 
class Point2D
{
    public: 
    double x;
    double y;

    Point2D();
    Point2D(double, double);

};

//Nonmember function prototype
double Getdistancebetween(Point2D p1, Point2D p2);

ostream& operator << (ostream &out,const Point2D &p);
const Vector2D operator +(const Point2D& point1,const Point2D& point2);
const Vector2D operator -(const Point2D& point1,const Point2D& point2);


#endif