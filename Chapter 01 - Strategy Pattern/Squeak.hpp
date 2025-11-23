#ifndef SQUEAK_HPP
#define SQUEAK_HPP

#include "QuackBehavior.hpp"

class Squeak : public QuackBehavior
{
public:
    void quack() const override;
};

#endif // SQUEAK_HPP