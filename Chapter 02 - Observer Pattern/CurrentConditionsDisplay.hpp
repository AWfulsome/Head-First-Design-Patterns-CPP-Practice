#ifndef CURRENT_CONDITIONS_DISPLAY_HPP
#define CURRENT_CONDITIONS_DISPLAY_HPP

#include <iostream>
#include <memory>

#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class CurrentConditionsDisplay : public virtual Observer, public virtual DisplayElement
{
public:
    CurrentConditionsDisplay(std::weak_ptr<WeatherData> weatherData);
    ~CurrentConditionsDisplay();

    // Observer implementation
    // =======================
    virtual void update(float temperature, float humidity, float pressure) override;

    // DisplayElement implementation
    // =============================
    virtual void display() override;
    
private:
    std::weak_ptr<WeatherData> weatherData_;
    float temperature_ = 0.0f;
    float humidity_ = 0.0f;
    float pressure_ = 0.0f;
};

#endif