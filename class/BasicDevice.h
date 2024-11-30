#ifndef BASICDEVICE_H
#define BASICDEVICE_H

class SmartHome; // Предварительное объявление

class BasicDevice {
protected:
    bool turned_on = true; // Состояние включения/выключения устройства
    SmartHome* home = nullptr; // Указатель на SmartHome

public:
    void setHome(SmartHome* h);
    virtual void scenario();
    virtual void setTurnedOn(bool state, bool came_from_scenario = false);
    virtual ~BasicDevice() = default;
};

#endif // BASICDEVICE_H