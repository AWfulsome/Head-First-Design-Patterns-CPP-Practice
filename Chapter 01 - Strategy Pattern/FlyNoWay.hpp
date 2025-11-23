#ifndef FLYNOWAY_HPP
#define FLYNOWAY_HPP

#include "FlyBehavior.hpp"

class FlyNoWay : public FlyBehavior
{
public:
    void fly() const override;
};

#endif // FLYNOWAY_HPP