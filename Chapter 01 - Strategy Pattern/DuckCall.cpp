#include <iostream>
#include <memory>

#include "DuckCall.hpp"
#include "Quack.hpp"

DuckCall::DuckCall()
{
    quackBehavior_ = std::make_unique<Quack>();
}

void DuckCall::display() const
{
    std::cout << "I'm a duck call. Not a duck!" << std::endl;
}

void DuckCall::performQuack() const
{
    quackBehavior_->quack();
}