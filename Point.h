//
// Created by user on 24.06.2022.
//

#ifndef SNAKE_POINT_H
#define SNAKE_POINT_H


class Point {
    int x{10};
    int y{10};
public:
    Point()=default;
    Point (const int& x, const int&y);
    void setPoint(const int&x, const int&y);
    void setPoint(const Point&point);
    void setX(const int&x);
    void setY(const int&y);
    int getX() const;
    int getY() const;
    bool operator==(const Point& point) const;
};



#endif //SNAKE_POINT_H
