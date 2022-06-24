//
// Created by user on 24.06.2022.
//

#include <iostream>
#include "Board.h"

Board::Board(const int & width, const int &height) {
    if ((width>8)&&(width<35))
        this->width=width;
    if ((height>8)&&(height<35))
        this->height=height;
    area.resize(width);
    for (int i=0;i<width;i++){
        area[i].resize(height);
    }
    //nadanie wartosci poczatkowych polom ['s' - waz, 'f'- jedzenie 'e'- puste]
}



int Board::getWidth() const {
    return this->width;
}

int Board::getHeight() const {
    return this->height;
}
