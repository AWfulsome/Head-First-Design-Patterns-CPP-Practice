#ifndef HEAT_INDEX_DISPLAY_HPP
#define HEAT_INDEX_DISPLAY_HPP

#include <memory>

#include "DisplayElement.hpp"
#include "ObserverInterface.hpp"
#include "WeatherData.hpp"

class HeatIndexDisplay : public virtual Observer, public virtual DisplayElement
{
public:
    HeatIndexDisplay(std::weak_ptr<WeatherData> weatherData);
    ~HeatIndexDisplay();

    // Observer implementation
    // =======================
    void update(float temperature, float humidity, float pressure);

    // DisplayElement implementation
    // =============================
    void display();

private:
    float temperature_ = 0.0f;
    float humidity_ = 0.0f;

    std::weak_ptr<WeatherData> weatherData_;

    float compute_heat_index_(float t, float rh) {
        float index = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) +
            (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) +
            (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
            (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *  
            (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
            (0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +     
            0.000000000843296 * (t * t * rh * rh * rh)) -
            (0.0000000000481975 * (t * t * t * rh * rh * rh)));
	    return index;
    }
};

#endif