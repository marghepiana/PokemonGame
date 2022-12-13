#include "GameObject.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

// This code implement all of the constructors and the functions of GameObject


//Definition of default constructor
GameObject:: GameObject(char in_code)
{
    display_code= in_code;
    id_num=1;
    state=0;
    cout<<"GameOject constructed"<<endl;
}

//Definition of paramenter construcor
GameObject:: GameObject(Point2D in_loc,  int in_id, char in_code)
{
    display_code= in_code;
    id_num= in_id;
    location= in_loc;
    state=0; // shouls i cast it?
    cout<< "GameObject contructed"<<endl;
}

// Definition of Getlocation function in GameObject
Point2D GameObject:: Getlocation()const
{
    return location;
}

//Definition of GetId function in GameObject
int GameObject:: GetId() const
{
    return id_num;
}

//Definition of GetState funciton in GameObject
char GameObject:: GetState() const
{
    return state;
}

//Definition  of Showstatus function in GameObject
void GameObject:: ShowStatus()
{
    cout<< "("<< display_code<< ") ("<<id_num<<")at("<<location <<")"<< endl;
}

GameObject:: ~GameObject()
{
    cout<<"GameObject destructed"<< endl;
}

void GameObject:: DrawSelf(char* ptr)
{
    *ptr=display_code;
    *(ptr+1)= '0'+ id_num;
}