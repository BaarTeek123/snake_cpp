//
// Created by user on 24.06.2022.
//

#ifndef SNAKE_GAMEMANAGER_H
#define SNAKE_GAMEMANAGER_H


#include "Snake.h"
#include "Board.h"
#include "Fruit.h"


enum Direction {UP,DOWN,LEFT,RIGHT};


class GameManager {
    Board board{10,10};
    Snake snake{5,5};
    int score{0};
    Fruit fruit{1,2,1,'&'};
    std::vector<Fruit>fruits;
    bool gameOver{false};
    Direction snakeDirection;
public:
    GameManager(const int &width, const int &height, const std::vector<Fruit>& fruits);
    GameManager() = default;
    // GameManager(const int& width, const int& height, const Fruit& fruit);
    void input();
    void gameLogic();
    void info();
    void print();
    Snake& getSnake();
    void game();
    int getScore() const;



};



#endif //SNAKE_GAMEMANAGER_H
