#ifndef CONDITIONER_H
#define CONDITIONER_H

#include "BasicDevice.h"
#include <iostream>
#include <string>

class Conditioner : public BasicDevice {
protected:
    int temperature = 0;
    std::string working_mode;

public:
    friend std::ostream& operator<<(std::ostream& os, const Conditioner& conditioner);
    void setTemperature(const int input, bool came_from_scenario = false);
    void setWorkingMode(const std::string& input, bool came_from_scenario = false);
    void setTurnedOn(bool state, bool came_from_scenario = false) override;
};

#endif // CONDITIONER_H