#include <memory>

#include "WeatherData.hpp"
#include "CurrentConditionsDisplay.hpp"
#include "ForecastDisplay.hpp"
#include "HeatIndexDisplay.hpp"
#include "StatisticDisplay.hpp"

int main()
{
    auto weatherData = std::make_shared<WeatherData>();
    auto currDisplay = new CurrentConditionsDisplay(weatherData);
    auto statDisplay = new StatisticDisplay(weatherData);
    auto forecastDisplay = new ForecastDisplay(weatherData);
    auto heatIndexDisplay = new HeatIndexDisplay(weatherData);

    weatherData->set_measurements(80, 65, 30.4f);
    weatherData->set_measurements(82, 70, 29.2f);
    weatherData->set_measurements(78, 90, 29.2f);
    
    return 0;
}