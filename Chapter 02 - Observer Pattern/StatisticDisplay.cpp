#include <iostream>

#include "StatisticDisplay.hpp"

StatisticDisplay::StatisticDisplay(std::weak_ptr<WeatherData> weatherData) :
    weatherData_(weatherData)
{

    weatherData_.lock()->register_observer(this);
}

StatisticDisplay::~StatisticDisplay()
{
    if (!weatherData_.expired())
    {
        weatherData_.lock()->remove_observer(this);
    }
}

void StatisticDisplay::update(float temperature, float humidity, float pressure)
{
    minTemp_ = std::min(minTemp_, temperature);
    maxTemp_ = std::max(maxTemp_, temperature);
    sumTemp_ += temperature;
    ++numReadings_;

    display();
}

void StatisticDisplay::display()
{
    std::cout << "Avg/Max/Min temperature = " << (sumTemp_ / numReadings_) << "/" << maxTemp_ << "/" << minTemp_ << std::endl;
}