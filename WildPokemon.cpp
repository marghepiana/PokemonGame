#include "GameObject.h"
#include "Trainer.h"
#include "Point2D.h"
#include "Trainer.h"
#include "WildPokemon.h"
#include <iostream>
#include <string>

using namespace std;

WildPokemon:: WildPokemon(string name,double attack, double health, bool variant, int id, Point2D in_loc) : GameObject(in_loc , id, 'W')
{
    this-> name = name;
    this->attack = attack;
    this-> health= health;
    this -> variant = variant;
    state= IN_ENVIRONMENT;

}

void WildPokemon:: follow(Trainer *t)
{
    if(state== IN_ENVIRONMENT)
    {
    current_trainer= t;
    state= IN_TRAINER;  }

    
    //display_code='w';


}

bool WildPokemon:: get_variant()
{
    return variant;
}

double WildPokemon:: get_attack()
{
    return attack;
}

double WildPokemon:: get_health()
{
    return health;
}

bool WildPokemon:: get_in_combat()
{
    return in_combat;
}

bool WildPokemon:: Update()
{
    if (state == IN_TRAINER)
    {
        health--;
        current_trainer-> DecreaseHealth(attack);
        if (health==0)
        {
            state=DEAD;
        }
        return false;
    }
    else if(state == DEAD)
    {
        return false;

    }
    else if(state == IN_ENVIRONMENT)
    {
        return false;

    }
    else{
        return  true;}


}

bool WildPokemon::ShouldBeVisible()
{
    if(state!=IN_ENVIRONMENT)
    {
        return false;
    }
    else{
        return true;
    }
}

void WildPokemon:: ShowStatus()
{
    
    cout<< "WildPokemon status"<< endl;
    GameObject:: ShowStatus();
    if(state == IN_ENVIRONMENT)
    {
        cout<<"Wild Pokemon is in environment"<<endl;
    }
    else if (state== DEAD)
    {
        cout<< "Wild Pokemon is dead"<<endl;

    }
    else if(state== IN_TRAINER)
    {
        cout<<"Wild Pokemon is in trainer"<< endl;
    }

    cout<<"Variant: "<< variant<<endl;
    cout<< "Attack: "<< attack<< endl;
    cout<<" Wild pokemon health: "<< health<< endl;
}

bool WildPokemon:: IsAlieve()
{
    if (health >0)
    {

        return true;
    }
    else {
        state=DEAD;
        return false;
    }
}
