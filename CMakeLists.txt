cmake_minimum_required(VERSION 3.29)
project(smarthouse)

set(CMAKE_CXX_STANDARD 20)

add_executable(smarthouse main.cpp
        class/BasicDevice.h
        class/BasicDevice.cpp
        class/Curtains.h
        class/Curtains.cpp
        class/Light.h
        class/Conditioner.h
        class/Windows.h
        class/Doors.h
        class/SmartHome.h
        class/Light.cpp
        class/Conditioner.cpp
        class/Windows.cpp
        class/Doors.cpp
        class/SmartHome.cpp
)
