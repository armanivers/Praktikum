#include "punkt.h"
Punkt::Punkt()
{
    setX(0);
    setY(0);
}
Punkt::Punkt(int x_koor, int y_koor)
{
    setX(x_koor);
    setY(y_koor);
}
int Punkt::getX(){return x;}
int Punkt::getY(){return y;}
void Punkt::setX(int x_koor){
x = x_koor;
}
void Punkt::setY(int y_koor){
y = y_koor;
}