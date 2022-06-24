#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.h"
#include "Snake.h"
#include "Fruit.h"
#include "Board.h"
#include "GameManager.h"

int main() {
    Fruit pear(5, 4, 3, 'b');
    Fruit apple(1, 2, 6, 'd');
    Fruit banana(1,2,2,')');
    Fruit pineapple(3,4,1,'Q');
    std::vector<Fruit>fruits;
    fruits.push_back(apple);
    fruits.push_back(banana);
    fruits.push_back(pear);
    fruits.push_back(pineapple);
    srand(time(0));
    GameManager G1(15,15,fruits);
    G1.game();

}
