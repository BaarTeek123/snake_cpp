
#include <iostream>
#include "Fruit.h"

Fruit::Fruit(const int& x,  const int& y,const int& score) : position(x,y),score(score){}

Fruit::Fruit(const int &x, const int &y, const int &score, const char &image) : position(x,y),score(score),image(image){
}

std::ostream& operator<< (std::ostream&out, const Point& point);

int Fruit::getScore() const {
    return score;
}

char Fruit::getImage() const {
    return image;
}

void Fruit::setImage(const char& image)
{
    this->image=image;
}

void Fruit::setPosition(const int & x, const int &y){
    position.setPoint(x,y);
}

Point Fruit::getPosition() const{
    return position;
}

Fruit Fruit::operator = (const Fruit& fruit)
{
    if (this==&fruit){
        return *this;
    }

    delete &image;
    delete &position;
    delete &score;

    this->score = fruit.getScore();
    this->position =fruit.getPosition();
    this->image = fruit.getImage();
}

