#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>

using namespace std;
//CLass definition of PokemonGym, it inherits from Building
class PokemonGym: public Building
{
    enum PokemonGymStates
    {
     NOT_DEFEATED = 0,
     DEFEATED = 1
    };  

    private:
        unsigned int num_battle_remaining;
        unsigned int max_number_of_battle;
        unsigned int health_cost_per_battle;
        double Poke_dollar_cost_per_battle;
        unsigned int experience_per_battle;
    public:
    PokemonGym();
    PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc);
    ~PokemonGym();
    double GetPokeDollarCost(unsigned int battle_qty);
    unsigned int GetHealthCost(unsigned int battle_qty);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int battle_qty, double budjet, unsigned int hralth);
    unsigned int TrainPokemon(unsigned int battle_units);
    bool Update();
    bool passed();
    void ShowStatus();



 
};

#endif