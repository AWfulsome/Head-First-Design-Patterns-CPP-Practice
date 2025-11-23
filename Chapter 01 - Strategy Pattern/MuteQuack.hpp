#ifndef MUTEQUACK_HPP
#define MUTEQUACK_HPP

#include "QuackBehavior.hpp"

class MuteQuack : public QuackBehavior
{
public:
    void quack() const override;
};

#endif // MUTEQUACK_HPP