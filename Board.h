//
// Created by user on 24.06.2022.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H
#include <iostream>
#include <vector>

class Board {
    int width {10};
    int height{10};
    std::vector<std::vector<char>> area;

public:
//    Board()=default;
    Board (const int&, const int&);
    ~Board()=default;
    int getWidth() const;
    int getHeight() const;

};


#endif //SNAKE_BOARD_H
