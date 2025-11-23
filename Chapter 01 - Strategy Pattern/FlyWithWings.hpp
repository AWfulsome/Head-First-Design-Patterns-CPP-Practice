#ifndef FLYWITHWINGS_HPP
#define FLYWITHWINGS_HPP

#include "FlyBehavior.hpp"

class FlyWithWings : public FlyBehavior
{
public:
    void fly() const override;
};

#endif // FLYWITHWINGS_HPP