#include <iostream>

#include "class/Conditioner.h"
#include "class/Light.h"
#include "class/Windows.h"
#include "class/SmartHome.h"
#include "class/Curtains.h"

int main()
{
    //инициализация дома
    SmartHome house;

    //инициализация света
    Light light1;
    light1.setBrightness(1);
    light1.setTemperature("Тёплый");
    house.appendDevice(&light1);

    //инициализация кондиционера
    Conditioner condition;
    condition.setTemperature(21);
    condition.setWorkingMode("Авто");
    house.appendDevice(&condition);

    //инициализация окон и дверей
    Windows windows;
    house.appendDevice(&windows);
    Doors doors;
    house.appendDevice(&doors);

    //инициализация штор
    Curtains curtains;
    house.appendDevice(&curtains);

}
