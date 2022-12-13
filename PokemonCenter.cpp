#include "GameObject.h"
#include "Building.h"
#include "Vector2D.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include <iostream>

using namespace std;
//Definition of defualt constuctor of PokemonCenter
PokemonCenter:: PokemonCenter()
{
    display_code='C';
    potion_capacity= 100;
    num_potions_remaining= potion_capacity;
    pokedollar_cost_per_potion= 5;
    state= POTIONS_AVAILABLE;
    cout<< "Pokemon Center default constructor"<< endl;

    cout<<"Checking default, display code"<<display_code<<", capacity"<< potion_capacity<<", potions remaining"<< "cost"<< pokedollar_cost_per_potion<<"state"<< state<< endl;
}
//Definition of paramenter constructor of PokemonCenter
PokemonCenter:: PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc)
{
    id_num= in_id;
    location= in_loc;
    pokedollar_cost_per_potion= potion_cost;
    potion_capacity=potion_cap;
    display_code= 'C';
    state= POTIONS_AVAILABLE;
    num_potions_remaining= potion_capacity;
    cout<< "Pokemon Center constructed"<< endl;

}
//Defintion of HasPotion function that returns true if there are still potions in the center
bool PokemonCenter:: HasPotions()
{
    if (num_potions_remaining>=1)
    {
        return true;
    }
    else{
        return false;
    }
}
//Definition of GetNumPotionRemaining that return the number of potions remaining 
unsigned int PokemonCenter:: GetNumPotionRemaining()
{
    return num_potions_remaining;
}
//Definition of CanAffordPotion function that checks if the potion can be afforded by the Budjet entered
bool PokemonCenter:: CanAffordPotion(unsigned int potion, double budjet)
{
    double costpotion= pokedollar_cost_per_potion*potion;

    if (budjet>= costpotion)
    {
        return true;

    }
    else {
        return false;
    }

}
//Definition of a function that calculated the total cost of the number of potions requested
double PokemonCenter:: GetPokeDollarCost(unsigned int potion)
{
    double costpotion= pokedollar_cost_per_potion*potion;
    return costpotion;
}
//Definition of DistributePotion that returns the potion distributed, if the ammount requested is bigger than the ammmount available it returns the amount available and then set it equal to zero.
unsigned int PokemonCenter:: DistributePotion(unsigned int potion_needed)
{
    unsigned int resultpotion;
    if(num_potions_remaining >= potion_needed)
    {
        num_potions_remaining -= potion_needed;
        resultpotion= potion_needed;
    }
    else if (num_potions_remaining < potion_needed)
    {
        resultpotion=num_potions_remaining;
        num_potions_remaining=0;
    }
    return resultpotion;
}
//Definitiom of Update function that update the number of potions remaining and returns true if there are no potions left
bool PokemonCenter:: Update()
{
    bool whattoreturn;
    if(num_potions_remaining== 0|| num_potions_remaining<0)
    {
        state= NO_POTIONS_AVAILABLE;
        display_code= 'c';
        cout<< "Pokemon Center ("<< id_num<< ") has run out of potions."<< endl;
        whattoreturn= true;
    }
    else if (num_potions_remaining!= 0|| num_potions_remaining>0){
        //cout<< "still potions"<< endl;
        whattoreturn=false;
    }
    return whattoreturn;
}
//Definition of ShowStatus that shoes the status of the center
void PokemonCenter:: ShowStatus()
{
    cout<<"Pokemon Center status:"<< endl;
    Building:: ShowStatus();
    cout<<"PokeDollars per potion:("<< pokedollar_cost_per_potion<<")"<< endl;
    cout<<"has("<< num_potions_remaining<<")"<< "potions remaining"<< endl;
}

PokemonCenter:: ~PokemonCenter()
{
    cout<< "PokemonCenter destructed"<< endl;
}
