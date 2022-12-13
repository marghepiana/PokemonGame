#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

//Definition of the default constructor which implements the base constructor since the base class of Building is Gameobject
Building:: Building()
:GameObject('B')
{
   // display_code='B';
    trainer_count=0;
    cout<< "Building default constructed"<< endl;
}
//Definition of the paramenter constructor
Building:: Building(Point2D in_loc, int in_id, char in_code)
:GameObject(in_loc, in_id, in_code)
{
    trainer_count=0;

    cout << "Building constructed"<< endl;
}
//Definition of AddOneTrainer that adds one to the trainer count every time that a trainer enters the building
void Building:: AddOneTrainer()
{
    trainer_count+=1;
}
//Definition of RemoveOneTrainer that removes one form the trainer count  every time a trianer leaves the building
void Building:: RemoveOneTrainer()
{
    trainer_count-=1;
}
//Definition of the function that shows the status of the building
void Building:: ShowStatus()
{
    cout<< "("<< display_code <<")("<<id_num<<")located at ("<< location<<")"<< endl;

    if (trainer_count==1)
    {
        cout<<"("<< trainer_count<< ") trainer is in the building"<< endl;
    }
    else
    {
        cout<< "("<< trainer_count<< ") trainers are in the building"<< endl;
    }
}
//Functoin that returns tue because buildings are always visible 
bool Building:: ShouldBeVisible ()
{
    return true;
}
//Function that gets the trainercount
unsigned int Building:: gettrainer()
{
    return trainer_count;
}

