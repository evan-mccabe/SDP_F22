#include "FEHLCD.h"
#include "FEHUtility.h"
#include  <stdio.h>
#include  <math.h>
#include <iostream>
#include <time.h>
#include <testgamestart.h>
#include <iostream>
using namespace std;

using namespace FEHIcon;

int td=0;
float tb;

int s;
int z;

int rep=0;
int return1=0;


class m{

public:


//Function definitions

//Start menu function written by Evan
int menustart() {


    z=0;
    rep=0;

    while (z==0){
    LCD.Clear(GREEN);

    //Write title
    LCD.WriteRC("Mountaineer",1,8);

 
    //Declare button icon
    Icon square_button[1];
 
    //Declare button labels
    char start[1][20] = {"Start"};
    char stats[1][20] = {"View Stats"};
    char instructions[1][20] = {"Instructions"};
    char credits[1][20] = {"View Credits"};

    //Draw buttons
    DrawIconArray(square_button, 1, 1, 50, 150, 80, 80, start, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 100, 100, 80, 80, stats, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 150, 50, 80, 80, instructions, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 200, 0, 80, 80, credits, WHITE, WHITE);
    LCD.Update();


    //User selection
    z=selection();

    }

    return z;

}


//Return button function written by Evan
void quit(){

    float x,y;
    while (!LCD.Touch(&x,&y)){}
    if (LCD.Touch(&x,&y)){
            if (x>240 && y>200){
                    return1=1;
            }
    }

    
}

//Credits screen function written by John
void credits(){

    return1=0;

    while (return1==0){

    LCD.Clear(GREEN);
    LCD.WriteAt("Credits:", 91, 20);
    LCD.WriteAt("Evan McCabe",91,50);
    LCD.WriteAt("John Hinton",91,80);
    LCD.WriteAt("FEH Proteus",91,110);
    LCD.Update();
    
    quitbutton();
    }

}

//Instructions screen function written by John
void instructions(){

    return1=0;
    while (return1==0){
    LCD.Clear(GREEN);
    LCD.WriteRC("Instructions:",1,1);
    LCD.WriteRC("Objective:",3,1);
    LCD.WriteRC("Get to the end",4,1);
    LCD.WriteRC("of the level quickly",5,1);
    LCD.WriteRC("without dying",6,1);

    LCD.WriteRC("Controls:",8,1);
    LCD.WriteRC("Press L/R to move",9,1);
    LCD.WriteRC("Press JUMP to jump",10,1);
    LCD.Update();


    quitbutton();
    quit();
    }
}

//Stats screen function written by John
void stats(){

    return1=0;
    while (return1==0){
    LCD.Clear(GREEN);
    LCD.WriteRC("Stats:",1,1);
    LCD.WriteRC("All time Deaths:",3,1);
    if (td>0)
    {
        LCD.WriteRC(td,4,1);
    }
    else{
        LCD.WriteRC("0",4,1);
    }
    
    LCD.WriteRC("Last time:",5,1);
    LCD.WriteRC(tf,6,1);
    LCD.WriteRC("s",6,8);


    quitbutton();
    quit();
    }



}


//Main menu selection function written by Evan
int selection(){

    float x,y;

    s=0;
    
    while (!LCD.Touch(&x,&y)){}
    if (LCD.Touch(&x,&y)){

            //X range of all buttons
            if (x>80 && x<239){

                //Start
                if (y>50 && y<89){
                    s=1;
                }
                
                //View Stats
                if (y>100 && y<139){
                    stats();
                }

                //View instructions
                if (y>150 && y<189){
                    instructions();
                }

                //View credits
                if (y>200){
                    credits();
                }
        }
    }
return s;

}

//Quit button drawing written by John
void quitbutton(){
    Icon square_button[1];
    char q[1][20] = {"Return"};
    DrawIconArray(square_button, 1, 1, 200, 0, 240, 0, q, WHITE, WHITE);
    LCD.Update();
    quit();

}

}menu;
