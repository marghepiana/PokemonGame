#include <iostream>
#include "Point2D.h"
#include <math.h>
#include "Vector2D.h"


using namespace std;

//Constructors definintion

Point2D:: Point2D()
{
    x= 0.0;
    y=0.0;
}

Point2D:: Point2D(double _x, double _y)
{
    x=_x;
    y=_y;
}

// Nonmember function definition that gets the distance between two points
double Getdistancebetween(Point2D p1, Point2D p2)
{
    double minusx= p2.x-p1.x;
    double minusy= p2.y-p1.y;
    double pxsqr= pow(minusx, 2);
    double pysqr= pow(minusy, 2);
    double distance= sqrt(pxsqr+pysqr);
    return distance;

}

//output overloaded operator 
ostream& operator <<(ostream &out, const Point2D &p)
{
    out<< "("<<p.x << "," << p.y <<")";
    return out;
}
// sum overloaded operator that when you sum two points returns a vector
const Vector2D operator +(const Point2D& point1,const Point2D & point2)
{
    double newx, newy;

    newx= point1.x + point2.x;
    newy= point1.y + point2.y;

    return Vector2D (newx, newy);

}
// minus overloaded operator that when you subtract two points returns a vector 
const Vector2D operator - (const Point2D& point1,const Point2D& point2)
{
    double newx, newy;

    newx= point1.x -point2.x;
    newy= point1.y - point2.y;

    return Vector2D (newx, newy);

}