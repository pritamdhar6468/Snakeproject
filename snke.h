#ifndef SNKE_H
#define SNKE_H
#include <windows.h>
#include<vector>
#define WIDTH 55
#define HEIGHT 26
using namespace std;

class Snke
{
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector<COORD> body;

public:
    Snke(COORD pos, int vel);
    void change_dir(char dir);
    void move_snke();
    COORD get_pos();
    vector<COORD> get_body();
    bool eaten(COORD food_pos);
    void grow();
    bool collided();
};
#endif