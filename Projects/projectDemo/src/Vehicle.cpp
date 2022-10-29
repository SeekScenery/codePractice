#include "Vehicle.h"

void Vehicle::move(){ std::cout << "move" << std::endl;}

void staticVariable()
{
    static int test;
    std::cout << test << std::endl; 
    test++;
    staticFunction();
}

void static staticFunction()
{
    std::cout << "Static Function" << std::endl; 
}