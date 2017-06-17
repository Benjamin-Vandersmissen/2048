//
// Created by Benjamin on 13/06/2017.
//

#ifndef INC_2048_BOARD_H
#define INC_2048_BOARD_H

#include "Block.h"
#include <iostream>
#include <vector>

class Board {
private:
    unsigned int w = 4;
    unsigned int h = 4;

    std::vector<std::vector<Block*>> board;
public:
    friend std::ostream& operator<<(std::ostream& stream, Board& b);

    Board(unsigned int w, unsigned h);

    //Moves all blocks upwards
    void moveUp();

    //Moves the block at (x,y) upwards
    void moveUp(unsigned int x, unsigned int y);

    //Moves all blocks downwards
    void moveDown();

    //Moves the block at (x,y) downwards
    void moveDown(unsigned int x, unsigned int y);

    //Moves all blocks leftwards
    void moveLeft();

    //Moves the block at (x,y) leftwards
    void moveLeft(unsigned int x, unsigned int y);

    //Moves all blocks rightwards
    void moveRight();

    //Moves the block at (x,y) rightwards
    void moveRight(unsigned int x, unsigned int y);

    //if all squares are occupied, the game is over
    bool validGameState();

    void addNewBlock();

    Block* operator()(unsigned int w, unsigned int h);

};

std::ostream& operator<<(std::ostream& stream, Board& board);

#endif //INC_2048_BOARD_H
