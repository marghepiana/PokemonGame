#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point2D.h"
#include <iostream>

using namespace std;

//Creating the interface of the base class for all of the objects in the game

class GameObject
{
    protected:
    Point2D location;
    int id_num ;
    char display_code, state;
    

    public:
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    virtual ~GameObject();
    Point2D Getlocation()const;
    int GetId()const;
    char GetState()const;
    virtual void ShowStatus();
    virtual bool Update()=0;
    virtual bool ShouldBeVisible()=0;
    void DrawSelf(char *ptr);
};

#endif

