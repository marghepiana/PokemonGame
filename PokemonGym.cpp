#include "PokemonGym.h"
#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>

using namespace std;

//Definitin of deafult constructor of Pokemongym
PokemonGym:: PokemonGym()
{
    display_code= 'G';
    state= NOT_DEFEATED;
    max_number_of_battle= 10;
    num_battle_remaining= max_number_of_battle;
    health_cost_per_battle= 1;
    Poke_dollar_cost_per_battle= 1.0;
    experience_per_battle =2;
    cout<<"PokemonGym default constructor"<< endl;

}
//Definition of parameter constructor of PokemonGYm
PokemonGym:: PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc)
{
    location= in_loc;
    id_num= in_id;
    display_code='G';
    max_number_of_battle= max_battle;
    num_battle_remaining=max_number_of_battle;
    health_cost_per_battle= health_loss;
    experience_per_battle= exp_per_battle;
    Poke_dollar_cost_per_battle=  PokeDollar_cost;
    cout<< "PokemonGymConstructed"<<endl;

}

//Definition od GetPOkeDollarCost function in PokemomnGym, it returns the cost of the number of battles that the trainer wants to fight
double PokemonGym:: GetPokeDollarCost(unsigned int battle_qty)
{
    double result1= battle_qty * Poke_dollar_cost_per_battle;
    return result1;
}
//Definition of the GetHealthCost function in PokemonGym it returns the total health cost for the number of battles that trainer wants to fight
unsigned int PokemonGym:: GetHealthCost(unsigned int battle_qty)
{
    unsigned int result2= health_cost_per_battle * battle_qty;
    return result2;
}

//Definition of GetNumBattlesRemaining function in POkemonGym, it returns the number of battles remaining in that gym
unsigned int PokemonGym:: GetNumBattlesRemaining()
{
    return num_battle_remaining;
}
//Definition of IsAbleToBattle function in POkemonGym that returns true only if pokemon is defeated otherwise returns false
bool PokemonGym:: IsAbleToBattle( unsigned int battle_qty, double budget, unsigned int health )
{
    double result1= battle_qty * Poke_dollar_cost_per_battle;
    unsigned int result2= health_cost_per_battle * battle_qty;
    if (budget >= result1 || health >= result2)
    {
        return true;
    }
    else {
        return false;
    } 
}
//Definition of TrainPokemon that returns the experience gained depending on the number of battles that the pokemon is doing, if the number of battles that the trianer wants to do is more tham the one remaining this function would just consider the one remeaining and then set them equal to zero.
unsigned int PokemonGym:: TrainPokemon(unsigned int battle_units)
{
    unsigned int experience_gained;
    if(battle_units <= num_battle_remaining)
    {
        num_battle_remaining= num_battle_remaining - battle_units;
        experience_gained= (battle_units)*(experience_per_battle);
    }
    else if(battle_units > num_battle_remaining)
    {
        experience_gained= (num_battle_remaining)*(experience_per_battle);
        num_battle_remaining=0;

    }

    return experience_gained;
}

//Check id pokemon is defeated
bool PokemonGym:: Update()
{
    if (num_battle_remaining== 0 || num_battle_remaining<= 0)
    {
        state= DEFEATED;
        display_code= 'g';
        cout<<"("<< display_code<<")("<< id_num<< ") has been defeated "<<endl;
        return true;
    }
    else{
        return false;
    }
}


bool PokemonGym:: passed()
{
    if (num_battle_remaining == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
//Definition of function that shows the status of the pokemon 
void PokemonGym:: ShowStatus()
{
    cout<<"PokemonGym status"<< endl;
    Building:: ShowStatus();
    cout<< "Max number of battles:("<< max_number_of_battle<<")"<< endl;
    cout<< "Health cost per battle("<< health_cost_per_battle<<")"<<endl;
    cout<< "Poke Dollar per battle("<< Poke_dollar_cost_per_battle<<")"<< endl;
    cout<<"Experiernce per battle("<<experience_per_battle<<")"<< endl;
    cout<< "("<<num_battle_remaining<<") battles are remaining for this PokemonGym"<<endl;
    
}

PokemonGym:: ~PokemonGym()
{
    cout<<"PokemonGym destructed"<< endl;
}