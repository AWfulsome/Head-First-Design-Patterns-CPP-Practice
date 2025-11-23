#include <iostream>

#include "MuteQuack.hpp"

void MuteQuack::quack() const
{
    std::cout << "<< Silence >>" << std::endl;
}