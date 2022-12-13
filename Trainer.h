#ifndef TRAINER_H
#define TRAINER_H
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Trainer: public GameObject
{
        enum TrainerStates {
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
    };

    private:
        double speed, PokeDollars;
        bool is_at_center;
        bool is_IN_GYM;
        unsigned int health, experience, battles_to_buy, potions_to_buy;
        string name;
        PokemonCenter * current_center;
        PokemonGym * current_gym;
        Point2D destination;
        Vector2D delta;
    public:
        Trainer();
        Trainer (char in_code);
       virtual ~Trainer();
        Trainer(string in_name, int in_id, char in_code, unsigned int _speed, Point2D in_loc );
        void StartMoving(Point2D dest);
        void StartMovingToGym(PokemonGym * gym);
        void StartMovingToCenter(PokemonCenter *center);
        void StartBattling(unsigned int num_battles);
        void StartRecoveringHealth (unsigned int num_potions);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        string GetName();
        void DecreaseHealth(double attack);

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D dest);
};

static double GetRandomAmmountOfPokeDollars();

#endif