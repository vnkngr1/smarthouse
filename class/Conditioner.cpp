#include "Conditioner.h"

std::ostream& operator<<(std::ostream& os, const Conditioner& conditioner) {
    os << "Conditioner [Включен: " << (conditioner.turned_on ? "Да" : "Нет")
       << ", Температура: " << conditioner.temperature
       << ", Режим работы: " << conditioner.working_mode << "]";
    return os;
}

void Conditioner::setTemperature(const int input, bool came_from_scenario) {
    temperature = input;
    if (!came_from_scenario) {
        scenario();
    }
}

void Conditioner::setWorkingMode(const std::string& input, bool came_from_scenario) {
    working_mode = input;
    if (!came_from_scenario) {
        scenario();
    }
}

void Conditioner::setTurnedOn(bool state, bool came_from_scenario) {
    turned_on = state;
    if (!came_from_scenario) {
        scenario();
    }
}