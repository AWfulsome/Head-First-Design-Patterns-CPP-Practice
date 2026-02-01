#include <iostream>

#include "HeatIndexDisplay.hpp"

HeatIndexDisplay::HeatIndexDisplay(std::weak_ptr<WeatherData> weatherData) :
    weatherData_(weatherData)
{
    weatherData_.lock()->register_observer(this);
}

HeatIndexDisplay::~HeatIndexDisplay()
{
    if (!weatherData_.expired())
        weatherData_.lock()->remove_observer(this);
}

void HeatIndexDisplay::update(float temperature, float humidity, float pressure)
{
    temperature_ = temperature;
    humidity_ = humidity;
    display();
}

void HeatIndexDisplay::display()
{
    std::cout << "Heat index is " << compute_heat_index_(temperature_, humidity_) << std::endl;
}