#include "Monster.hpp"
#include <iostream>


Monster::Monster()
{
    std::cout << "object created adress = " << this << std::endl;
}

Monster::~Monster()
{
    std::cout << "object distroy adress = " << this << std::endl;
}