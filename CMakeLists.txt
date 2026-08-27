cmake_minimum_required(VERSION 4.3)
project(I_Proyecto_progra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(I_Proyecto_progra
        Cancha.cpp
        Cancha.h
        mainExperimental.cpp
        gestorCanchas.cpp
        gestorCanchas.h)
