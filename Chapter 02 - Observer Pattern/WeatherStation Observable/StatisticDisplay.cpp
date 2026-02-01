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

void StatisticDisplay::update()
{
    if (!weatherData_.expired())
    {
        float currTemp = weatherData_.lock()->get_temperature();
        minTemp_ = std::min(minTemp_, currTemp);
        maxTemp_ = std::max(maxTemp_, currTemp);
        sumTemp_ += currTemp;
        ++numReadings_;
    }

    display();
}

void StatisticDisplay::display()
{
    std::cout << "Avg/Max/Min temperature = " << (sumTemp_ / numReadings_) << "/" << maxTemp_ << "/" << minTemp_ << std::endl;
}