#include "Point2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Vector2D.h"
#include "Trainer.h"
#include "WildPokemon.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
//fv
using namespace std;
//defining the constructors for trainer
Trainer:: Trainer() :GameObject('B')
{
    speed= 5;
    potions_to_buy=0;
    battles_to_buy=0;
    health=20;
    experience=0;
    PokeDollars=10;
    is_IN_GYM= false;
    is_at_center= false;
    destination.x=0.0;
    destination.y= 0.0;
    cout<<"Trainer defualt constructed " << endl;
}

Trainer:: Trainer(char in_code) :GameObject(in_code)
{
    speed=5;
    state= STOPPED;
    speed= 5;
    potions_to_buy=0;
    battles_to_buy=0;
    health=20;
    experience=0;
    PokeDollars=10;
    is_IN_GYM= false;
    is_at_center= false;
    destination.x=0.0;
    destination.y= 0.0;
    cout<< "Trainer Constructed "<< endl;
}

Trainer:: Trainer (string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc): GameObject(in_loc, in_id, in_code)
{
    speed= in_speed;
    name= in_name;
    speed= in_speed;
    potions_to_buy=0;
    battles_to_buy=0;
    health=20;
    experience=0;
    PokeDollars=10;
    is_IN_GYM= false;
    is_at_center= false;
    destination = in_loc;
    cout<< "Trainer Constructed";
}

//function that make the pokemon status to moce if it has not fainted. it also checks if there are some trianer already in gym or center and remoce them 
void Trainer:: StartMoving(Point2D dest)
{
    Trainer:: SetupDestination(dest);

    if (Getdistancebetween(location, dest)==0)
    {
        state= MOVING;
        cout<< display_code<< " "<< id_num<< ": I'm already there. See?"<< endl;
        UpdateLocation();
    }
    else if(state==FAINTED)
    {
        cout<<display_code<< " "<< id_num<< ": My pokemon has fained. I may move but you cannot see me." << endl;
    }
    else {
        if(state==AT_CENTER)
        {
            current_center->RemoveOneTrainer();
        } else if(state == IN_GYM)
        {
            current_gym->RemoveOneTrainer();
        }
         cout<<display_code<< " "<< id_num<< ": On my way"<< endl;
         state= MOVING;
    }
}

 void Trainer:: StartMovingToGym(PokemonGym *gym)
{
    //tells the trainer to start moving to a pokemon gym , if there are some trainer already in a gym or center it removes them.it uses a pointer to see the locatiom of the gym and set it up to the destination 

    
    destination= gym->Getlocation();
    SetupDestination(destination);

    if (Getdistancebetween(location, destination)==0)
    {
        state= IN_GYM;
        cout<< display_code<< " "<< id_num<< ": I'm already there. See?"<< endl;
        UpdateLocation();
    }
    else if(state == FAINTED)
    {
        cout<<display_code<< " "<< id_num<< ": My pokemon has fainted. I may move but you cannot see me." << endl;
    }
    else {
        if(state==AT_CENTER)
        {
            current_center->RemoveOneTrainer();
        } else if(state == IN_GYM)
        {
            current_gym->RemoveOneTrainer();
        }
         cout<<display_code<< " "<< id_num<< ": On my way to gym "<<gym->GetId()<< endl;
		 current_gym= gym;
         state= MOVING_TO_GYM;
    }

}
//same concept of start moving to gym, uses a pointer to see the location of the center the user wants to go to and make it go there
void Trainer:: StartMovingToCenter(PokemonCenter * center)

{
    
    destination = center->Getlocation();
    SetupDestination(destination);
    
    if (Getdistancebetween(location, destination)==0)
    {
        state= AT_CENTER;
        cout<< display_code<< " "<< id_num<< ": I'm already there. See?"<< endl;
        UpdateLocation();
        
    }
    else if(state == FAINTED)
    {
        cout<<display_code<< " "<< id_num<< ": My pokemon has fained. I may move but you cannot see me." << endl;
    }
    
    else {
        if(state==AT_CENTER)
        {
            current_center->RemoveOneTrainer();
        }
         else if(state == IN_GYM)
        {
            current_gym->RemoveOneTrainer();
        }
         cout<<display_code<< " "<< id_num<< ": On my way to center "<<center->GetId()<< endl;
         current_center=center;
         state= MOVING_TO_CENTER;
    }

}
//calculates the delta
void Trainer:: SetupDestination(Point2D dest)
{
    destination= dest;
    double distancebetween=Getdistancebetween(destination, location);
    double speeddivdist= speed/distancebetween;
    Vector2D destminusloc= dest-location;
    delta=(destminusloc)*(speeddivdist);
}


