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

void CurrentConditionsDisplay::update()
{
    if (!weatherData_.expired())
    {
        temperature_ = weatherData_.lock()->get_temperature();
        humidity_ = weatherData_.lock()->get_humidity();
    }
    display();
}

void CurrentConditionsDisplay::display()
{
    std::cout << "Current conditions: " << temperature_ << "F degrees and " << humidity_ << "% humidity" << std::endl;
}