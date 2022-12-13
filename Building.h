#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
#include "Point2D.h"
#include <iostream>

using namespace std;

//Class definition of building that inherits from GameObject
class Building: public GameObject
{
    private:
        unsigned int trainer_count;
         
        
    public: 

       Building();
       Building(Point2D in_loc, int in_Id, char in_code);
        void AddOneTrainer();
        void RemoveOneTrainer();
        void ShowStatus();
        bool ShouldBeVisible();
        unsigned int gettrainer();

};

#endif