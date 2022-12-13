#include "Model.h"
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"
#include "View.h"
#include "WildPokemon.h"
#include "Invalid_Input.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

Model:: Model()
{
    time=0;
    //creating center objects in the heap and then setting the respective pointer array of the center and of the object to point to them 
    Point2D locc1(1,20);
    PokemonCenter *center1= new PokemonCenter(1,1,100,locc1);
    center_ptrs.push_back(center1);
    object_ptrs.push_back(center1);
    Point2D locc2(10,20);
    PokemonCenter *center2= new PokemonCenter (2,2,200,locc2);
    center_ptrs.push_back(center2);
    object_ptrs.push_back(center2);

    //creating the gym objects in the heap and then setting the respective pointer array of the gym and of the object to point to them
    Point2D locg1(0,0);
    PokemonGym *gym1= new PokemonGym(1, 1, 2, 3, 1, locg1);
    gym_ptrs.push_back(gym1);
    object_ptrs.push_back(gym1);
    Point2D locg2(5,5);
    PokemonGym *gym2= new PokemonGym(1,5,7.5,4,2,locg2);
    gym_ptrs.push_back(gym2);
    object_ptrs.push_back(gym2);

    //creting the trainer objects in the heap and then setting the respective pointer array of the trainer and the object to point to them
    Point2D loct1(5,1);
    string namet1= "Ash";
    Trainer *trainer1= new Trainer(namet1,1,'T',2,loct1);
    trainer_ptrs.push_back(trainer1);
    object_ptrs.push_back(trainer1);
    Point2D loct2(10,1);
    string namet2= "Misty";
    Trainer *trainer2= new Trainer(namet2,2,'T',2,loct2);
    trainer_ptrs.push_back(trainer2);
    object_ptrs.push_back(trainer2);

    //creating the wildpokemonobject
    Point2D locw1(10,12);
    string namew1="Fadi";
    WildPokemon *WildPokemon1= new WildPokemon(namew1,5,2,0,1,locw1);
    wildpokemon_ptrs.push_back(WildPokemon1);
    object_ptrs.push_back(WildPokemon1);
    Point2D locw2 (15,5);
    string namew2="Marghe";
    WildPokemon *WildPokemon2= new WildPokemon(namew2,5,2,0,2,locw2);
    wildpokemon_ptrs.push_back(WildPokemon2);
    object_ptrs.push_back(WildPokemon2);

    active_ptrs.push_back(center1);
    active_ptrs.push_back(center2);
    active_ptrs.push_back(gym1);
    active_ptrs.push_back(gym2);
    active_ptrs.push_back(trainer1);
    active_ptrs.push_back(trainer2);
    active_ptrs.push_back(WildPokemon1);
    active_ptrs.push_back(WildPokemon2);




    num_objects=8;
    num_trainers=2;
    num_centers=2;
    num_gyms=2;
    num_wildpokemon=2;
    cout<<"Model default constucted"<< endl;

}

    //implementation of the destuctor for model that destructs all of the objects created in the heap by accessing them though the array of pointers that are pointing to the specific objects
    Model:: ~Model()
    {
        for (auto it= object_ptrs.begin(); it!= object_ptrs.end(); ++ it)
        {
            delete *it;
        }
        
        cout<<"Model Destructed"<< endl;
        
    }
    //update function that increments the time then check if the update function for each object was true and if it was returns true itself, it also check if the user lost won the game if the hasfained returned true you lose, if passed returned true you win. 
    bool Model:: Update()
    {
        time++;
        bool whattoreturn;
        checkifsamelocation();
        for (auto it= object_ptrs.begin(); it!= object_ptrs.end(); ++ it)
        {
          bool check= (*it)->Update();
          if (check== true)
          {
            whattoreturn=true;
          }
        }
        for (auto it= gym_ptrs.begin(); it!= gym_ptrs.end(); ++ it)
        {
            if (!(*it)->passed())
            {
                break;
            }
            if(gym_ptrs.end()== next(it,1))
            {
                cout<<"GAME OVER: You win! All battles done!"<< endl;
                exit(0);
            }
        }


        for (auto it= trainer_ptrs.begin(); it!= trainer_ptrs.end(); ++ it)
        {
            if(!(*it)-> HasFainted())
            {
                break;
            }
            if(trainer_ptrs.end()== next(it,1)) //checking if the next element pointed by the it is at the end if so do the if statement 
            {
                cout<<"GAME OVER: You lose! All of your Trainer's pokemon have fainted!"<< endl;
                exit(0);
            }

        }

        for(auto it= active_ptrs.begin(); it!= active_ptrs.end(); ++ it)
        {
            if(!(*it)->ShouldBeVisible())
            {
                active_ptrs.erase(it);
                cout<<"DEADDDDDDDDDDDDDDDDDSSSS"<< endl;
                break;
                
            }


        }

        

        //go through active pointer list if 
        

    return whattoreturn;


    }

    void Model:: ShowStatus()
    {
        cout<<"Time: "<< time<< endl;
        for (auto it= object_ptrs.begin(); it!= object_ptrs.end(); ++ it)
        {
            (*it)->ShowStatus();
        }

    }

    void Model:: Display(View& view)
    {
        ShowStatus();
        view.Clear();
        for (auto it= active_ptrs.begin(); it!= active_ptrs.end(); ++ it)
        {
           
            view.Plot(*it);
        }
        view.Draw();

    }
    //grets pointer that point to the trainer, pokemon center and pokemon gm picked
   Trainer* Model:: GetTrainerPtr(int id)
   {
    for (auto it= trainer_ptrs.begin(); it!= trainer_ptrs.end(); ++ it)
    {
        if((*it)->GetId()==id)
        {
            return *it;
        }
    

    }
    return 0;
   }

    PokemonCenter* Model:: GetPokemonCenterPtr(int id)
   {
    for (auto it= center_ptrs.begin(); it!= center_ptrs.end(); ++ it)
    {
        if((*it)->GetId()==id)
        {
            return *it;
        }
    

    }
    return 0;
   }

    WildPokemon* Model:: GetWildPokemonPtr(int id)
   {
    for (auto it= wildpokemon_ptrs.begin(); it!= wildpokemon_ptrs.end(); ++ it)
    {
        if((*it)->GetId()==id)
        {
            return *it;
        }
    

    }
    return 0;
   }

      PokemonGym* Model:: GetPokemonGymPtr(int id)
   {
    for (auto it= gym_ptrs.begin(); it!= gym_ptrs.end(); ++ it)
    {
        if((*it)->GetId()==id)
        {
            return *it;
        }
    

    }
    return 0;
   }

   int Model:: Gettime()
   {
    return time;
   }

 void Model:: checkifsamelocation()
 {

    for (auto mt= wildpokemon_ptrs.begin(); mt!= wildpokemon_ptrs.end(); ++mt){
        for(auto ee= trainer_ptrs.begin(); ee!= trainer_ptrs.end(); ++ee)
        {
           if ( Getdistancebetween((*mt)->Getlocation(), (*ee)->Getlocation())==0)
           {
            (*mt)->follow(*ee);
            cout<<"I have a Wild Pokemon following me"<< endl;

            
           }

        }
    }
   
    
 }

 void Model:: NewCommand(char type, int id, Point2D loc)
 {
    if(type=='c')
    {
        if(GetPokemonCenterPtr(id)==0)
        {
            PokemonCenter *center3= new PokemonCenter(id,1,100,loc);
            center_ptrs.push_back(center3);
            object_ptrs.push_back(center3);
            active_ptrs.push_back(center3);
        }
        else{
            throw Invalid_Input("Id already exist");
        }
    }

    if(type== 'g')
    {
        if(GetPokemonGymPtr(id)==0)
        {
            PokemonGym *gym3= new PokemonGym(1, 1, 2, 3, id, loc);
            gym_ptrs.push_back(gym3);
            object_ptrs.push_back(gym3);
            active_ptrs.push_back(gym3);
        }
         else{
            throw Invalid_Input("Id already exist");
        }
    }

    if(type=='t')
    {
        if(GetTrainerPtr(id)==0)
        {
            string namet3="Sofia";
            Trainer *trainer3= new Trainer(namet3,id,'T',2,loc);
            trainer_ptrs.push_back(trainer3);
            object_ptrs.push_back(trainer3);
            active_ptrs.push_back(trainer3);
        }
         else{
            throw Invalid_Input("Id already exist");
        }
    }

    if(type=='w')
    {
        if(GetWildPokemonPtr(id)==0)
        {
            string namet3="Costanza";
            WildPokemon *WildPokemon3= new WildPokemon(namet3,1, 4, false, id,loc);
            wildpokemon_ptrs.push_back(WildPokemon3);
            object_ptrs.push_back(WildPokemon3);
            active_ptrs.push_back(WildPokemon3);
        }
         else{
            throw Invalid_Input("Id already exist");
        }
    }
 }