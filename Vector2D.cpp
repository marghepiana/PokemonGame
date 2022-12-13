#include <iostream>
#include "Vector2D.h"

using namespace std;

//Defining default constructor
Vector2D:: Vector2D()
{
    x=0.0;
    y= 0.0;
}

//Defining the constructors
Vector2D:: Vector2D(double in_x, double in_y)
{
    x= in_x;
    y= in_y;
}


//Defining the multiplication overloaded operator that multiply a vector and a scalar

//const Vector2D operator*(const Vector2D& p, double &dm)
const Vector2D operator*( Vector2D& p, double &dm)
{
    double Newx= p.x * dm;
    double Newy= p.y * dm;
    Vector2D result(Newx, Newy);
    return result;
}
//Defining the division overloaded operator that multiply a vector and a scalar
//const Vector2D operator /(const Vector2D& p, double &dd)
const Vector2D operator /( Vector2D& p, double &dd)
{
    double Newx;
    double Newy;
    if (dd==0)
    {
        Newx= p.x;
        Newy= p.y;
    }
    else 
    {
     Newx= p.x/ dd;
     Newy= p.y/ dd;
    }

    Vector2D result (Newx, Newy);
    return result;
}
//Defining a output overloaded operator that prints the output in vector style
 ostream& operator << (ostream &out,const Vector2D &p)
 {
     out<< "<"<<p.x << "," << p.y <<">"<<endl;
    return out;
 }