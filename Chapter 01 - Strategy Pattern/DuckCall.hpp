#ifndef DUCKCALL_HPP
#define DUCKCALL_HPP

#include <memory>

#include "QuackBehavior.hpp"

class DuckCall
{
public:
    DuckCall();

    void display() const;
    void performQuack() const;

private:
    std::unique_ptr<QuackBehavior> quackBehavior_;
};

#endif // DUCKCALL_HPP