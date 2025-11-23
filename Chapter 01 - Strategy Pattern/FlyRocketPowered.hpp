#ifndef FLYROCKETPOWERED_HPP
#define FLYROCKETPOWERED_HPP

#include "FlyBehavior.hpp"

class FlyRocketPowered : public FlyBehavior
{
public:
    void fly() const override;
};

#endif // FLYROCKETPOWERED_HPP