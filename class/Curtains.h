#ifndef CURTAINS_H
#define CURTAINS_H

#include "BasicDevice.h"
#include <iostream>

class Curtains : public BasicDevice {
protected:
    bool opened = true;

public:
    friend std::ostream& operator<<(std::ostream& os, const Curtains& curtains);
    void setOpened(bool state, bool came_from_scenario = false);
    bool isClosed() const;
};

#endif // CURTAINS_H