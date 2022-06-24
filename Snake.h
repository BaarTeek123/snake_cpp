//
// Created by user on 24.06.2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "Point.h"

#include <vector>
#include "Point.h"

class Snake {
    int length{0};
    Point headPosition{0,0};
    std::vector<Point> body;
public:
    Snake ()=default;
    Snake (const int&x, const int&y);
    void grow(const int& update);
    int getLength() const;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    std::vector<Point>& getBody() ;
    Point& getBodyPosition(const int& index);
    Point &getHeadPosition();
};




#endif //SNAKE_SNAKE_H
