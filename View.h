
#ifndef VIEW_H
#define VIEW_H
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"
#include <string>
#include <iostream>

using namespace std;


const int view_maxsize = 20;
class View
{
    //const int view_maxsize;

    private:
        int size;
        double scale;
        Point2D origin;
        char grid[20][20][2];
        bool GetSubscripts(int &out_x, int &out_y, Point2D location);

    public:
        View();
        void Clear();
        void Plot(GameObject *ptr);
        void Draw();
};

#endif