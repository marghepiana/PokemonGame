#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <iostream>

using namespace std;
//Class definition of PokemonCenter that inherits from Building
class PokemonCenter: public Building
{
    enum PokemonCenterStates {
    POTIONS_AVAILABLE = 0,
    NO_POTIONS_AVAILABLE = 1
    }; 

    private:
        unsigned int potion_capacity;
        unsigned int num_potions_remaining;
        double pokedollar_cost_per_potion;

    public:

        PokemonCenter();
        PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc);
        ~PokemonCenter();
        bool HasPotions();
        unsigned int GetNumPotionRemaining();
        bool  CanAffordPotion(unsigned int potion, double budjet);
        double GetPokeDollarCost(unsigned int potion);
        unsigned int DistributePotion(unsigned int potion_needed);
        bool Update();
        void ShowStatus();

};

#endif