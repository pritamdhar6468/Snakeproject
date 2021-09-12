#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
#include<cstdlib>
#define WIDTH 55
#define HEIGHT 26
class Food
{
private:
    COORD pos;

public:
    Food();
    void gen_food();
    COORD get_pos();

};
#endif