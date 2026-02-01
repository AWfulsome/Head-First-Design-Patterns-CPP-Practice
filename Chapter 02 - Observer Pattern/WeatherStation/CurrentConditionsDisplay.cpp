#include <iostream>

#include "CurrentConditionsDisplay.hpp"

CurrentConditionsDisplay::CurrentConditionsDisplay(std::weak_ptr<WeatherData> weatherData) :
    weatherData_(weatherData)
{
    weatherData_.lock()->register_observer(this);
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    if (!weatherData_.expired())
    {
        weatherData_.lock()->remove_observer(this);
    }
}

void CurrentConditionsDisplay::update(float temperature, float humidity, float pressure)
{
    temperature_ = temperature;
    humidity_ = humidity;
    display();
}

void CurrentConditionsDisplay::display()
{
    std::cout << "Current conditions: " << temperature_ << "F degrees and " << humidity_ << "% humidity" << std::endl;
}