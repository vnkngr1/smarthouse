#include "BasicDevice.h"
#include "SmartHome.h"

void BasicDevice::setHome(SmartHome* h) {
    home = h;
}

void BasicDevice::scenario() {
    if (home) {
        home->applyScenarios();
    }
}

void BasicDevice::setTurnedOn(bool state, bool came_from_scenario) {
    turned_on = state;
    if (!came_from_scenario) {
        scenario();
    }
}