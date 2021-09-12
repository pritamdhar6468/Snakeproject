#include "snke.h"

Snke::Snke(COORD pos,int vel){
    this->pos=pos;
    this->vel=vel;
    len=1;
    direction='n';
    body.push_back(pos);
}
void Snke::change_dir(char dir){direction=dir;}
void Snke::grow(){len++;}
COORD Snke::get_pos()
{
    return pos;
}
vector<COORD> Snke::get_body() {return body;}


void Snke::move_snke()
{
    switch(direction)
    {
        case 'u':pos.Y-=vel;break;
        case 'b':pos.Y+=vel;break;
        case 'l':pos.X-=vel;break;
        case 'r':pos.X+=vel;break;
    }
    if(pos.X>WIDTH-2) pos.X=0;
    if(pos.X<1)pos.X=WIDTH-2;
    if(pos.Y>HEIGHT-2) pos.Y=0;
    if(pos.Y<1)pos.Y=HEIGHT-2;
    body.push_back(pos);
    if(body.size()>len) body.erase(body.begin());
}


bool Snke::collided()
{
    if(pos.X<1||pos.X>(WIDTH-2)||pos.Y<1||pos.Y>(HEIGHT-2)) return true;
    for(int i=0;i=len-1;i++)
    {
        if(pos.X==body[i].X && pos.Y==body[i].Y){
            return true;
        }
    }
    return false;
}
bool Snke:: eaten(COORD food_pos){
    if(food_pos.X==pos.X&& food_pos.Y==pos.Y)
        return true;
    else return false;
}