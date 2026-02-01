#ifndef FORECAST_DISPLAY_HPP
#define FORECAST_DISPLAY_HPP

#include <memory>

#include "ObserverInterface.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class ForecastDisplay : public virtual Observer, public virtual DisplayElement
{
public:
    ForecastDisplay(std::weak_ptr<WeatherData> weatherData);
    ~ForecastDisplay();

    // Observer implementation
    // =======================
    void update() override;

    // DisplayElement implementation
    // =============================
    void display() override;

private:
    float currentPressure_ = 29.92f;
    float lastPressure_ = 29.92f;

    std::weak_ptr<WeatherData> weatherData_;
};

#endif