
#include "FEHLCD.h"
#include "FEHUtility.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

using namespace FEHIcon;


int selected=0;
int difficulty;
int control;

float xpos=0;
float ypos=149;

float tempx;
float tempy;

int quit=0;
int on;
int deaths=0;

float tf;
float ti;

int r=0;

int chosen=0;



//Difficulty selection and controls class
class diff{

public:


//Difficulty screen display function written by Evan and John
int difficultyscreen(){

    chosen=0;

    while (chosen==0){
    LCD.Clear(GREEN);

    //Write title
    LCD.WriteRC("Select difficulty:",1,6);

 
    //Declare button icon
    Icon square_button[1];
 
    //Declare button labels
    char easy[1][20] = {"Easy"};
    char hard[1][20] = {"Hard"};
 

    //Draw buttons
    DrawIconArray(square_button, 1, 1, 50, 150, 80, 80, easy, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 100, 100, 80, 80, hard, WHITE, WHITE);

    LCD.Update();

    //Selection of difficulty
    difficultyselection();

    }

    return chosen;

}

//Difficulty selection touch function written by Evan and John
void difficultyselection(){

    float x,y;

    if (LCD.Touch(&x,&y)){
            
            //Buttons x range
            if (x>80 && x<239){

                //Easy
                if (y>50 && y<89){
                    chosen=1;
                    difficulty=0;
                }

                //Hard
                if (y>100 && y<139){
                    chosen=1;
                    difficulty=1;
                }
            }
    }

    }


//Display controls written by Evan
void controls(){

 
    //Declare button icon
    Icon square_button[1];
 
    //Declare button labels
    char l[1][20] = {"L"};
    char r[1][20] = {"R"};
    char jump[1][20]={"JUMP"};
 

    //Draw buttons
    DrawIconArray(square_button, 1, 1, 200, 0, 0, 260, l, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 200, 0, 260, 0, r, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 200, 0, 100, 100, jump, WHITE, WHITE);

    LCD.Update();

    //Collect input
    controlselect();


}

//Collect user input written by John
void controlselect(){

    float x,y;

    if (LCD.Touch(&x,&y)){

            //L
            if (x>0 && x<119 && y>200){
                if (xpos>=10){
 
                    tempx=xpos;
                    tempy=ypos;
                    xpos-=5;
                    LCD.SetFontColor(WHITE);
                    LCD.DrawPixel(xpos,ypos);
                    LCD.SetFontColor(BLACK);
                    LCD.DrawPixel(tempx,tempy);
    
                    


                }
            }

            //R
            if (x>260 && x<319 && y>200){
                if (xpos<320){

                    tempx=xpos;
                    tempy=ypos;
                    xpos+=5;
                    LCD.SetFontColor(WHITE);
                    LCD.DrawPixel(xpos,ypos);
                    LCD.SetFontColor(BLACK);
                    LCD.DrawPixel(tempx,tempy);
                    

                }
            }

            //Jump
            if (x>100 && x<219 && y>200){
                if (ypos<320){
                    if (on==1){
                        jump();
                    }
                    on=0;
                }
            }

    }


    }


//Jump function written by Evan
void jump(){
int j;
for (j=0;j<30;j++)
{
    tempx=xpos;
    tempy=ypos;
    ypos-=1;
    LCD.SetFontColor(WHITE);
    LCD.DrawPixel(xpos,ypos);
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(tempx,tempy);
    Sleep(2);

}
}


}gamestart;



