#include<iostream>

class Vehicle
{
private:
    /* data */
    double _v;
    int _type;
public:
    Vehicle(double v, int ty): _v(v), _type(ty){ };
    void move();
    ~Vehicle(){};
};

void staticVariable();
void static staticFunction();
