#ifndef DOORS_H
#define DOORS_H

#include "BasicDevice.h"
#include <iostream>

class Doors : public BasicDevice {
protected:
    bool opened = false;
    bool blocked = false;

public:
    friend std::ostream& operator<<(std::ostream& os, const Doors& doors);
    void setBlocked(const bool input, bool came_from_scenario = false);
    void setOpened(const bool input, bool came_from_scenario = false);
};

#endif // DOORS_H