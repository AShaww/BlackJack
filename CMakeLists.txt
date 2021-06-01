cmake_minimum_required(VERSION 3.17)
project(EasyJack)

set(CMAKE_CXX_STANDARD 14)

include_directories(EasyJack)

add_executable(EasyJack
    EasyJack/Card.h
    EasyJack/Deck.h
    EasyJack/Game.h
    EasyJack/main.cpp
    EasyJack/mainHeader.h
    EasyJack/Player.h)
