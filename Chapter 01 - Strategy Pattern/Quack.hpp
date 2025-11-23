#ifndef QUACK_HPP
#define QUACK_HPP

#include "QuackBehavior.hpp"

class Quack : public QuackBehavior
{
public:
    void quack() const override;
};

#endif // QUACK_HPP