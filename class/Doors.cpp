#include "Doors.h"

std::ostream& operator<<(std::ostream& os, const Doors& doors) {
    os << "Doors [Включен: " << (doors.turned_on ? "Да" : "Нет")
       << ", Открыты: " << (doors.opened ? "Да" : "Нет")
       << ", Заблокированы: " << (doors.blocked ? "Да" : "Нет") << "]";
    return os;
}

void Doors::setBlocked(const bool input, bool came_from_scenario) {
    if (input) { opened = false; }
    blocked = input;
    if (!came_from_scenario) {
        scenario();
    }
}

void Doors::setOpened(const bool input, bool came_from_scenario) {
    if (blocked) {
        std::cout << "Дверь заблокирована, её нельзя открыть!" << std::endl;
    } else {
        opened = input;
        if (!came_from_scenario) {
            scenario();
        }
    }
}