//functio that will make a pokemon battle if the trainer is in a gym, if it is not fainted
void Trainer:: StartBattling (unsigned int num_battles)
{
    if(state!= IN_GYM)
    {
        cout<< display_code<< " "<< id_num<< ": I can only battle in a PokemonGym"<< endl;
    }
    else if(state==FAINTED)
    {
        cout<<display_code<< " "<< id_num<< ": My pokemon has fained so  no more battles for me" << endl;
    }
    else if(PokeDollars < current_gym-> GetPokeDollarCost(num_battles))
    {
        cout<<display_code<<" "<< id_num<< ": Not enough money for battles"<< endl;
    }
    else if (current_gym->gettrainer()== 0)
    {
        cout<< display_code<< " "<< id_num<< ": Cannot Battle! This PokemonGym has no more trainers to battle!"<< endl;
    }
    else {
         cout<<display_code<< " "<< id_num<< ": Started to battle at the PokemonGym "<<current_gym-> GetId()<< " with "<< num_battles<< endl;
         state= BATTLING_IN_GYM;
         battles_to_buy= num_battles;
    }

}

void Trainer:: StartRecoveringHealth(unsigned int num_potions)
{
    // Tells the trainer to start recovering health at PokemonCenter

if (state != AT_CENTER)
    {
        cout<< display_code<< " "<< id_num<< ": I can only recover health at a PokemonCenter "<< endl;
    }
    else if(state==FAINTED)
    {
        cout<<display_code<< " "<< id_num<< ": My pokemon has fained so  no more battles for me" << endl;
    }
    else if(PokeDollars < current_center-> GetPokeDollarCost(num_potions))
    {
        cout<<display_code<<" "<< id_num<< ": Not enough money to recover Health"<< endl;
    }
    else if (current_center-> HasPotions()== false)
    {
        cout<< display_code<< " "<< id_num<< ": Cannot Recover! No potions remaining in this Pokemon Center "<< endl;
    }
    else {
         cout<<display_code<< " "<< id_num<< ": Start recovering "<< num_potions<< "potions at PokemoCenter "<< current_center-> GetId()<< endl;
         state= RECOVERING_HEALTH;
         potions_to_buy= num_potions;
    }

}

void Trainer:: Stop()
{
    state= STOPPED;
    cout<< display_code<< " "<< id_num<< ": Stopping "<< endl;
}