//Stage class which includes level drawing and gameplay
class stage{

public:

//Start easy level written by Evan
int starteasy(){   

    //Start time
    ti=TimeNow();

    quit=0;

    //Draw level
    LCD.Clear(BLACK);
    LCD.SetFontColor(ORANGERED);
    LCD.FillRectangle(0,180,319,20);
    LCD.SetFontColor(SIENNA);
    LCD.FillRectangle(0,150,30,20);
    LCD.FillRectangle(40,140,20,20);
    LCD.FillRectangle(70,130,100,20);
    LCD.FillRectangle(190,150,100,20);
    LCD.FillRectangle(300,170,19,20);


    while(quit==0){

        
    //Draw rectangle on top of screen to reset timer HUD
    LCD.FillRectangle(0,0,319,50);

    LCD.Update();

    //HUD with time elasped
    LCD.SetFontColor(WHITE);
    LCD.WriteRC((TimeNow()-ti),1,8);

    //Check player position
    platformcheck();

    //Draw player
    LCD.SetFontColor(WHITE);
    LCD.DrawPixel(xpos,ypos);


    //Check for input
    gamestart.controls();

    //Check player position
    platformcheck();

    LCD.Update();

    //Draw player
    LCD.SetFontColor(WHITE);
    LCD.DrawPixel(xpos,ypos);

    //Fill in player's previous position
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(tempx,tempy);

    Sleep(.1);


    }

    return r;

}

//Function to check user position written by Evan
void platformcheck(){

    //X range of platform 1 but not on y level of platform
    if ((xpos>=0)&&(xpos<=30)&&(ypos!=149)){
        on=0;
        gravity();
    }
    
    //In between platforms 1 and 2
    else if ((xpos>30 && xpos<40)){
        on=0;
        gravity();
    }

    //X range of platform 2 but not on y level of platform
    else if (((xpos>=40 && xpos<=60) && (ypos!=139))){
        on=0;
        gravity();
    }

    //In between platforms 2 and 3
    else if ((xpos>60 && xpos<70)){
        on=0;
        gravity();
    }

    //X range of platform 3 but not on y level of platform
    else if (((xpos>=70 && xpos<=170) && (ypos!=129))){
        on=0;
        gravity();
    }

    //In between platforms 3 and 4
    else if ((xpos>170 && xpos<190)){
        on=0;
        gravity();
    }

    //X range of platform 4 but not on y level of platform
    else if (((xpos>=190 && xpos<=290) && (ypos!=149))){
        on=0;
        gravity();
    }

    //In between platforms 4 and 5
    else if ((xpos>290 && xpos<300)){
        on=0;
        gravity();
    }

    //Not on platform 6
    else if ((xpos>=300 && ypos<169)){
        on=0;
        gravity();
    }

    //If on the platform
    else{

        on=1;

    }


    //If in lava
    if (ypos>=180){
        deaths+=1;
        on=1;
        quit=1;
        xpos=0;
        ypos=149;
        end();

    }

    //If at end of level
    if (xpos>=319){

        //Stop timer
        tf=TimeNow()-ti;
        quit=1;
        xpos=0;
        ypos=149;
        end();
    
    }



}

//Gravity function to update position written by Evan
void gravity(){
    tempx=xpos;
    tempy=ypos;
    ypos+=1;
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(tempx,tempy);


}


//End function for once the user has died or reached the end of the level written by John
void end(){

    quit=0;

    LCD.Update();

    //Write title
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.WriteRC("Game Over",1,6);
    LCD.Update();

    while (quit==0)
    {

    //Declare button icon
    Icon square_button[1];
 
    //Declare button labels
    char re[1][20] = {"Replay"};
    char m[1][20] = {"Menu"};
 

    //Draw buttons
    DrawIconArray(square_button, 1, 1, 50, 150, 80, 80, re, WHITE, WHITE);
    DrawIconArray(square_button, 1, 1, 100, 100, 80, 80, m, WHITE, WHITE);

    LCD.Update();

    float x,y;

    //Replay or return to menu

    if (LCD.Touch(&x,&y)){
            if (x>80 && x<239){

                //Replay
                if (y>50 && y<89){
                    r=0;
                    quit=1;
            
                }

                //Return to menu
                if (y>100 && y<139){
                    r=1;
                    quit=1;
                }
            }
    }

    }

    
}



//Hard Level which is identical in logic to easy level but with different platforms written by John

int starthard(){   

    //Start timer
    ti=TimeNow();

    quit=0;

    //Draw level
    LCD.Clear(BLACK);
    LCD.SetFontColor(ORANGERED);
    LCD.FillRectangle(0,180,319,20);
    LCD.SetFontColor(SIENNA);
    LCD.FillRectangle(0,150,15,20);
    LCD.FillRectangle(30,135,10,20);
    LCD.FillRectangle(70,130,10,20);
    LCD.FillRectangle(110,160,8,20);

    LCD.FillRectangle(150,150,12,20);
    LCD.FillRectangle(180,140,15,20);
    LCD.FillRectangle(220,160,5,20);
    LCD.FillRectangle(250,160,5,20);
    LCD.FillRectangle(280,160,5,20);
    LCD.FillRectangle(310,150,9,20);

    
    while(quit==0){

    //Draw rectangle over top of screen to reset timer HUD
    LCD.FillRectangle(0,0,319,50);

    LCD.Update();

    LCD.SetFontColor(WHITE);

    //HUD time
    LCD.WriteRC((TimeNow()-ti),1,8);

    //Check player position
    platformcheckhard();

    //Draw player
    LCD.SetFontColor(WHITE);
    LCD.DrawPixel(xpos,ypos);

    //Check for input
    gamestart.controls();

    //Check player position
    platformcheckhard();

    LCD.Update();

    //Draw plaayer
    LCD.SetFontColor(WHITE);
    LCD.DrawPixel(xpos,ypos);

    //Erase player's previous position
    LCD.SetFontColor(BLACK);
    LCD.DrawPixel(tempx,tempy);

    Sleep(.1);


    }

    return r;

}

//Function to check player position written by John
void platformcheckhard(){
    

    //X range of platform 1 but not on y level of platform
    if ((xpos>=0)&&(xpos<=15)&&(ypos!=149)){
        on=0;
        gravity();
    }

    //In between platforms 1 and 2
    else if ((xpos>15 && xpos<30)){
        on=0;
        gravity();
    }

    //X range of platform 2 but not on y level of platform
    else if (((xpos>=30 && xpos<=40) && (ypos!=134))){
        on=0;
        gravity();
    }

    //In between platforms 2 and 3
    else if ((xpos>40 && xpos<70)){
        on=0;
        gravity();
    }

    //X range of platform 3 but not on y level of platform
    else if (((xpos>=70 && xpos<=80) && (ypos!=129))){
        on=0;
        gravity();
    }

    //In between platforms 3 and 4
    else if ((xpos>80 && xpos<110)){
        on=0;
        gravity();
    }

    //X range of platform 4 but not on y level of platform
    else if (((xpos>=110 && xpos<=118) && (ypos!=159))){
        on=0;
        gravity();
    }

    //In between platforms 4 and 5
    else if ((xpos>118 && xpos<150)){
        on=0;
        gravity();
    }

    //X range of platform 5 but not on y level of platform
    else if (((xpos>=150 && xpos<=162) && (ypos!=149))){
        on=0;
        gravity();
    }

    //In between platforms 5 and 6
    else if ((xpos>162 && xpos<180)){
        on=0;
        gravity();
    }

    //X range of platform 6 but not on y level of platform
    else if ((((xpos>=180) && (xpos<=195)) && (ypos!=139))){
        on=0;
        gravity();
       
       
    }

    //In between platforms 6 and 7
    else if ((xpos>195 && xpos<220)){
        on=0;
        gravity();

    }


    //X range of platform 7 but not on y level of platform
    else if (((xpos>=220 && xpos<=225) && (ypos!=159))){
        on=0;
        gravity();
    }

    //In between platforms 7 and 8
    else if ((xpos>225 && xpos<250)){
        on=0;
        gravity();
    }


    //X range of platform 8 but not on y level of platform
    else if (((xpos>=250 && xpos<=255) && (ypos!=159))){
        on=0;
        gravity();
    }

    //In between platforms 8 and 9
    else if ((xpos>255 && xpos<280)){
        on=0;
        gravity();
    }

    //X range of platform 9 but not on y level of platform
    else if (((xpos>=280 && xpos<=285) && (ypos!=159))){
        on=0;
        gravity();
    }

    //In between platforms 9 and 10
    else if ((xpos>285 && xpos<310)){
        on=0;
        gravity();
    }

    //X range of final platform but not on y level of platform
    else if (((xpos>=310 && xpos<=319) && (ypos!=149))){
        on=0;
        gravity();
    }

    //If on platform
    else{
        
        on=1;
        
    }


    //If in lava
    if (ypos>=180){
        deaths+=1;
        on=1;
        quit=1;
        xpos=0;
        ypos=149;
        end();
        
    }

    //If end of level has been reached
    if (xpos>=319){
        tf=TimeNow()-ti;
        quit=1;
        xpos=0;
        ypos=149;
        end();

    }


}/*End Hard Level*/
}level;


