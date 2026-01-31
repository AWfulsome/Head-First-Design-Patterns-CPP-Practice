#ifndef STATISTIC_DISPLAY_HPP
#define STATISTIC_DISPLAY_HPP

#include <memory>
#include <limits>

#include "ObserverInterface.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

class StatisticDisplay : public virtual Observer, public virtual DisplayElement
{
public:
    StatisticDisplay(std::weak_ptr<WeatherData> weatherData);
    ~StatisticDisplay();

    // Observer implementation
    // =======================
    void update(float temperature, float humidity, float pressure) override;

    // DisplayElement implementation
    // =============================
    void display() override;

private:
    float minTemp_ = std::numeric_limits<float>::infinity();
    float maxTemp_ = -std::numeric_limits<float>::infinity();
    float sumTemp_ = 0.0f;
    int numReadings_ = 0;

    std::weak_ptr<WeatherData> weatherData_;
};

#endif