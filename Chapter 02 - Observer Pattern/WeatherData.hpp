#ifndef WEATHER_DATA_HPP
#define WEATHER_DATA_HPP

#include <memory>
#include <vector>

#include "ObserverInterface.hpp"

class WeatherData : public virtual Subject
{
public:
    // Subject implementation
    // ======================
    virtual void register_observer(Observer* ob) override;
    virtual void remove_observer(Observer* ob) override;
    virtual void notify_observers() override;
    
    // WeatherData methods
    // ===================
    void set_measurements(float temperature, float humidity, float pressure);
    void measurements_changed();

private:
    float temperature_;
    float humidity_;
    float pressure_;
    std::vector<Observer*> observers_;
};

#endif