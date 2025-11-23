#include <iostream>
#include <memory>

#include "FlyWithWings.hpp"
#include "MallardDuck.hpp"
#include "Quack.hpp"

MallardDuck::MallardDuck()
{
    flyBehavior_ = std::make_unique<FlyWithWings>();
    quackBehavior_ = std::make_unique<Quack>();
}

void MallardDuck::display() const
{
    std::cout << "I'm a real Mallard duck" << std::endl;
}