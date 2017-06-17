//
// Created by Benjamin on 13/06/2017.
//

#include "Board.h"



Board::Board(unsigned int w, unsigned h) : w(w), h(h){
    for(unsigned int a = 0; a < w; a++){
        std::vector<Block*> column = {};
        for(unsigned int b = 0; b < h; b++){
            column.push_back(NULL);
        }
        board.push_back(column);
    }
}

void Board::moveUp() {
    for(unsigned int a = 0; a < w ; a++){
        for(unsigned int b = 0; b < h; b++){
            moveUp(a,b);
        }
    }
}

void Board::moveUp(unsigned int x, unsigned int y) {
    if (board[x][y] == nullptr)
        return;
    bool collision = false; //if collision is false, the block will end on one of the borders
    Block* block = board[x][y];
    board[x][y] = nullptr;
    for(unsigned int b = y; b > 0; b--){
        if (board[x][b-1] == nullptr)
            continue;
        else{
            collision = true;
            if (board[x][b-1]->merge(block)){
                delete block;
            }
            else{
                board[x][b] = block;
            }
            break;
        }
    }
    if (!collision){
        board[x][0] = block;
    }
}

std::ostream &operator<<(std::ostream &stream, Board &board) {
    for(unsigned int b = 0; b < board.h; b++){
        for(unsigned int a = 0; a < board.w; a++){
            Block* block = board.board[a][b];
            if (block == nullptr)
                stream << 0 << ' ';
            else
                stream << block->getValue() << ' ';
        }
        stream << std::endl;
    }
    return stream;
}

void Board::moveDown() {
    for(unsigned int a = 0; a < w ; a++){
        for(unsigned int b = h; b > 0; b--){
            moveDown(a,b-1);
        }
    }
}

void Board::moveDown(unsigned int x, unsigned int y) {
    if (board[x][y] == nullptr)
        return;
    bool collision = false; //if collision is false, the block will end on one of the borders
    Block* block = board[x][y];
    board[x][y] = nullptr;
    for(unsigned int b = y; b < h-1; b++){
        if (board[x][b+1] == nullptr)
            continue;
        else{
            collision = true;
            if (board[x][b+1]->merge(block)){
                delete block;
            }
            else{
                board[x][b] = block;
            }
            break;
        }
    }
    if (!collision){
        board[x][h-1] = block;
    }
}

void Board::moveLeft() {
    for(unsigned int a = 0; a < w ; a++){
        for(unsigned int b = 0; b < h; b++){
            moveLeft(a,b);
        }
    }
}

void Board::moveLeft(unsigned int x, unsigned int y) {
    if (board[x][y] == nullptr)
        return;
    bool collision = false; //if collision is false, the block will end on one of the borders
    Block* block = board[x][y];
    board[x][y] = nullptr;
    for(unsigned int a = x; a > 0; a--){
        if (board[a-1][y] == nullptr)
            continue;
        else{
            collision = true;
            if (board[a-1][y]->merge(block)){
                delete block;
            }
            else{
                board[a][y] = block;
            }
            break;
        }
    }
    if (!collision){
        board[0][y] = block;
    }
}

void Board::moveRight() {
    for(unsigned int a = w; a > 0 ; a--){
        for(unsigned int b = 0; b < h; b++){
            moveRight(a-1,b);
        }
    }
}

void Board::moveRight(unsigned int x, unsigned int y) {
    if (board[x][y] == nullptr)
        return;
    bool collision = false; //if collision is false, the block will end on one of the borders
    Block* block = board[x][y];
    board[x][y] = nullptr;
    for(unsigned int a = x; a < w-1; a++){
        if (board[a+1][y] == nullptr)
            continue;
        else{
            collision = true;
            if (board[a+1][y]->merge(block)){
                delete block;
            }
            else{
                board[a][y] = block;
            }
            break;
        }
    }
    if (!collision){
        board[w-1][y] = block;
    }
}

bool Board::validGameState() {
    for(int a = 0; a  < w; a++){
        for(int b = 0; b < h; b++){
            if (board[a][b] == NULL)
                return true;
        }
    }
    return false;
}

void Board::addNewBlock() {
    if (validGameState()){
        std::vector<std::pair<unsigned int, unsigned int>> emptySquares = {};
        for(int a = 0; a < w; a++){
            for(int b = 0; b < h; b++){
                if (board[a][b] == NULL)
                    emptySquares.push_back(std::make_pair(a,b));
            }
        }
        std::pair<unsigned int, unsigned int > randCoord = emptySquares[rand()%emptySquares.size()];
        board[randCoord.first][randCoord.second] = new Block;
    }
}

Block *Board::operator()(unsigned int w, unsigned int h) {
    if (w < this->w && h < this->h){
        return this->board[w][h];
    }
    else{
        return nullptr;
    }
}
