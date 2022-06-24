#include <iostream>
#include "Point.h"

//konstruktor
Point::Point (const int& x, const int& y)
{
    this -> x = x;
    this -> y = y;
}

void Point::setPoint(const int & x, const int & y) {
    this -> x = x;
    this -> y = y;
}

void Point::setPoint(const Point& point) {
    this -> x = point.getX();
    this -> y = point.getY();
}

int Point::getY() const {
    return y;
}

bool Point::operator==(const Point& point) const
{
    if ((x==point.getX())&& (y==point.getY())){
        return true;
    }

    return false;
}

int Point::getX() const {
    return x;
}


void Point::setX(const int &x) {
    this->x=x;
}

void Point::setY(const int &y) {
    this->y=y;
}


std::ostream& operator<< (std::ostream&out, const Point& point){
    return out<<"("<<point.getX()<<","<<point.getY()<<")";
}
