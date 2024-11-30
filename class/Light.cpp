#include "Light.h"

std::ostream& operator<<(std::ostream& os, const Light& light) {
    os << "Light [Включен: " << (light.turned_on ? "Да" : "Нет")
       << ", Яркость: " << light.brightness
       << ", Температура света: " << light.temperature << "]";
    return os;
}

void Light::setBrightness(const int input, bool came_from_scenario) {
    if (input == 0) { turned_on = false; }
    if (input != 0 && !turned_on) { turned_on = true; }
    brightness = input;
    if (!came_from_scenario) {
        scenario();
    }
}

void Light::setTemperature(const std::string& input, bool came_from_scenario) {
    temperature = input;
    if (!came_from_scenario) {
        scenario();
    }
}