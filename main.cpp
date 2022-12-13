#include "Model.h"
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Vector2D.h"
#include "GameCommand.h"
#include "View.h"
#include "Invalid_Input.h"
#include <iostream>

using namespace std;

int main()
{
    View v;
    char code;
    Point2D point;
    int ID1, ID2;
    unsigned int battlesq, potionsq;
    char type;
    Model modeldefault;
    modeldefault.ShowStatus();
    modeldefault.Display(v);

    do{
        cout<<"Enter Game Command: "<<endl;
        cin>>code;

        try{
        
        
            if(code== 'm'){ 
                cin>>ID1;

                if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                cin>>point.x;
                if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                cin>>point.y;
                if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}

                if((point.x<0||point.x>20)||(point.y<0||point.y>20)){
                    throw Invalid_Input("Location is outside bounds");}

                DoMoveCommand(modeldefault,ID1,point);
            }

            else if(code=='c')
             {  cin>>ID1;
                    if(cin.fail()){
                        cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                cin>>ID2;
                    if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                DoMoveToCenterCommand(modeldefault,ID1,ID2);
             }
            else if(code== 'g')
                { cin>>ID1;
                    if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                    cin>>ID2;
                    if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                DoMoveToGymCommand(modeldefault,ID1,ID2);
                }
            else if(code== 's') 
                { cin>>ID1;
                    if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                DoStopCommand(modeldefault, ID1);
                }
            else if(code== 'b')
                {cin>> ID1;
                    if(cin.fail())
                    {
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                cin>>battlesq;
                    if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                DoBattleCommand(modeldefault, ID1, battlesq);
                }
            else if(code== 'p')
                {cin>>ID1;
                if(cin.fail()){
                cin.clear();
                 throw Invalid_Input("Was expecting an integer");}
                cin>> potionsq;
                if(cin.fail())
                {
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");
                }
                DoRecoverInCenterCommand(modeldefault, ID1, potionsq);
                }
            else if(code=='a')
            {
                DoAdvanceCommand(modeldefault,v);
            }
            else if(code=='r')
            {
                DoRunCommand(modeldefault,v);
            }
            /*case 'r': if(modeldefault.Update()==false||modeldefault.Gettime()!=5)
                    {
                    modeldefault.Update();
                    }
                    else{
                        break;
                    }*/
            else if(code=='n')
            {
                cin>>type;
                if(cin.fail())
                {
                    cin.clear();
                    throw Invalid_Input("Was expecting a char ");

                }


                cin>>ID1;
                if(cin.fail())
                {
                    cin.clear();
                    throw Invalid_Input("Was expecting a integer");
                    
                }

                cin>>point.x;
                if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}
                cin>> point.y;
                if(cin.fail()){
                    cin.clear();
                    throw Invalid_Input("Was expecting an integer");}

                modeldefault.NewCommand(type, ID1, point);
            }
               
            else if(code=='q')
            {
                 break;
            }
            else if (code != 'q' || code != 'r'|| code != 'a'|| code != 'p'|| code != 'b' || code != 's' || code !='g' || code != 'c' || code!= 'm' ) {
                throw Invalid_Input("Error: Wrong command entered");

            }
        }
    catch (Invalid_Input& except)
    {
        cout<<"Invalid input- "<< except.msg_ptr<< endl;
        
        //actions to be taken if the input is wrong
    }
        
        

    }while(code!='q');

    if (code=='q')
    {
        exit(0);
    }

return 0;
    
}