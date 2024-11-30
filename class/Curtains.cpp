#include "Curtains.h"

std::ostream& operator<<(std::ostream& os, const Curtains& curtains) {
    os << "Curtains [Открыты: " << (curtains.opened ? "Да" : "Нет") << "]";
    return os;
}

void Curtains::setOpened(bool state, bool came_from_scenario) {
    opened = state;
    if (!came_from_scenario) {
        scenario();
    }
}

bool Curtains::isClosed() const {
    return !opened;
}