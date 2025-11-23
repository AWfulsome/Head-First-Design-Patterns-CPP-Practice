#include <iostream>

#include "Duck.hpp"

void Duck::set_fly_behavior(std::unique_ptr<FlyBehavior> fb)
{
    flyBehavior_ = std::move(fb);
}

void Duck::set_quack_behavior(std::unique_ptr<QuackBehavior> qb)
{
    quackBehavior_ = std::move(qb);
}

void Duck::perform_quack() const
{
    quackBehavior_->quack();
}

void Duck::perform_fly() const
{
    flyBehavior_->fly();
}

void Duck::swim() const
{
    std::cout << "All ducks float, even decoys!" << std::endl;
}