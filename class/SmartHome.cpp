#include "SmartHome.h"

void SmartHome::appendDevice(const std::variant<Light*, Conditioner*, Doors*, Windows*, Curtains*>& device) {
    devices.push_back(device);
    std::visit([this](auto* dev) {
        if (dev) {
            dev->setHome(this);
        }
    }, device);
}

void SmartHome::applyScenarios() {
    bool anyWindowOpened = false;
    bool curtainsClosed = false;

    // Проверяем состояние окон и штор
    for (const auto& device : devices) {
        std::visit([&](auto* dev) {
            if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Windows>) {
                if (dev && dev->getOpened()) {
                    anyWindowOpened = true;
                }
            } else if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Curtains>) {
                if (dev && dev->isClosed()) {
                    curtainsClosed = true;
                }
            }
        }, device);
    }

    // Если есть открытые окна, выключаем кондиционеры
    if (anyWindowOpened) {
        for (auto& device : devices) {
            std::visit([](auto* dev) {
                if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Conditioner>) {
                    if (dev) {
                        dev->setTurnedOn(false, true); // Выключаем кондиционер
                    }
                }
            }, device);
        }
    }

    // Если шторы закрыты, включаем свет; если открыты, выключаем свет
    for (auto& device : devices) {
        std::visit([curtainsClosed](auto* dev) {
            if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Light>) {
                if (dev) {
                    dev->setTurnedOn(curtainsClosed, true); // Управляем состоянием света
                }
            }
        }, device);
    }
}

void SmartHome::securitySystem(const int input) {
    security = input; // Устанавливаем текущий уровень защиты

    for (auto& device : devices) {
        std::visit([input](auto* dev) {
            if (dev) {
                // Если устройство - Doors или Windows, устанавливаем блокировку
                if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Doors>) {
                    dev->setBlocked(input >= 1); // Заблокировать двери для input >= 1
                } else if constexpr (std::is_same_v<std::remove_pointer_t<decltype(dev)>, Windows>) {
                    dev->setBlocked(input == 2); // Заблокировать окна только для input == 2
                }
            }
        }, device);
    }
}

std::ostream& operator<<(std::ostream& os, const SmartHome& home) {
    os << "SmartHome [Уровень защиты: " << home.security << "]\n";
    os << "Устройства:\n";

    for (const auto& device : home.devices) {
        std::visit([&os](auto dev) {
            if (dev) {
                os << *dev << "\n"; // Разыменовываем указатель и вызываем перегруженный `<<`
            } else {
                os << "Null device\n"; // Если указатель нулевой, выводим это
            }
        }, device);
    }

    return os;
}