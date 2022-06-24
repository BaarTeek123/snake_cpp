#include <iostream>
#include "Snake.h"

std::ostream& operator<< (std::ostream&out, const Point& point);

Snake::Snake(const int & x, const int &y) : headPosition(x,y), length(1){
    body.reserve(35); //35-max width & max height
}

void Snake::grow(const int & update) {
    this->length+=update;
}

int Snake::getLength() const {
    return length;
}

Point& Snake::getHeadPosition(){
    return headPosition;
}

void Snake::moveUp() {
    headPosition.setX(headPosition.getX()-1);
}

void Snake::moveLeft() {
    headPosition.setY(headPosition.getY()-1);
}

void Snake::moveDown() {
    headPosition.setX(headPosition.getX()+1);
}

void Snake::moveRight() {
    headPosition.setY(headPosition.getY()+1);
}

std::vector<Point>& Snake::getBody()
{
    return body;
}

Point& Snake::getBodyPosition(const int &index) {
    return (body[index]);
}