void Trainer:: ShowStatus()
{
    GameObject:: ShowStatus();
    cout<< name<<" status: "<< endl;
    cout<< "Health: "<< health<< endl;
    cout<< "Pokeollars: "<< PokeDollars<< endl;
    cout<< "Experience: "<< experience<< endl;
    if (state == STOPPED)
    {
        cout<< "Stopped "<< endl;
    }
    else if(state== MOVING)
    {
        cout<<"Moving at a speed of "<< speed<<" to destination "<<destination<<" at each step of "<< delta;
    }
    else if(state== MOVING_TO_GYM)
    {
        cout<<"heading to PokemonGym"<<current_gym-> GetId()<< " at a speed of "<< speed<< " at each step of "<< delta<< endl;
    }
    else if(state== MOVING_TO_CENTER)
    {
        cout<<"geading to PokemonCenter "<< current_center-> GetId()<<" at speed of "<< speed<< " at each step of "<< delta<< endl;
    }
    else if (state== IN_GYM)
    {
        cout<<"inside PokemonGym "<< current_gym-> GetId()<< endl;
    }
    else if (state == BATTLING_IN_GYM)
    {
        cout<< "battling in PokemonGym "<< current_gym->GetId()<< endl;
    }
    else if(state== RECOVERING_HEALTH)
    {
        cout<<"recovering health in Pokemon Center "<< current_center-> GetId()<< endl;
    }
    else if(state== AT_CENTER)
    {
        cout<<"inside Pokemon Center "<< current_center->GetId()<< endl;
    }

}
//most important function of trainer since it is the one that checks the states of the trainer and return true if the case is changed. This is done with a switch statement to check the case
bool Trainer:: Update()
{
    if (HasFainted()==true)
    {
        //state= FAINTED;
        cout<<name<< " is out of health and can't move!"<< endl;
        return true;
    }
    else{

    switch (state)
    {
        case STOPPED: return false;
                break;
        case MOVING:

         if (UpdateLocation())
                {
                    state= STOPPED;
                    return true;
                }
                else {
					UpdateLocation();
                    return false;}

                break;

        case MOVING_TO_GYM: 
        
         if (UpdateLocation())
                {
                    state=IN_GYM;
                    current_gym-> AddOneTrainer();
                    return true;
                }
                else {
				
                    return false;
				}
                break;

        case MOVING_TO_CENTER: 
         if (UpdateLocation()) {
                    state= AT_CENTER;
                    current_center->AddOneTrainer();
                    return true;
                }
                else {
					UpdateLocation();
                    return false;
				}
                    break;
        case IN_GYM: 
                //forse togli trainer qui aggiungendo un if statement controllando se il trainer not sta li dentro
                 return false;
                 break;
        case AT_CENTER: 
                return false;
                 break;
        case BATTLING_IN_GYM: experience += current_gym-> TrainPokemon(battles_to_buy);
                if ((health-(current_gym->GetHealthCost(battles_to_buy)))>0){
                 health= health-(current_gym->GetHealthCost(battles_to_buy));}
                 else{
                    health=0;
                    state=FAINTED;
                 }
                 PokeDollars-= current_gym->GetPokeDollarCost(battles_to_buy);
                 cout<< name <<" compleated battles "<< battles_to_buy<< " battles!"<< endl;
                 cout<<name <<" gained "<< experience<<" experience!"<< endl;
                 state= IN_GYM;
                 return true;
                 break;
        case RECOVERING_HEALTH: health += (5*(current_center-> DistributePotion(potions_to_buy)));
                PokeDollars-= current_center-> GetPokeDollarCost(current_center->DistributePotion(potions_to_buy));
                cout<<name<< "recovered "<<current_center->DistributePotion(potions_to_buy) << " potions "<< endl;
                state= AT_CENTER;
                return true;
                break;
        //case FAINTED:
       default: return false;
    }

    }
    
}

bool Trainer:: HasFainted()
{
    if(health==0)
    {
        state=FAINTED;
        return true;
    }
    else{ 
        return false;}
}
//function of trainer that updates the location
bool Trainer:: UpdateLocation()
{
    if(fabs(destination.x-location.x)<=fabs(delta.x) && fabs(destination.y-location.y)<= fabs(delta.y))
    {
		
        location= destination;
        cout<<"arrived"<< endl;
        cout<< display_code<<" "<< id_num<< " : I'm there!"<< endl;
        return true;
    }
    else{
        location.x+=delta.x;
        location.y+=delta.y;
        if(health !=0)
        {
         health-=1;}
         else {
            state= FAINTED;
         }
        PokeDollars+= GetRandomAmmountOfPokeDollars();
        cout<< "moved "<< endl;
        cout<<display_code<<" "<<id_num<< " : step...."<< endl;
        return false;
    }
}

static double GetRandomAmmountOfPokeDollars()
{
    srand(time(NULL));

    static double randomdollar= (rand()/ (double) RAND_MAX) *(2.0- 0.0)+0.0;
    return randomdollar;

}

Trainer:: ~Trainer()
{
    cout<< "Trainer destructed "<< endl;
}

bool Trainer:: ShouldBeVisible()
{
    if (state==FAINTED)
    {
        return false;
    }
    else{
        return true;
    }
}

string Trainer:: GetName()
{
    return name;
}
 

 void Trainer:: DecreaseHealth(double attack)
 {
    if (health < attack )
    {
        health=0;
    }
    else{
        health -= attack;
    }
 }