#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include <math.h>

using namespace std;

//Class definition 
class Vector2D
{
    public:
    double x;
    double y;
    Vector2D();
    Vector2D (double in_x, double in_y);
    
};

//const Vector2D operator*(const Vector2D& p, double &dm);
const Vector2D operator * (Vector2D& p, double &dm);
//const Vector2D operator /(const Vector2D& p, double &dd);
const Vector2D operator /(Vector2D& p, double &dd);
ostream& operator << (ostream &out,const Vector2D &p);


#endif
