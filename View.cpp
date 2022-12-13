
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"
#include "GameCommand.h"
#include "View.h"
#include <string>
#include <iostream>

using namespace std;
//this class is going to create the view of the game
View:: View()
{
    size=11;
    scale=2;
    Point2D point(0,0);
    origin.x=point.x;
    origin.y=point.y;

    //view_maxsize=20;
}

void View::Draw(){
	for(int i = (view_maxsize/scale); i >= 0; i--){
		
		if(i%2 == 0){
			if(i*2>9){
				cout << i*2;
			}else{
				cout << i*2 << " ";
			}
		}else{
			cout << "  ";
		}
		for(int j = 0; j <= (view_maxsize/scale); j++){
			cout << grid [j][i][0];
			cout << grid [j][i][1];
		}
		cout << endl;
	}
	cout <<"  ";
	for(int i = 0; i <= (view_maxsize/scale); i++){
		if(i%2 == 0){
			if(i*2>9){
				cout << i*2;
			}else{
				cout << i*2 << " ";
			}
		}else{
			cout << "  ";
		}
	}
	cout << endl;
}

bool View:: GetSubscripts(int &out_x, int &out_y, Point2D location)
{
           
    out_x= (location.x-origin.x)/scale;
    out_y= (location.y-origin.y)/scale;
    bool whattoreturn;
    if (out_x<= 20 && out_y<= 20)
    {
        //cout<<"I get in here";
        whattoreturn= true;
    }
    else if (out_x>view_maxsize|| out_y>view_maxsize){
        cout<<"An Object is outside the display"<< endl;
        whattoreturn= false;
    }
    return whattoreturn;
}

void View:: Clear()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            grid[i][j][0]= '.';
            grid[i][j][1]= ' ';
        }
    }

}

void View:: Plot(GameObject *ptr)
{
    /*int x,y;
    char* selfptr= new char[2];
    ptr->DrawSelf(selfptr);
    cout<<"I get here plot ";
    if (GetSubscripts(x,y,ptr->Getlocation()))
    {
        if(grid[x][y][0]!='.'&& *selfptr!= 't')
        {
            grid[x][y][0]= '*';
            grid[x][y][1]= ' ';
        }
        else{
            if(*selfptr != 't')
            {
                grid[x][y][0]= *selfptr;
                grid[x][y][1]=*(selfptr+1);
            }
        }

    }
    delete[] selfptr;*/

    int x, y;
    bool issubscriptvalid = GetSubscripts(x,y,ptr->Getlocation());
    if(issubscriptvalid)
    {
        if(grid[x][y][0] != '.' && grid[x][y][0] != 'W')
        {
            grid[x][y][0] ='*';
            grid[x][y][1] =' ';
        }
        /*else if(!ptr->ShouldBeVisible() )
        {
            grid[x][y][0]= '.';
            grid[x][y][1]= ' ';
        }*/
        {(*ptr).DrawSelf(grid[x][y]);}
    }
}

