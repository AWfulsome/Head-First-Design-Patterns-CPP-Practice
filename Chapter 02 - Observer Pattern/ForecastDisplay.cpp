#include <iostream>

#include "ForecastDisplay.hpp"

ForecastDisplay::ForecastDisplay(std::weak_ptr<WeatherData> weatherData) :
    weatherData_(weatherData)
{
    weatherData_.lock()->register_observer(this);
}

ForecastDisplay::~ForecastDisplay()
{
    if (!weatherData_.expired())
    {
        weatherData_.lock()->remove_observer(this);
    }
}

void ForecastDisplay::update(float temperature, float humidity, float pressure)
{
    lastPressure_ = currentPressure_;
    currentPressure_ = pressure;

    display();
}

void ForecastDisplay::display()
{
    std::cout << "Forecast: ";
    if (currentPressure_ > lastPressure_) std::cout << "Improving weather on the way!" << std::endl;
    else if (currentPressure_ < lastPressure_) std::cout << "Watch out for cooler, rainy weather" << std::endl;
    else std::cout << "More of the same" << std::endl;
}