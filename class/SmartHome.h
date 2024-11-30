#ifndef SMARTHOME_H
#define SMARTHOME_H

#include "Light.h"
#include "Conditioner.h"
#include "Windows.h"
#include "Doors.h"
#include "Curtains.h"
#include <variant>
#include <vector>
#include <iostream>

class SmartHome {
protected:
    std::vector<std::variant<Light*, Conditioner*, Doors*, Windows*, Curtains*>> devices;
    int security = 0;

public:
    void appendDevice(const std::variant<Light*, Conditioner*, Doors*, Windows*, Curtains*>& device);
    void applyScenarios();
    void securitySystem(const int input);
    friend std::ostream& operator<<(std::ostream& os, const SmartHome& home);
};

#endif // SMARTHOME_H