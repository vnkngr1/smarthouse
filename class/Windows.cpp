#include "Windows.h"

std::ostream& operator<<(std::ostream& os, const Windows& windows) {
    os << "Windows [Включен: " << (windows.turned_on ? "Да" : "Нет")
       << ", Открыты: " << (windows.opened ? "Да" : "Нет")
       << ", Заблокированы: " << (windows.blocked ? "Да" : "Нет") << "]";
    return os;
}

void Windows::setBlocked(const bool input, bool came_from_scenario) {
    if (input) { opened = false; }
    blocked = input;
    if (!came_from_scenario) {
        scenario();
    }
}

void Windows::setOpened(const bool input, bool came_from_scenario) {
    if (blocked) {
        std::cout << "Окно заблокировано, его нельзя открыть!" << std::endl;
    } else {
        opened = input;
        if (!came_from_scenario) {
            scenario();
        }
    }
}

bool Windows::getOpened() const {
    return opened;
}