#ifndef DUCK_HPP
#define DUCK_HPP

#include <memory>

#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

class Duck
{
public:
    Duck() {};

    void set_fly_behavior(std::unique_ptr<FlyBehavior> fb);
    void set_quack_behavior(std::unique_ptr<QuackBehavior> qb);
    void perform_fly() const;
    void perform_quack() const;
    void swim() const;
    virtual void display() const = 0;

protected:
    std::unique_ptr<FlyBehavior> flyBehavior_ = nullptr;
    std::unique_ptr<QuackBehavior> quackBehavior_ = nullptr;
};

#endif // DUCK_HPP