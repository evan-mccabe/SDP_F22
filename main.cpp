
#include <testmenu.h>
#include <FEHSD.h>

using namespace FEHIcon;

//FEH Proteus Simulator documentation as well has help from the TAs and professor was used to help develop this game


//Entry point to the program

int main() {

FEHFile *death;


while (1){


//Persistent all time deaths stat opening and storing
//Written by Evan

int pd;

death=SD.FOpen("deaths.txt","r+");

td=deaths;

while (!SD.FEof(death)){

    SD.FScanf(death,"%d",&pd);
    td+=pd;

}

if (deaths>pd){
    SD.FPrintf(death,"%d",deaths);
}

SD.FClose(death);



//Initialize conditions for loop exit

int selected=0;
int finished=0;
int started=0;


//Start menu
while (started==0){

started=menu.menustart();

}


float a,b;
while(LCD.Touch(&a,&b));


//Start difficulty screen
while (selected==0){

selected=gamestart.difficultyscreen();

}


//Start easy or hard level
while (finished==0){

//Easy
    if (difficulty==0){

        finished=level.starteasy();
    }

//Hard
    if (difficulty==1){

        finished=level.starthard();

    }

}


while(LCD.Touch(&a,&b));


}





}







