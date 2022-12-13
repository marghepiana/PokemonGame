
#ifndef MODEL_H
#define MODEL_H
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "WildPokemon.h"
#include "View.h"
#include <list>


class Model
{
    private:
        int time;
       // GameObject *object_ptrs[10];
       list<GameObject*> object_ptrs, active_ptrs;
        int num_objects;
        list<Trainer*>trainer_ptrs;
        int num_trainers;
        list<PokemonCenter*> center_ptrs;
        int num_centers;
        list<PokemonGym*> gym_ptrs;
        int num_gyms;

    public:
        Model();
        ~Model();
    Trainer *GetTrainerPtr(int id);
    PokemonCenter *GetPokemonCenterPtr(int id);
    PokemonGym *GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    int Gettime();
    void checkifsamelocation();
    void NewCommand(char type, int id, Point2D loc);
    WildPokemon *GetWildPokemonPtr(int id);
    list<WildPokemon*> wildpokemon_ptrs;
    int num_wildpokemon;
};

#endif