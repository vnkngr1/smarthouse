#ifndef LIGHT_H
#define LIGHT_H

#include "BasicDevice.h"
#include <iostream>
#include <string>

class Light : public BasicDevice {
protected:
    int brightness = 0;
    std::string temperature;

public:
    friend std::ostream& operator<<(std::ostream& os, const Light& light);
    void setBrightness(const int input, bool came_from_scenario = false);
    void setTemperature(const std::string& input, bool came_from_scenario = false);
};

#endif // LIGHT_H