#include <cstdlib>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdio>
#include <synchapi.h>
#include "GameManager.h"
#include <cstdio>

std::ostream &operator<<(std::ostream &out, const Point &point);

//GameManager::GameManager(const int & width, const int & height, const Fruit& fruit) : board(width,height),snake(rand()%(board.getWidth()-1),rand()%(board.getHeight()-1)),fruit(fruit)
//{}

GameManager::GameManager (const int &width, const int &height, const std::vector<Fruit> &fruits) : board(width, height), snake(board.getWidth()/2,board.getHeight()/2)
{
//    snake(rand() % (board.getWidth() - 1), rand() % (board.getHeight() - 1);
    this->fruits=fruits;
}

void GameManager::print() {
    system ("CLS");
    //gora
    for (int i=0;i<=board.getWidth()+2;i++){
        std::cout<<"X";
    }

    for (int i=0;i<=board.getHeight();i++){
        //lewy bok
        std::cout<<std::endl<<"X";
        for (int k=0;k<=board.getWidth();k++)
        {
            if ((k == snake.getHeadPosition().getY()) && (i == snake.getHeadPosition().getX())) {
                std::cout << "O";
            }

            else if ((k == fruit.getPosition().getY()) && (i == fruit.getPosition().getX())) {
                std::cout << fruit.getImage();
            }
            else {
                bool printEmpty=false;
                for (int j=0;j<snake.getLength();j++){
                    if((i == snake.getBodyPosition(j).getX()) && (k == snake.getBodyPosition(j).getY())){
                        std::cout<<":";
                        printEmpty=true;
                    }
                }
                if (printEmpty==0)
                    std::cout<<" ";
                if (k == board.getWidth())
                    std::cout << "X";
            }
        }
    }
    std::cout<<std::endl;
    for (int i=0;i<=board.getWidth()+2;i++){
        std::cout<<"X";
    }

    std::cout<<"\n\nScore: "<<score<<std::endl;
    std::cout<<"\nLength: "<<snake.getLength()<<std::endl;
    std::cout << "\nSize: " << snake.getLength() << std::endl;
    std::cout << "\nPOINTS: ";
    std::cout << "\n\nHead Position: " << snake.getHeadPosition() << std::endl;
}

std::ostream& operator << (std::ostream&out, const Point& point);
void GameManager::info() {
    std::cout<<"Glowa snake: "<<snake.getHeadPosition()<<"\nOwoc: "<<fruit.getPosition()<<std::endl;
}

void GameManager::input() {
    if (_kbhit()){
        switch (_getch()){
            case 'a':
            {
                snakeDirection=LEFT;
            }
                break;
            case 'd':
            {
                snakeDirection = RIGHT;
            }
                break;
            case 'w':
            {
                snakeDirection = UP;
            }
                break;
            case 's':
            {
                snakeDirection = DOWN;
            }
                break;
            case 'x':
            {
                gameOver= true;
            }
        }
    }
}

Snake& GameManager::getSnake()  {
    return snake;
}

void GameManager::gameLogic() {
    Point previousPoint=snake.getHeadPosition();

    switch (snakeDirection)
    {
        case LEFT:
            snake.moveLeft();
            break;
        case RIGHT:
            snake.moveRight();
            break;
        case UP:
            snake.moveUp();
            break;
        case DOWN:
            snake.moveDown();
            break;
    }
    Point previousPointSec=snake.getBodyPosition(0);
    snake.getBodyPosition(0) = previousPoint;


    for (int i=1;i<snake.getLength();i++){
        previousPoint=snake.getBodyPosition(i);
        snake.getBodyPosition(i)=previousPointSec;
        previousPointSec=previousPoint;
    }

    if(((snake.getHeadPosition().getX())>(board.getWidth()))||(snake.getHeadPosition().getX()<0)||(snake.getHeadPosition().getY()>((board.getHeight())))||(snake.getHeadPosition().getY()<0)) {
        gameOver=true;
    }

    for (int i=1;i<snake.getLength();i++){
        if (snake.getBodyPosition(i)==snake.getHeadPosition()){
            std::cout<<i<<". " <<snake.getBodyPosition(i)<<" = "<<snake.getHeadPosition();
            gameOver=true;
        }
    }

    if ((snake.getHeadPosition().getX()==fruit.getPosition().getX())&&(snake.getHeadPosition().getY()==fruit.getPosition().getY())){
        score+=fruit.getScore();
        fruit.setImage(this->fruits[rand()%fruits.size()].getImage());
        fruit.setPosition(rand()%(board.getWidth()-1),rand()%(board.getHeight()-1));
        snake.grow(1);
        if (snake.getLength()>0)
            snake.getBodyPosition(snake.getLength()).setPoint(snake.getBodyPosition(snake.getLength()-1));

        else{
            snake.getBodyPosition(snake.getLength()).setPoint(snake.getBodyPosition(0));
        }
    }
}

void GameManager::game() {
    int miliseconds=600;
    while(!gameOver){
        print();
        input();
        gameLogic();
        Sleep(miliseconds);
        if (score % 3 == 2){
            miliseconds*=0.9;
        }
        //system("CLS");
    }
    Sleep(10000);
    system("CLS");
    print();
    std::cout<<"GAME OVER"<<std::endl;
    std::cout<<"\nYour score: "<<score<<std::endl;
}


int GameManager::getScore() const {
    return score;
}
