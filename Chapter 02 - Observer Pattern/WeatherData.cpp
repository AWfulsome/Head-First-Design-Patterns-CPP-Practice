#include <algorithm>

#include "WeatherData.hpp"

void WeatherData::register_observer(Observer* ob)
{
    observers_.emplace_back(ob);
}

void WeatherData::remove_observer(Observer* ob)
{
    observers_.erase(std::find(observers_.begin(), observers_.end(), ob));
}

void WeatherData::notify_observers()
{
    for (auto ob : observers_)
        ob->update(temperature_, humidity_, pressure_);
}

void WeatherData::set_measurements(float temperature, float humidity, float pressure)
{
    this->temperature_ = temperature;
    this->humidity_ = humidity;
    this->pressure_ = pressure;
    measurements_changed();
}

void WeatherData::measurements_changed()
{
    notify_observers();
}