//
// Created by user on 24.06.2022.
//

#ifndef SNAKE_FRUIT_H
#define SNAKE_FRUIT_H

#include "Point.h"

class Fruit {
    Point position{1,0};
    int score{1};
    char image{'O'};
public:
    Fruit()=default;
    Fruit(const int &x, const int &y, const int &score);
    Fruit(const int &x, const int &y, const int &score, const char &image);
    int getScore() const;
    char getImage() const;
    void setImage(const char&);
    void setPosition(const int &x, const int &y);
    Point getPosition() const;
    Fruit operator = (const Fruit& fruit);


};



#endif //SNAKE_FRUIT_H
