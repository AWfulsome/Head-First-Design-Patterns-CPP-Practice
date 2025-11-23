#ifndef MODELDUCK_HPP
#define MODELDUCK_HPP

#include "Duck.hpp"

class ModelDuck : public Duck
{
public:
    ModelDuck();
    
    void display() const override;
};

#endif // MODELDUCK_HPP