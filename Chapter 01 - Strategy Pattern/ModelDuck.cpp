#include <iostream>
#include <memory>

#include "FlyNoWay.hpp"
#include "ModelDuck.hpp"
#include "MuteQuack.hpp"

ModelDuck::ModelDuck()
{
    flyBehavior_ = std::make_unique<FlyNoWay>();
    quackBehavior_ = std::make_unique<MuteQuack>();
}

void ModelDuck::display() const
{
    std::cout << "I'm a model duck";
}