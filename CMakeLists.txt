cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake main.cpp Fruit.cpp Fruit.h GameManager.cpp GameManager.h Point.cpp Point.h Snake.cpp Snake.h Board.cpp Board.h)
