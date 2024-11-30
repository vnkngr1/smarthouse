/#ifndef WINDOWS_H
#define WINDOWS_H

#include "BasicDevice.h"
#include <iostream>

class Windows : public BasicDevice {
protected:
    bool opened = false;
    bool blocked = false;

public:
    friend std::ostream& operator<<(std::ostream& os, const Windows& windows);
    void setBlocked(const bool input, bool came_from_scenario = false);
    void setOpened(const bool input, bool came_from_scenario = false);
    bool getOpened() const;
};

#endif // WINDOWS_H