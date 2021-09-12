#include<iostream>

#include<conio.h>
#include <windows.h>
#include<ctime>
#include "snke.h"
#include"Food.h"
#include "snke.cpp"
#include "Food.cpp"
#define WIDTH 55
#define HEIGHT 26
using namespace std;


int score;

Snke snke({WIDTH/2,HEIGHT/2},1);
Food food;
void wall()
{
    COORD snke_pos=snke.get_pos();
    COORD food_pos=food.get_pos();

    vector<COORD> snke_body=snke.get_body();
    cout<<"Score"<<score<<"\n\n";

    for (int i = 0; i < HEIGHT; i++)
    {
        cout<<"\t\t#";
        for (int j = 0; j < WIDTH -2; j++)
        {
            if(i==0 || i==HEIGHT-1) {
            cout<<'#';}
            else if (i==snke_pos.Y&&j==snke_pos.X) 
            {
               cout<<'0';      //0 is the SNAKE
            }
            else if(i==food_pos.Y && j==food_pos.X){cout<<'@';}
            
            else{
                bool isBodypart= false;
                for(int k=0;k<snke_body.size()-1;k++){
                    if(i==snke_body[k].Y && j+1==snke_body[k].X){
                        cout<<'O';
                        isBodypart=true;
                        break;
                    }
                }
                if(!isBodypart){ cout<<' ';}
            }
        }
        cout<<"#\n";
    }
    
}


int main()
{
    srand(time(NULL));
    bool game_over=false;
    while(!game_over){
        wall();
        if(kbhit()){
            switch(getch())
            {
                case 'w':snke.change_dir('u');break;
                case 'a':snke.change_dir('l');break;
                case 's':snke.change_dir('b');break;
                case 'd':snke.change_dir('r');break;
            }
        }
        
        if(snke.collided()) game_over=true;
        if(snke.eaten(food.get_pos())){
            food.gen_food();
            snke.grow();
            score=score+10;
        }
        snke.move_snke();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    }

}
