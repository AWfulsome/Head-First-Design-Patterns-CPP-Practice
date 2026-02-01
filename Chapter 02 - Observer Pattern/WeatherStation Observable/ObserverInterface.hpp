#ifndef OBSERVER_INTERFACE_HPP
#define OBSERVER_INTERFACE_HPP

#include <memory>

class Observer;

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void register_observer(Observer* ob) = 0;
    virtual void remove_observer(Observer* ob) = 0;
    virtual void notify_observers() = 0;
};

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

#endif