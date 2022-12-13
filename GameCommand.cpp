#include "Model.h"
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"
#include "GameCommand.h"
#include "View.h"
#include <string>
#include <iostream>

using namespace std;



void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
    Trainer* pointertotrainer= model.GetTrainerPtr(trainer_id);
    if( pointertotrainer!=NULL)
    {
        cout<<"Moving "<< pointertotrainer->GetName()<< " to"<< p1;
        pointertotrainer-> StartMoving(p1);
    }
    else{
        cout<<"Error: Please enter a valid commmand"<< endl;
    }

}


void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{
    Trainer* pointertotrainer= model.GetTrainerPtr(trainer_id);
    PokemonCenter* pointertocenter= model.GetPokemonCenterPtr(center_id);
    if( pointertocenter!=NULL ||  pointertotrainer!= NULL)
    {
        cout<<"Moving "<< pointertotrainer->GetName()<< " to "<< pointertocenter->GetId()<<endl;
        pointertotrainer->StartMovingToCenter(pointertocenter);
    }
    else{
        cout<<"Error: Please enter a valid commmand"<< endl;
    }

}
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)
{
    Trainer* pointertotrainer = model.GetTrainerPtr(trainer_id);
    PokemonGym* pointertogym = model.GetPokemonGymPtr(gym_id);

    if(pointertogym!=NULL || pointertotrainer!=NULL)
    {
        cout<<"Moving "<<pointertotrainer->GetName()<<" to "<<pointertogym->GetId()<<endl;
        pointertotrainer->StartMovingToGym(pointertogym);
    }
    else{
        cout<<"Error: Please enter a valid command"<< endl;
    }
}
void DoStopCommand(Model& model, int trainer_id)
{
    Trainer *pointertotrainer= model.GetTrainerPtr(trainer_id);
    if(pointertotrainer != NULL)
    {
        cout<<"Stopping "<< pointertotrainer->GetName()<<endl;
        pointertotrainer->Stop();
    }
    else{
        cout<<"Error: Please enter a valid command"<< endl;
    }
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)
{
    Trainer* pointertotrainer= model.GetTrainerPtr(trainer_id);
    if(pointertotrainer==NULL)
    {
        cout<<"Error: Plese enter a valid command"<< endl;
    
    }
    else{
        cout<<pointertotrainer->GetName()<<" is battling"<< endl;
        pointertotrainer->StartBattling(battles);
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
{
    Trainer *pointertotrainer= model.GetTrainerPtr(trainer_id);
    if(pointertotrainer!= NULL)
    {
        cout<<"Recovering "<< pointertotrainer->GetName()<<" 's Pokemon's health"<< endl;
        pointertotrainer->StartRecoveringHealth(potions_needed);
    }
    else{
        cout<<"Error: Please enter a valid command"<<endl;
    }
}



void DoAdvanceCommand(Model& model, View & view)
{
    model.Update();
    cout<<"Advancing one tick."<< endl;
    view.Clear();
    model.Display(view);
    model.ShowStatus();
    view.Draw();
}

void DoRunCommand(Model& model, View& view)
{
    for(int i=0; i<=5; i++)
    {
    model.Update(); 
    cout<<"Advancing to the next event"<<endl;
    }
    view.Clear();
    model.Display(view);
    model.ShowStatus();
    view.Draw();



}
